savedcmd_drivers/gpu/drm/amd/amdxcp/amdxcp.ko := ld -r -EL  -maarch64elf -z noexecstack --no-warn-rwx-segments --build-id=sha1  -T scripts/module.lds -o drivers/gpu/drm/amd/amdxcp/amdxcp.ko drivers/gpu/drm/amd/amdxcp/amdxcp.o drivers/gpu/drm/amd/amdxcp/amdxcp.mod.o;  true