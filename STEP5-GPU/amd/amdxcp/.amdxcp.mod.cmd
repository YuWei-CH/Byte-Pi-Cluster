savedcmd_drivers/gpu/drm/amd/amdxcp/amdxcp.mod := printf '%s\n'   amdgpu_xcp_drv.o | awk '!x[$$0]++ { print("drivers/gpu/drm/amd/amdxcp/"$$0) }' > drivers/gpu/drm/amd/amdxcp/amdxcp.mod
