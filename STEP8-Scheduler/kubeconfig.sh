#!/bin/bash

# Loop to create 30 users and corresponding namespaces, roles, and kubeconfig files
for i in {1..30}; do
  USERNAME="user$i"
  NAMESPACE="workspace-$USERNAME"

  # Create namespace
  kubectl create namespace $NAMESPACE

  # Create role with full permissions within the namespace
  cat <<EOF | kubectl apply -n $NAMESPACE -f -
apiVersion: rbac.authorization.k8s.io/v1
kind: Role
metadata:
  name: ${USERNAME}-role
rules:
- apiGroups: ["*"]
  resources: ["*"]
  verbs: ["get", "list", "watch", "create", "update", "patch", "delete"]
EOF

  # Create service account for the user
  kubectl create serviceaccount $USERNAME -n $NAMESPACE

  # Bind role to service account
  kubectl create rolebinding ${USERNAME}-binding \
    --role=${USERNAME}-role \
    --serviceaccount=$NAMESPACE:$USERNAME \
    -n $NAMESPACE

  # Generate kubeconfig file for the user
  SECRET_NAME=$(kubectl get serviceaccount $USERNAME -n $NAMESPACE -o jsonpath='{.secrets[0].name}')
  TOKEN=$(kubectl get secret $SECRET_NAME -n $NAMESPACE -o jsonpath='{.data.token}' | base64 --decode)
  CLUSTER_NAME=$(kubectl config view -o jsonpath='{.clusters[0].name}')
  SERVER=$(kubectl config view -o jsonpath='{.clusters[0].cluster.server}')
  CA=$(kubectl get secret $SECRET_NAME -n $NAMESPACE -o jsonpath='{.data.ca\.crt}' | base64 --decode)

  # Create kubeconfig file for the user
  KUBECONFIG_FILE="kubeconfig-$USERNAME.yaml"
  cat <<EOF > $KUBECONFIG_FILE
apiVersion: v1
kind: Config
clusters:
- name: $CLUSTER_NAME
  cluster:
    certificate-authority-data: $(echo $CA | base64)
    server: $SERVER
contexts:
- name: $USERNAME-context
  context:
    cluster: $CLUSTER_NAME
    namespace: $NAMESPACE
    user: $USERNAME
current-context: $USERNAME-context
users:
- name: $USERNAME
  user:
    token: $TOKEN
EOF

echo "Kubeconfig for $USERNAME created: $KUBECONFIG_FILE"
done