#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/export-internal.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

#ifdef CONFIG_UNWINDER_ORC
#include <asm/orc_header.h>
ORC_HEADER;
#endif

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

MODULE_INFO(intree, "Y");

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

KSYMTAB_FUNC(amdgpu_xcp_drm_dev_alloc, "", "");
KSYMTAB_FUNC(amdgpu_xcp_drv_release, "", "");

SYMBOL_CRC(amdgpu_xcp_drm_dev_alloc, 0x4b93565c, "");
SYMBOL_CRC(amdgpu_xcp_drv_release, 0x0ea5d74b, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x6eace5a4, "devres_release_group" },
	{ 0xf0fdf6cb, "__stack_chk_fail" },
	{ 0xbc5c901c, "platform_device_unregister" },
	{ 0x56f707c7, "devres_open_group" },
	{ 0x617a3b1f, "__devm_drm_dev_alloc" },
	{ 0xdcb764ad, "memset" },
	{ 0x6b9e2c1b, "platform_device_register_full" },
	{ 0xe478ef45, "module_layout" },
};

MODULE_INFO(depends, "drm");


MODULE_INFO(srcversion, "E73B18950BF6F397C573CB8");
