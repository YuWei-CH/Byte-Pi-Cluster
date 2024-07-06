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
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

MODULE_INFO(intree, "Y");

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif



static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x922f45a6, "__bitmap_clear" },
	{ 0xa4f39c88, "drm_show_fdinfo" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0xfc03d97a, "page_is_ram" },
	{ 0xc9009011, "drm_atomic_helper_commit_hw_done" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x1000e51, "schedule" },
	{ 0x1ab7b326, "drm_gem_object_release" },
	{ 0x2f2c95c4, "flush_work" },
	{ 0xc66957ea, "drm_connector_attach_max_bpc_property" },
	{ 0x1b380411, "request_firmware" },
	{ 0xe49f1e2a, "__pm_runtime_resume" },
	{ 0x33f0768c, "cpufreq_quick_get_max" },
	{ 0xeaff514c, "pci_unregister_driver" },
	{ 0x8d701329, "drm_dp_clock_recovery_ok" },
	{ 0x3de95204, "pm_runtime_allow" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xf1421d13, "drm_mode_sort" },
	{ 0xb1798aae, "drm_crtc_vblank_get" },
	{ 0x6abe2fa1, "drm_mode_probed_add" },
	{ 0x2c38f027, "dma_resv_replace_fences" },
	{ 0xc1d8cfaf, "__fdget" },
	{ 0x12a4e128, "__arch_copy_from_user" },
	{ 0x273b003e, "drm_atomic_helper_crtc_duplicate_state" },
	{ 0x8ac0e747, "kobj_sysfs_ops" },
	{ 0x5a9f1d63, "memmove" },
	{ 0x3dcb72a6, "drm_dp_atomic_find_time_slots" },
	{ 0xfe12bcb9, "drm_dsc_compute_rc_parameters" },
	{  0x66912, "ttm_bo_vm_close" },
	{ 0xae277372, "__drm_crtc_commit_free" },
	{ 0x55f443f1, "drm_syncobj_get_handle" },
	{ 0x87a0859, "pm_genpd_add_device" },
	{ 0xdb760f52, "__kfifo_free" },
	{ 0xc7d04fc5, "drm_vma_node_allow" },
	{ 0xdf63aab2, "drm_sched_stop" },
	{ 0x218f96ce, "drm_fbdev_generic_setup" },
	{ 0xc5c99a79, "drm_dp_get_adjust_request_voltage" },
	{ 0xa7a9d2b8, "__drm_atomic_helper_private_obj_duplicate_state" },
	{ 0x34fbe4b1, "drm_crtc_arm_vblank_event" },
	{ 0xd469bccc, "__tracepoint_mmap_lock_released" },
	{ 0xa084749a, "__bitmap_or" },
	{ 0x87a8031e, "drm_sched_entity_error" },
	{ 0xe8a034df, "drm_dev_exit" },
	{ 0x22c9ffd6, "pci_clear_master" },
	{ 0xc958e309, "kmem_cache_free" },
	{ 0x319950ac, "ttm_resource_init" },
	{ 0x5555193d, "drm_connector_list_iter_next" },
	{ 0x5a7f5a7b, "ttm_bo_vm_fault_reserved" },
	{ 0x97d55281, "drm_plane_create_blend_mode_property" },
	{ 0x2b363464, "debugfs_create_x32" },
	{ 0x91429efb, "ww_mutex_lock_interruptible" },
	{ 0x4da181f5, "hmm_range_fault" },
	{ 0x1e6d26a8, "strstr" },
	{ 0xdebe3cba, "drm_atomic_helper_dirtyfb" },
	{ 0x20d2fa80, "drm_mode_config_helper_resume" },
	{ 0xd0dfde80, "drm_gem_private_object_init" },
	{ 0xb43f9365, "ktime_get" },
	{ 0xedcf81ce, "drm_dp_channel_eq_ok" },
	{ 0x9b2a6fe6, "ttm_range_man_init_nocheck" },
	{ 0x80262e24, "ttm_resource_manager_evict_all" },
	{ 0xfdc7f129, "debugfs_lookup" },
	{ 0x9304802e, "task_active_pid_ns" },
	{ 0x16cc0520, "pci_dev_put" },
	{ 0xf70e4a4d, "preempt_schedule_notrace" },
	{ 0x3082b54c, "drm_atomic_state_alloc" },
	{ 0xdd3c6afa, "drm_mode_is_420_also" },
	{ 0xeee59892, "pci_read_config_word" },
	{ 0x69353664, "__drm_debug" },
	{ 0x57bc19d2, "down_write" },
	{ 0xe01a9514, "__mmap_lock_do_trace_acquire_returned" },
	{ 0xa58f46fc, "pci_reset_function" },
	{ 0xd17b1672, "debugfs_create_bool" },
	{ 0x73011db0, "drm_dp_bw_code_to_link_rate" },
	{ 0x7a2fc866, "drm_helper_force_disable_all" },
	{ 0xd3abe05, "drm_open" },
	{ 0xc7525e70, "drm_add_edid_modes" },
	{ 0xbe398b96, "mmu_interval_notifier_remove" },
	{ 0xd6e1fd13, "trace_event_raw_init" },
	{ 0x5b7fa55f, "drm_send_event_locked" },
	{ 0xf390f6f1, "__bitmap_andnot" },
	{ 0x19d4aec8, "drm_dp_mst_put_port_malloc" },
	{ 0x60a13e90, "rcu_barrier" },
	{ 0x74dd9e0b, "dma_fence_wait_any_timeout" },
	{ 0xf23fcb99, "__kfifo_in" },
	{ 0x349cba85, "strchr" },
	{ 0x7dd78390, "drm_atomic_get_mst_payload_state" },
	{ 0x9f44c898, "drm_buddy_init" },
	{ 0xe783e261, "sysfs_emit" },
	{ 0x60bbb124, "dma_fence_signal_locked" },
	{ 0x4885776d, "drm_dp_aux_unregister" },
	{ 0x1c0fb8ac, "trace_event_printf" },
	{ 0x17dc632e, "mfd_remove_devices" },
	{ 0x4e8f828, "mtree_load" },
	{ 0x92d3c7c4, "drm_atomic_helper_page_flip" },
	{ 0x7b180abd, "drm_connector_unregister" },
	{ 0xef733a06, "pci_device_is_present" },
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0x7b4aae89, "debugfs_create_blob" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xe00e3274, "dma_buf_dynamic_attach" },
	{ 0x8426f463, "pci_get_domain_bus_and_slot" },
	{ 0xd0c05159, "emergency_restart" },
	{ 0xffae8e8b, "nsecs_to_jiffies" },
	{ 0x3cf307c1, "drm_sched_fault" },
	{ 0x17375c7b, "drm_dp_mst_update_slots" },
	{ 0x4575a0ca, "drm_mode_set_crtcinfo" },
	{ 0x6edfd56d, "dma_map_resource" },
	{ 0x4c6217be, "drm_fb_helper_set_suspend_unlocked" },
	{ 0x5a921311, "strncmp" },
	{ 0xb50213ac, "drm_modeset_lock_all_ctx" },
	{ 0x5a290250, "hdmi_drm_infoframe_pack_only" },
	{ 0x8196839b, "drm_connector_set_path_property" },
	{ 0x139f2189, "__kfifo_alloc" },
	{ 0x64031c83, "_dev_warn" },
	{ 0x63deb0d9, "drm_connector_list_iter_end" },
	{ 0x3dad9978, "cancel_delayed_work" },
	{ 0xd6ee688f, "vmalloc" },
	{ 0x53b954a2, "up_read" },
	{ 0x96d101d4, "drm_atomic_helper_shutdown" },
	{ 0x87827973, "sg_alloc_table_from_pages_segment" },
	{ 0xa843805a, "get_unused_fd_flags" },
	{ 0x46179c9a, "dma_resv_iter_next_unlocked" },
	{ 0xa990321, "drm_atomic_helper_check_modeset" },
	{ 0xacf26a4c, "drm_helper_hpd_irq_event" },
	{ 0xf7acb66, "drm_mm_print" },
	{ 0xdc3fcbc9, "__sw_hweight8" },
	{ 0xc3bc72ad, "trace_print_array_seq" },
	{ 0x52735c61, "__mmap_lock_do_trace_start_locking" },
	{ 0xa916b694, "strnlen" },
	{ 0x2835cebb, "drm_dp_mst_topology_mgr_suspend" },
	{ 0x9af5263d, "pci_msix_vec_count" },
	{ 0xc9f84595, "drm_dp_mst_atomic_enable_dsc" },
	{ 0x588dd80e, "pm_runtime_forbid" },
	{ 0x9d645987, "pci_store_saved_state" },
	{ 0x1b0bc29b, "perf_pmu_register" },
	{ 0xd3e94e0d, "kobject_create_and_add" },
	{ 0x3b0e5e9c, "__drm_puts_coredump" },
	{ 0x31850a1e, "pcie_get_speed_cap" },
	{ 0x82ee90dc, "timer_delete_sync" },
	{ 0x4b93565c, "amdgpu_xcp_drm_dev_alloc" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x2f6c30d0, "pci_load_saved_state" },
	{ 0xc2481d60, "drm_crtc_vblank_off" },
	{ 0x787b7df7, "drm_atomic_helper_suspend" },
	{ 0xc2d45fd1, "pcie_capability_write_word" },
	{ 0xb6fde909, "close_fd" },
	{ 0x75265358, "drm_sched_suspend_timeout" },
	{ 0xeb6eb87, "add_taint" },
	{ 0xf53ed454, "ttm_bo_wait_ctx" },
	{ 0xfb814f38, "simple_attr_open" },
	{ 0x7f24de73, "jiffies_to_usecs" },
	{ 0x6cfd5e9, "debugfs_create_dir" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xf05f800e, "pci_alloc_irq_vectors" },
	{ 0xa7d5f92e, "ida_destroy" },
	{ 0xf5bdfeca, "param_ops_int" },
	{ 0x7e09a3d3, "vga_client_register" },
	{ 0x9a96b17d, "ttm_resource_manager_usage" },
	{ 0xee3d2be4, "drm_atomic_helper_check_planes" },
	{ 0x8ab2521b, "dma_resv_wait_timeout" },
	{ 0xb5cdac8c, "ttm_resource_manager_init" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xc091c09d, "drm_syncobj_create" },
	{ 0x44ba1be5, "drm_dp_mst_connector_late_register" },
	{ 0x4176a705, "drm_gem_dmabuf_vmap" },
	{ 0x5c674bce, "seq_write" },
	{ 0x8f581c0e, "__srcu_read_lock" },
	{ 0x645d04eb, "ttm_bo_vm_access" },
	{ 0xb81479ec, "__task_pid_nr_ns" },
	{ 0x84be5e76, "drm_sched_job_add_resv_dependencies" },
	{ 0x6128b5fc, "__printk_ratelimit" },
	{ 0x325153c3, "pid_task" },
	{ 0x8d522714, "__rcu_read_lock" },
	{ 0x81e6b37f, "dmi_get_system_info" },
	{ 0x14605535, "dma_fence_context_alloc" },
	{ 0x9ea73724, "pci_set_master" },
	{ 0x96f3b9ec, "ttm_resource_free" },
	{ 0xd3ba0a56, "drm_sched_fini" },
	{ 0xec32de24, "to_drm_sched_fence" },
	{ 0x3fe69c8c, "ttm_bo_init_reserved" },
	{ 0xbcf80174, "pcie_capability_clear_and_set_word_locked" },
	{ 0x48a510f, "drm_suballoc_manager_init" },
	{ 0xe2964344, "__wake_up" },
	{ 0xf236d20c, "drm_sched_entity_modify_sched" },
	{ 0x2104b303, "drm_connector_attach_encoder" },
	{ 0xcdf1dad, "dma_set_mask" },
	{ 0x4302d0eb, "free_pages" },
	{ 0x574ba5, "dev_coredumpm" },
	{ 0x81beb2a2, "param_ops_hexint" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0x8a01c137, "i2c_new_client_device" },
	{ 0x61bf4969, "__register_chrdev" },
	{ 0x9068aa82, "drm_dp_mst_topology_state_funcs" },
	{ 0x5267f029, "irq_set_chip_and_handler_name" },
	{ 0x1cc895de, "drm_exec_lock_obj" },
	{ 0xca9beaa4, "__xa_store" },
	{ 0xb5b54b34, "_raw_spin_unlock" },
	{ 0x8477cdaf, "compat_ptr_ioctl" },
	{ 0x7b5ee872, "drm_set_preferred_mode" },
	{ 0x7b4da6ff, "__init_rwsem" },
	{ 0x88a25e7e, "drm_get_edid" },
	{ 0x338e80e9, "hrtimer_try_to_cancel" },
	{ 0xfb139180, "drm_crtc_enable_color_mgmt" },
	{ 0x8524f875, "drm_dp_dpcd_write" },
	{ 0x62f7e207, "down_read_killable" },
	{ 0x692c950, "drm_modeset_acquire_init" },
	{ 0x20d1d6e1, "bpf_trace_run6" },
	{ 0x88f28935, "pci_save_state" },
	{ 0x7b2e2166, "drm_vma_node_revoke" },
	{ 0xbcc03ecb, "drm_plane_get_damage_clips_count" },
	{ 0x4f61cab3, "get_pid_task" },
	{ 0x48f57091, "kobject_add" },
	{ 0x599fb41c, "kvmalloc_node" },
	{ 0x22d53779, "drm_buddy_free_list" },
	{ 0xf4c3bbce, "pci_wait_for_pending_transaction" },
	{ 0xe942363a, "bpf_trace_run2" },
	{ 0xcf5ce693, "backlight_device_unregister" },
	{ 0xf480cb77, "drm_sched_entity_set_priority" },
	{ 0x2491ad29, "drm_plane_get_damage_clips" },
	{ 0xdf521442, "_find_next_zero_bit" },
	{ 0xf8ae37dd, "drm_sched_pick_best" },
	{ 0x31368b5e, "drm_modeset_acquire_fini" },
	{ 0xf7596497, "drm_connector_atomic_hdr_metadata_equal" },
	{ 0x167c5967, "print_hex_dump" },
	{ 0x120b336a, "__rb_insert_augmented" },
	{ 0xf9a482f9, "msleep" },
	{ 0xb17b5906, "bpf_trace_run4" },
	{ 0x2d30c16d, "drm_sched_job_cleanup" },
	{ 0xb11ac7a7, "__drm_err" },
	{ 0xa7e6f955, "ttm_tt_fini" },
	{ 0xfef216eb, "_raw_spin_trylock" },
	{ 0x4829a47e, "memcpy" },
	{ 0x5e515be6, "ktime_get_ts64" },
	{ 0xe6b63ad0, "drm_dp_start_crc" },
	{ 0x2fca9c50, "ttm_pool_fini" },
	{ 0xff748b76, "drm_buddy_alloc_blocks" },
	{ 0x43fda0ef, "drm_crtc_helper_set_mode" },
	{ 0x42338dcd, "__drm_atomic_helper_plane_reset" },
	{ 0xcbcdf3e0, "drm_dp_dpcd_read" },
	{ 0x44c10a52, "kvfree_call_rcu" },
	{ 0xb1518e15, "cancel_work" },
	{ 0xc6d09aa9, "release_firmware" },
	{ 0x8df92f66, "memchr_inv" },
	{ 0x4a35d30d, "drm_mode_set_name" },
	{ 0x2688ec10, "bitmap_zalloc" },
	{ 0xfa150882, "drm_buddy_fini" },
	{ 0x8cc68fe1, "seq_lseek" },
	{ 0x226bd32a, "drm_modeset_unlock_all" },
	{ 0xe1e03b27, "drm_dp_mst_atomic_wait_for_dependencies" },
	{ 0x15a55c49, "dma_buf_unmap_attachment" },
	{ 0x1154c794, "debugfs_remove" },
	{ 0x3f4547a7, "put_unused_fd" },
	{ 0xb39ca41a, "dma_resv_iter_first" },
	{ 0x53a1e8d9, "_find_next_bit" },
	{ 0xf1ea969c, "ttm_bo_kmap" },
	{ 0xb7c0f443, "sort" },
	{ 0x3e481176, "generic_handle_domain_irq" },
	{ 0x28aa6a67, "call_rcu" },
	{ 0x58c9dc61, "kthread_use_mm" },
	{ 0x71928c13, "kobject_del" },
	{ 0x3cf7babe, "drm_dp_mst_topology_mgr_set_mst" },
	{ 0xc4f0da12, "ktime_get_with_offset" },
	{ 0xb5919972, "dma_buf_move_notify" },
	{ 0x2c320b8e, "dma_resv_reserve_fences" },
	{ 0x8ce6b608, "ttm_bo_set_bulk_move" },
	{ 0x1f1eee9, "debugfs_attr_write_signed" },
	{ 0x20978fb9, "idr_find" },
	{ 0xf0fdf6cb, "__stack_chk_fail" },
	{ 0x27ba42d3, "drm_gem_prime_export" },
	{ 0x51b8a36d, "devm_device_add_group" },
	{ 0x6c204336, "dma_buf_put" },
	{ 0xa38602cd, "drain_workqueue" },
	{ 0xdf660cb3, "mmu_notifier_put" },
	{ 0xd9491c14, "xa_destroy" },
	{ 0xe8d4d0c8, "single_open" },
	{ 0xe0e00411, "pcie_get_readrq" },
	{ 0x2469810f, "__rcu_read_unlock" },
	{ 0xacfb29c3, "dma_resv_iter_first_unlocked" },
	{ 0x9e7d6bd0, "__udelay" },
	{ 0xffb28d40, "dma_resv_add_fence" },
	{ 0xfb9fde1a, "seq_printf" },
	{ 0x7b37d4a7, "_find_first_zero_bit" },
	{ 0xaf8ff722, "__drm_atomic_helper_connector_destroy_state" },
	{ 0x7665a95b, "idr_remove" },
	{ 0xfe5cf9d2, "drm_dp_atomic_release_time_slots" },
	{ 0xbe895cdb, "drm_atomic_add_affected_connectors" },
	{ 0x6dffcdd3, "dma_resv_get_fences" },
	{ 0xf34ca194, "drm_dp_mst_detect_port" },
	{ 0xb65811f9, "pci_restore_state" },
	{ 0x9d6db53, "drm_helper_connector_dpms" },
	{ 0x9ce050be, "drm_mode_copy" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xc98130f8, "seq_hex_dump" },
	{ 0x40863ba1, "ioremap_prot" },
	{ 0x4b7e71e5, "pci_unmap_rom" },
	{ 0xb3a7a779, "__alloc_pages" },
	{ 0xf0517d7a, "drm_mm_init" },
	{ 0x52e7a496, "sync_file_create" },
	{ 0x513072fe, "__drm_puts_seq_file" },
	{ 0x11089ac7, "_ctype" },
	{ 0x45fa3f11, "synchronize_srcu" },
	{ 0x88ab6fe3, "kgdb_active" },
	{ 0x16b2056d, "drm_plane_create_rotation_property" },
	{ 0x7302b1e5, "iommu_iova_to_phys" },
	{ 0x1a411479, "drm_syncobj_free" },
	{ 0x5fcf71b0, "kset_register" },
	{ 0x4ce04710, "drm_add_modes_noedid" },
	{ 0xf9a1a295, "__trace_trigger_soft_disabled" },
	{ 0xd955afa6, "hrtimer_start_range_ns" },
	{ 0x16009ed3, "ttm_bo_vm_dummy_page" },
	{ 0x7b0c885d, "drm_modeset_lock_all" },
	{ 0x8be39fa3, "dma_unmap_page_attrs" },
	{ 0x371e755d, "dma_resv_iter_next" },
	{ 0x33cce269, "drm_atomic_private_obj_init" },
	{ 0x6bc3fbc0, "__unregister_chrdev" },
	{ 0x14316a8b, "debugfs_create_file_unsafe" },
	{ 0xa75c0799, "drm_atomic_normalize_zpos" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0xe311fde0, "drm_gem_dmabuf_mmap" },
	{ 0x668b19a1, "down_read" },
	{ 0x7682ba4e, "__copy_overflow" },
	{ 0x57698a50, "drm_mm_takedown" },
	{ 0x70df87eb, "drm_crtc_helper_set_config" },
	{ 0xad73041f, "autoremove_wake_function" },
	{ 0x941d368a, "drm_gem_handle_create" },
	{ 0x48879f20, "hrtimer_init" },
	{ 0xfe0dfb85, "__mmdrop" },
	{ 0x13441077, "pci_enable_atomic_ops_to_root" },
	{ 0x9c78d836, "drm_atomic_helper_set_config" },
	{ 0xd48dab33, "ww_mutex_unlock" },
	{ 0x64d11af1, "dma_fence_wait_timeout" },
	{ 0x9fb5d50f, "drm_dp_read_dpcd_caps" },
	{ 0x2a3508ab, "drm_dev_enter" },
	{ 0x6626afca, "down" },
	{ 0xa38c1436, "cpu_bit_bitmap" },
	{ 0xc310b981, "strnstr" },
	{ 0x85df9b6c, "strsep" },
	{ 0xc57c48a3, "idr_get_next" },
	{ 0xbc33ae4f, "kmem_cache_create" },
	{ 0x27995494, "pm_runtime_autosuspend_expiration" },
	{ 0x7c173634, "__bitmap_complement" },
	{ 0xfacddf2e, "ttm_bo_pin" },
	{ 0x25111224, "__drm_atomic_helper_crtc_destroy_state" },
	{ 0xd9b4753, "drm_mode_equal" },
	{ 0xdcb764ad, "memset" },
	{ 0x8810754a, "_find_first_bit" },
	{ 0x49b453f0, "component_del" },
	{ 0x9b285573, "drm_match_cea_mode" },
	{ 0x2fbef297, "drm_atomic_helper_update_legacy_modeset_state" },
	{ 0xf02aa937, "wait_for_completion_interruptible_timeout" },
	{ 0x46ed7299, "hwmon_device_register_with_groups" },
	{ 0xd642f3f6, "video_firmware_drivers_only" },
	{ 0x60617e9, "drm_sched_init" },
	{ 0x812d8333, "fd_install" },
	{ 0xc54b111f, "drm_object_property_set_value" },
	{ 0x37a0cba, "kfree" },
	{ 0xc5c2f57b, "anon_inode_getfd" },
	{ 0x6df0734a, "drm_fb_helper_lastclose" },
	{ 0xbf363bf8, "iommu_get_domain_for_dev" },
	{ 0x7dc4ee5d, "sysfs_create_bin_file" },
	{ 0x98555a05, "dma_fence_chain_walk" },
	{ 0x6c43c205, "drm_atomic_commit" },
	{ 0xeca28f3b, "drm_atomic_helper_plane_reset" },
	{ 0xbb9ed3bf, "mutex_trylock" },
	{ 0x1cb1424b, "drm_atomic_private_obj_fini" },
	{ 0x4f26c5de, "fget" },
	{ 0x224c5b24, "drm_kms_helper_connector_hotplug_event" },
	{ 0x593bdb03, "pcie_capability_read_dword" },
	{ 0x15e57dcc, "perf_pmu_unregister" },
	{ 0x9dbfc2c3, "__put_task_struct" },
	{ 0xbe14b6a5, "drm_crtc_send_vblank_event" },
	{ 0xe4862761, "drm_atomic_helper_connector_duplicate_state" },
	{ 0xdc0e4855, "timer_delete" },
	{ 0x65dbb301, "ttm_bo_mem_space" },
	{ 0xaf0c7a80, "drm_dp_mst_hpd_irq_send_new_request" },
	{ 0x4e68e9be, "rb_next_postorder" },
	{ 0xaf56600a, "arm64_use_ng_mappings" },
	{ 0x80e29f6, "ttm_device_init" },
	{ 0x1a18686d, "pci_wake_from_d3" },
	{ 0xcd91b127, "system_highpri_wq" },
	{ 0xe42a535c, "drm_dp_add_payload_part2" },
	{ 0x6a4f623b, "mmu_notifier_synchronize" },
	{ 0x7a09088c, "sysfs_create_files" },
	{ 0x15c5d9fe, "get_task_pid" },
	{ 0xa20e8a23, "drm_connector_attach_dp_subconnector_property" },
	{ 0xcf2a6966, "up" },
	{ 0x6696454d, "ww_mutex_trylock" },
	{ 0x1c97b51e, "drm_release" },
	{ 0x5119cb31, "drm_atomic_helper_connector_destroy_state" },
	{ 0xe0af659a, "drm_universal_plane_init" },
	{ 0x10db9e50, "drm_atomic_helper_crtc_reset" },
	{ 0x9c7cc34, "pcie_capability_read_word" },
	{ 0xfcec0987, "enable_irq" },
	{ 0x9714e0bb, "ktime_get_raw" },
	{ 0x9da407a, "drm_dp_stop_crc" },
	{ 0x7aa1756e, "kvfree" },
	{ 0x69875d0e, "pci_bus_resource_n" },
	{ 0x4e2a621e, "drm_prime_sg_to_dma_addr_array" },
	{ 0x99f2d00a, "sysfs_emit_at" },
	{ 0x3a1f312a, "drm_connector_attach_vrr_capable_property" },
	{ 0x62713c0, "drm_crtc_accurate_vblank_count" },
	{ 0x3454c238, "drm_atomic_helper_disable_plane" },
	{ 0x7b2f29b, "param_ops_string" },
	{ 0x385c7481, "__tracepoint_mmap_lock_start_locking" },
	{ 0x3ec8e16c, "device_destroy" },
	{ 0x86bc07de, "drm_sched_job_arm" },
	{ 0x4cbc63fa, "drm_dp_mst_dsc_aux_for_port" },
	{ 0x92ec510d, "jiffies64_to_msecs" },
	{ 0xe7a02573, "ida_alloc_range" },
	{ 0x334e65b8, "drm_mode_create_scaling_mode_property" },
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0x8bd71bb5, "drm_read" },
	{ 0x1f50c56a, "dma_buf_map_attachment" },
	{ 0x7c433569, "pci_restore_msi_state" },
	{ 0x1def1415, "i2c_add_adapter" },
	{ 0x9c084b51, "__drm_atomic_helper_plane_duplicate_state" },
	{ 0xea9b6428, "drm_simple_encoder_init" },
	{ 0x5f340e40, "kobject_init" },
	{ 0x8f9d4cb4, "drm_dp_mst_topology_mgr_init" },
	{ 0x8e17b3ae, "idr_destroy" },
	{ 0x89940875, "mutex_lock_interruptible" },
	{ 0x23565453, "drm_crtc_handle_vblank" },
	{ 0x40c7247c, "si_meminfo" },
	{ 0xd5dbc655, "drm_atomic_helper_check_plane_state" },
	{ 0xaacf03c1, "dma_fence_signal" },
	{ 0x18b632c7, "drm_syncobj_get_fd" },
	{ 0x20c295f0, "drm_gem_fb_create_handle" },
	{ 0x6ebe366f, "ktime_get_mono_fast_ns" },
	{ 0x575ee134, "drm_plane_create_zpos_property" },
	{ 0x56470118, "__warn_printk" },
	{ 0xfd32dc62, "drm_atomic_get_mst_topology_state" },
	{ 0x953e1b9e, "ktime_get_real_seconds" },
	{ 0x96d89242, "drm_dev_register" },
	{ 0x89c7251a, "drm_crtc_vblank_helper_get_vblank_timestamp" },
	{ 0xe4542dce, "mmput" },
	{ 0xa2de0ee3, "drm_gem_ttm_vunmap" },
	{ 0xe2b9efbb, "drm_dp_send_real_edid_checksum" },
	{ 0xb749ee4b, "param_ops_bint" },
	{ 0x28fde3c6, "drm_dp_link_train_channel_eq_delay" },
	{ 0xf215b718, "device_remove_file" },
	{ 0x2c208607, "power_supply_is_system_supplied" },
	{ 0x17de3d5, "nr_cpu_ids" },
	{ 0x6d2a769d, "drm_dp_remove_payload" },
	{ 0x1f167ef1, "drm_crtc_init_with_planes" },
	{ 0xb1da6dcd, "kthread_unpark" },
	{ 0x96b29254, "strncasecmp" },
	{ 0xe914e41e, "strcpy" },
	{ 0x1e1a8de, "kgdb_breakpoint" },
	{ 0x7e3277f8, "___drm_dbg" },
	{ 0xb03fe913, "kmem_cache_destroy" },
	{ 0xfb384d37, "kasprintf" },
	{ 0x115dff56, "pci_set_power_state" },
	{ 0x3bb63412, "ttm_device_clear_dma_mappings" },
	{ 0xf64bca43, "hwmon_device_unregister" },
	{ 0xaf05b3bc, "contig_page_data" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0xc8c85086, "sg_free_table" },
	{ 0xa286f4b7, "drm_gem_object_lookup" },
	{ 0xad1a5955, "drm_crtc_init" },
	{ 0x6837b116, "drm_atomic_helper_connector_reset" },
	{ 0xc3c8c75d, "drm_aperture_remove_conflicting_pci_framebuffers" },
	{ 0x481acc5, "pm_genpd_init" },
	{ 0xa5481204, "default_llseek" },
	{ 0x93531b79, "perf_event_update_userpage" },
	{ 0xc3ff38c2, "down_read_trylock" },
	{ 0x27092e31, "ttm_pool_free" },
	{ 0x9fa7184a, "cancel_delayed_work_sync" },
	{ 0x7c983a5d, "dmi_walk" },
	{ 0xa47826e4, "drm_dp_calc_pbn_mode" },
	{ 0x37befc70, "jiffies_to_msecs" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x1d298f94, "drm_sched_entity_init" },
	{ 0x8d72789e, "drm_edid_is_valid" },
	{ 0x5fa06655, "dma_buf_fd" },
	{ 0x2d9e9583, "drm_buddy_print" },
	{ 0x2e8f7de3, "drm_dp_aux_init" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x689067dd, "dma_fence_chain_ops" },
	{ 0xffb7c514, "ida_free" },
	{ 0x6f23373b, "ttm_bo_move_to_lru_tail" },
	{ 0xc752dccf, "drm_sched_entity_flush" },
	{ 0x1503f64d, "mmu_notifier_get_locked" },
	{ 0x89c2ad7f, "drm_kms_helper_poll_disable" },
	{ 0xc2cb55b8, "drm_dp_check_act_status" },
	{ 0x35260f5a, "trace_event_buffer_reserve" },
	{ 0xa6257a2f, "complete" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0x9b9de1c1, "drm_edid_header_is_valid" },
	{ 0xa0598ccd, "drm_plane_enable_fb_damage_clips" },
	{ 0xfeb953b1, "__drm_printfn_seq_file" },
	{ 0x3ecb6ac7, "_dev_emerg" },
	{ 0x55f705a7, "pci_assign_unassigned_bus_resources" },
	{ 0x11fb43f9, "param_ops_bool" },
	{ 0x9fa9698d, "drm_mode_create_hdmi_colorspace_property" },
	{ 0xc32ec4c6, "dma_free_attrs" },
	{ 0x628c0f8f, "dma_fence_add_callback" },
	{ 0xed77bc38, "drm_atomic_helper_check" },
	{ 0xa41879d1, "dma_buf_get" },
	{ 0x92d84e4d, "ttm_bo_unpin" },
	{ 0xcc109eb6, "drm_dp_mst_connector_early_unregister" },
	{ 0x6d72048b, "drm_plane_create_color_properties" },
	{ 0x3da28742, "drm_gem_dmabuf_release" },
	{ 0x3cdc37e9, "drm_edid_to_speaker_allocation" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0x716265c7, "debugfs_initialized" },
	{ 0x6091797f, "synchronize_rcu" },
	{ 0x15b3c027, "drm_hdmi_avi_infoframe_from_display_mode" },
	{ 0x88a9a6ce, "vm_mmap" },
	{ 0x2178a3cf, "drm_gem_dmabuf_vunmap" },
	{ 0x7c545285, "drm_edid_get_monitor_name" },
	{ 0x615911d7, "__bitmap_set" },
	{ 0x9119a60b, "drm_modeset_lock" },
	{ 0x3434f437, "single_release" },
	{ 0xe02c9c92, "__xa_erase" },
	{ 0x9f28b4e7, "drm_atomic_get_connector_state" },
	{ 0xfbe215e4, "sg_next" },
	{ 0x3b6c41ea, "kstrtouint" },
	{ 0x89fffe03, "dma_resv_test_signaled" },
	{ 0x4afb2238, "add_wait_queue" },
	{ 0x4a64e82b, "drm_encoder_cleanup" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0xd2f85632, "drm_connector_attach_colorspace_property" },
	{ 0xe8334c43, "drm_atomic_get_plane_state" },
	{ 0xd5e14ff7, "drm_helper_probe_single_connector_modes" },
	{ 0x619cb7dd, "simple_read_from_buffer" },
	{ 0xca9360b5, "rb_next" },
	{ 0x52459368, "__free_pages" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0xd6d79c3a, "__pm_runtime_disable" },
	{ 0xd55124e2, "ttm_bo_eviction_valuable" },
	{ 0x617a3b1f, "__devm_drm_dev_alloc" },
	{ 0x57131e77, "pci_write_config_word" },
	{ 0x26815dbc, "drm_dp_link_rate_to_bw_code" },
	{ 0x861f6a91, "debugfs_attr_read" },
	{ 0x479f3dd1, "drm_plane_helper_destroy" },
	{ 0x1b87b0ff, "pci_read_config_dword" },
	{ 0x56cc6e39, "drm_dp_aux_register" },
	{ 0xc6ed0b34, "component_add" },
	{ 0xdeb99119, "dma_fence_init" },
	{ 0x31507999, "drm_sched_entity_push_job" },
	{ 0x122ebad3, "drm_atomic_add_affected_planes" },
	{ 0x2189aa5a, "drm_syncobj_find" },
	{ 0x3ef8f454, "send_sig" },
	{ 0xa65c6def, "alt_cb_patch_nops" },
	{ 0x4a666d56, "hrtimer_cancel" },
	{ 0x58d8fcaa, "drm_dsc_pps_payload_pack" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x7b82b9a1, "idr_replace" },
	{ 0x830560ed, "drm_crtc_add_crc_entry" },
	{ 0x6cbbfc54, "__arch_copy_to_user" },
	{ 0x4b7ebf95, "drm_mm_remove_node" },
	{ 0x52c66ec4, "drm_modeset_drop_locks" },
	{ 0xcf2ea86b, "__tracepoint_mmap_lock_acquire_returned" },
	{ 0x75f2fec3, "pcie_set_readrq" },
	{ 0xcd6ea6f8, "drm_dp_dpcd_read_link_status" },
	{ 0x4241d946, "kthread_park" },
	{ 0x4d32f61e, "__srcu_read_unlock" },
	{ 0x148653, "vsnprintf" },
	{ 0x3fa3f54a, "dma_buf_unpin" },
	{ 0xaea73547, "ttm_bo_vm_open" },
	{ 0x9e962d0b, "__pm_runtime_suspend" },
	{ 0xe3dd3308, "drm_atomic_get_crtc_state" },
	{ 0x6f287c34, "drm_syncobj_replace_fence" },
	{ 0xdf5f7e2f, "i2c_bit_add_bus" },
	{ 0xc31d0d94, "pci_ignore_hotplug" },
	{ 0x583d5e7b, "drm_modeset_backoff" },
	{ 0x98fb5823, "drm_atomic_helper_crtc_destroy_state" },
	{ 0xd5c4684c, "kthread_unuse_mm" },
	{ 0xe920db28, "pci_free_irq_vectors" },
	{ 0x41954096, "drm_cvt_mode" },
	{ 0x6c55814a, "drm_edid_override_connector_update" },
	{ 0xfbbe5226, "kobject_init_and_add" },
	{ 0x72c8caa6, "ttm_pool_init" },
	{ 0x56190217, "drm_dp_mst_add_affected_dsc_crtcs" },
	{ 0xbe3f18dc, "get_task_mm" },
	{ 0x8c8569cb, "kstrtoint" },
	{ 0x2a849a0b, "drm_poll" },
	{ 0x7e764882, "dma_unmap_resource" },
	{ 0x13145da, "dma_alloc_attrs" },
	{ 0xde8d6d59, "drmm_mode_config_init" },
	{ 0xb5cf2d7e, "kobject_set_name" },
	{ 0x70294ff, "drm_atomic_helper_wait_for_flip_done" },
	{ 0x3673a039, "__irq_domain_add" },
	{ 0xa8a8110c, "kernel_neon_end" },
	{ 0x3da092b8, "dma_fence_get_stub" },
	{ 0x3314531c, "ttm_bo_move_memcpy" },
	{ 0xffc7d51d, "drm_kms_helper_poll_init" },
	{ 0x3d8acfe, "pcie_bandwidth_available" },
	{ 0x30cb6068, "pci_write_config_dword" },
	{ 0x4ec54e78, "bitmap_to_arr32" },
	{ 0xc1d797eb, "unmap_mapping_range" },
	{ 0xa63bd841, "drm_property_create_range" },
	{ 0xed02b1ca, "drm_framebuffer_init" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xa85a3e6d, "xa_load" },
	{ 0x5c600623, "drm_dp_mst_hpd_irq_handle_event" },
	{ 0x2d39b0a7, "kstrdup" },
	{ 0xc87c6199, "ttm_lru_bulk_move_tail" },
	{ 0x26d8426f, "kmem_cache_alloc" },
	{ 0xc3af0b96, "ttm_resource_fini" },
	{ 0x1b106d56, "drm_mode_crtc_set_gamma_size" },
	{ 0x792736a6, "drm_sched_increase_karma" },
	{ 0xe2d928a8, "drm_dp_mst_dump_topology" },
	{ 0x3cdecc00, "debugfs_create_file" },
	{ 0xb8f64758, "mfd_add_devices" },
	{ 0xd89a552a, "trace_event_buffer_commit" },
	{ 0xf1b5340a, "drm_mode_vrefresh" },
	{ 0x18bcd516, "param_ops_charp" },
	{ 0x1e7426c1, "debugfs_attr_write" },
	{ 0x56256e8a, "orderly_poweroff" },
	{ 0x55eb38da, "drm_format_info" },
	{ 0x28779e52, "drm_printf" },
	{ 0x18c44c2c, "pci_release_resource" },
	{ 0x53f95e59, "drm_mode_config_cleanup" },
	{ 0x5d112304, "__memcpy_fromio" },
	{ 0xa35b93f4, "kmalloc_caches" },
	{ 0x89c00665, "dev_driver_string" },
	{ 0x210d5086, "drm_atomic_helper_cleanup_planes" },
	{ 0x47d02d6b, "sysfs_create_group" },
	{ 0xf2b64149, "_dev_err" },
	{ 0xcc195ee6, "pci_disable_device" },
	{ 0x3ed2d0e, "__drm_atomic_helper_crtc_reset" },
	{ 0x5e3240a0, "__cpu_online_mask" },
	{ 0x999e8297, "vfree" },
	{ 0xd680a377, "drm_gem_object_free" },
	{ 0xf51a1f16, "drm_atomic_helper_plane_destroy_state" },
	{ 0xb5417181, "drm_atomic_get_private_obj_state" },
	{ 0xe8704b6a, "put_pid" },
	{ 0xc93b3776, "drm_property_create_enum" },
	{ 0x4879c194, "drm_handle_vblank" },
	{ 0xcfe631d2, "ttm_bo_kunmap" },
	{ 0xf8b35584, "bpf_trace_run9" },
	{ 0xeaff7f0f, "drm_compat_ioctl" },
	{ 0x4be5a213, "pci_resize_resource" },
	{ 0x7a00d6af, "drm_gem_ttm_mmap" },
	{ 0xcbedc829, "class_destroy" },
	{ 0xd6bba1fe, "ttm_bo_put" },
	{ 0x4fdc67fb, "drm_syncobj_add_point" },
	{ 0xf0bb707a, "__drm_atomic_helper_connector_duplicate_state" },
	{ 0xf77555cd, "__memcpy_toio" },
	{ 0xea5d74b, "amdgpu_xcp_drv_release" },
	{ 0x229e7be5, "__drm_atomic_helper_crtc_duplicate_state" },
	{ 0x8debd4c9, "drm_suballoc_free" },
	{ 0xf4394767, "bpf_trace_run5" },
	{ 0x9b477107, "dma_map_page_attrs" },
	{ 0x6afd0b70, "dma_unmap_sg_attrs" },
	{ 0xab2614a5, "dma_map_sgtable" },
	{ 0xaadf5ef2, "device_create_file" },
	{ 0xe4bbc1dd, "kimage_voffset" },
	{ 0x448241f7, "drm_dp_mst_atomic_check" },
	{ 0x5e0ffe14, "ttm_pool_debugfs" },
	{ 0x149587d1, "bpf_trace_run1" },
	{ 0x8b621f95, "backlight_device_register" },
	{ 0x781a7bf2, "bpf_trace_run3" },
	{ 0x21ea5251, "__bitmap_weight" },
	{ 0x2e4ad4d4, "pcie_aspm_enabled" },
	{ 0x79f8a221, "drm_prime_gem_destroy" },
	{ 0x449ad0a7, "memcmp" },
	{ 0xecfa9650, "ttm_range_man_fini_nocheck" },
	{ 0xdc2ceabc, "drm_atomic_helper_async_check" },
	{ 0xfc911b5a, "pm_runtime_enable" },
	{ 0x4b750f53, "_raw_spin_unlock_irq" },
	{ 0xf07464e4, "hrtimer_forward" },
	{ 0x587ae305, "drm_exec_fini" },
	{ 0x339e85b5, "drm_dev_unplug" },
	{ 0xe778f1cc, "drm_connector_attach_hdr_output_metadata_property" },
	{ 0xc8dcc62a, "krealloc" },
	{ 0xcdb99cc9, "drm_mode_init" },
	{ 0xea00fe81, "__drm_printfn_coredump" },
	{ 0x96848186, "scnprintf" },
	{ 0xd11d6b7e, "pci_map_rom" },
	{ 0x57674fd7, "__sw_hweight16" },
	{ 0xbf196e86, "dma_resv_get_singleton" },
	{ 0x3cebeade, "drm_sched_job_init" },
	{ 0x10327928, "mmu_interval_read_begin" },
	{ 0xa3194274, "drm_gem_fb_destroy" },
	{ 0x542945dd, "sysfs_create_file_ns" },
	{ 0x5268f915, "drm_hdcp_update_content_protection" },
	{ 0xd9332b2f, "drm_hdmi_infoframe_set_hdr_metadata" },
	{ 0xa1eaed54, "find_get_pid" },
	{ 0x8e78f398, "drm_vblank_init" },
	{ 0x5670afd0, "drm_exec_cleanup" },
	{ 0x5bad0d97, "dma_set_coherent_mask" },
	{ 0x92540fbf, "finish_wait" },
	{ 0xc1e5a392, "drm_sched_entity_destroy" },
	{ 0xea124bd1, "gcd" },
	{ 0x6bd0e573, "down_interruptible" },
	{ 0xa63cd727, "drm_syncobj_find_fence" },
	{ 0x66b4cc41, "kmemdup" },
	{ 0x11c4f7fe, "drm_hdmi_vendor_infoframe_from_display_mode" },
	{ 0xac4da463, "pm_runtime_set_autosuspend_delay" },
	{ 0x124c0cf8, "dma_buf_pin" },
	{ 0xfd97a197, "kobject_get" },
	{ 0xd4835ef8, "dmi_check_system" },
	{ 0x4f27b27d, "pcie_get_mps" },
	{ 0xb8f11603, "idr_alloc" },
	{ 0x3854774b, "kstrtoll" },
	{ 0xee91879b, "rb_first_postorder" },
	{ 0xb00ea861, "drm_helper_resume_force_mode" },
	{ 0xe5718ac4, "drm_plane_cleanup" },
	{ 0x5308fb09, "_dev_info" },
	{ 0x9166fc03, "__flush_workqueue" },
	{ 0x364c23ad, "mutex_is_locked" },
	{ 0x2a38ab8b, "__pci_register_driver" },
	{ 0x50877b9, "dmi_first_match" },
	{ 0xe3d121b3, "drm_connector_set_vrr_capable_property" },
	{ 0x96b9a60f, "drm_atomic_helper_plane_duplicate_state" },
	{ 0xf4074e30, "sysfs_remove_group" },
	{ 0x13d0adf7, "__kfifo_out" },
	{ 0x9e779b6b, "irq_domain_remove" },
	{ 0x9a0507bb, "drm_dp_mst_topology_mgr_destroy" },
	{ 0xb5e73116, "flush_delayed_work" },
	{ 0xf8e61fec, "drm_dp_mst_atomic_setup_commit" },
	{ 0x6a72806e, "ww_mutex_lock" },
	{ 0xbd1fa494, "simple_attr_release" },
	{ 0xc1514a3b, "free_irq" },
	{ 0xbd60453a, "kobject_put" },
	{ 0x3199fbeb, "mem_section" },
	{ 0xd4c14632, "system_unbound_wq" },
	{ 0xabdc171f, "drm_encoder_init" },
	{ 0x6a8b0722, "seq_read" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x88378b0a, "device_for_each_child" },
	{ 0xda98d039, "dma_get_required_mask" },
	{ 0xabb5a026, "drm_buddy_block_trim" },
	{ 0xfe1d6c97, "pm_genpd_remove_device" },
	{ 0x9cb2927d, "drm_connector_attach_content_protection_property" },
	{ 0x1e6c272e, "ttm_bo_vm_reserve" },
	{ 0x862a8862, "drm_sched_start" },
	{ 0x6589a5d9, "param_ops_uint" },
	{ 0x7bcd5d4e, "drm_connector_init_with_ddc" },
	{ 0x16d6d40a, "drm_dp_mst_get_port_malloc" },
	{ 0x607ece98, "drm_sched_entity_fini" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0x8840f8c0, "ttm_sg_tt_init" },
	{ 0xa6740e20, "drm_atomic_helper_calc_timestamping_constants" },
	{ 0xca5f20cd, "sysfs_add_file_to_group" },
	{ 0xa8aa9e1c, "drm_mode_config_helper_suspend" },
	{ 0x4dda04fc, "drm_gem_ttm_vmap" },
	{ 0x916bc186, "ttm_bo_validate" },
	{ 0xce807a25, "up_write" },
	{ 0x131f3d8b, "mmu_interval_notifier_insert" },
	{ 0x56b8f568, "i2c_del_adapter" },
	{ 0xe2ee4fd5, "ttm_resource_manager_create_debugfs" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x8626a2dd, "__drm_dev_dbg" },
	{ 0x8937d004, "drm_helper_mode_fill_fb_struct" },
	{ 0x729292f6, "kernel_write" },
	{ 0x221bea50, "sysfs_create_link" },
	{ 0x122c3a7e, "_printk" },
	{ 0x4b2ffedd, "__drm_atomic_helper_connector_reset" },
	{ 0xb9cad492, "__drm_atomic_state_free" },
	{ 0x37110088, "remove_wait_queue" },
	{ 0x7381287f, "trace_handle_return" },
	{ 0x7910fa99, "drm_calc_timestamping_constants" },
	{ 0xb66962c1, "ttm_glob" },
	{ 0x7856f884, "__get_task_comm" },
	{ 0x4cc1d587, "drm_crtc_vblank_on" },
	{ 0xe123f3d9, "dma_fence_release" },
	{ 0x4a3ad70e, "wait_for_completion_timeout" },
	{ 0x55ca9d9f, "drm_dp_mst_get_edid" },
	{ 0x1d71603f, "device_create" },
	{ 0x4f270e7c, "drm_connector_set_panel_orientation_with_quirk" },
	{ 0xdfd1616e, "drm_connector_cleanup" },
	{ 0x7441311d, "drm_gem_mmap" },
	{ 0xeed3e9eb, "sysfs_remove_file_from_group" },
	{ 0x2d2c902f, "perf_trace_buf_alloc" },
	{ 0x582f248e, "drm_dp_get_adjust_request_pre_emphasis" },
	{ 0x5aa6f00, "remap_pfn_range" },
	{ 0xff102b7d, "sysfs_remove_bin_file" },
	{ 0xbcab6ee6, "sscanf" },
	{ 0xdbb58502, "drm_dp_set_subconnector_property" },
	{ 0xad0665cd, "drm_kms_helper_poll_fini" },
	{ 0x364850b1, "down_write_killable" },
	{ 0xf9bd8154, "drm_atomic_helper_commit" },
	{ 0x9291cd3b, "memdup_user" },
	{ 0x98cf60b3, "strlen" },
	{ 0xea367d68, "drm_connector_update_edid_property" },
	{ 0xf737bb2d, "dput" },
	{ 0x2793b21, "drm_dp_link_train_clock_recovery_delay" },
	{ 0x551bd071, "__rb_erase_color" },
	{ 0x74979f36, "debugfs_create_file_size" },
	{ 0x23ba4663, "drm_atomic_helper_update_plane" },
	{ 0xe1573cb4, "drm_modeset_unlock" },
	{ 0xe9bbd9d0, "drm_kms_helper_hotplug_event" },
	{ 0x69e05e1d, "drm_any_plane_has_format" },
	{ 0x42d0cd47, "perf_trace_run_bpf_submit" },
	{ 0x3199c743, "debugfs_create_u32" },
	{ 0x315e4fc1, "drm_prime_pages_to_sg" },
	{ 0x3ce4ca6f, "disable_irq" },
	{ 0x43b0c9c3, "preempt_schedule" },
	{ 0x4bcf5398, "drm_mode_config_reset" },
	{ 0x5d7875d, "drm_exec_init" },
	{ 0x790551e4, "ttm_bo_move_accel_cleanup" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0x343d123f, "drm_atomic_helper_resume" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x7158c716, "i2c_transfer" },
	{ 0x2be514d9, "pci_enable_device" },
	{ 0x9ed12e20, "kmalloc_large" },
	{ 0x5c3c7387, "kstrtoull" },
	{ 0x8526c012, "drm_gem_plane_helper_prepare_fb" },
	{ 0xc142f645, "pci_rebar_get_possible_sizes" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0x7c7f7985, "drm_kms_helper_poll_enable" },
	{ 0x69cc2943, "ttm_tt_pages_limit" },
	{ 0x18b48e28, "__memset_io" },
	{ 0x30c5fb62, "drm_dp_mst_root_conn_atomic_check" },
	{ 0xece5377, "ttm_device_fini" },
	{ 0xb4032484, "drm_mm_insert_node_in_range" },
	{ 0xaa0c318b, "vscnprintf" },
	{ 0x4f5aca9b, "kmalloc_trace" },
	{ 0x6b0d711b, "drm_connector_init" },
	{ 0x18dcfcb1, "trace_raw_output_prep" },
	{ 0x41e5fc81, "sysfs_remove_files" },
	{ 0xba18f65b, "drm_dp_add_payload_part1" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0xbcc1049e, "fput" },
	{ 0xc6cbbc89, "capable" },
	{ 0xb9f0bb19, "drm_connector_list_iter_begin" },
	{ 0xe4b96a52, "drm_mode_create_dp_colorspace_property" },
	{ 0xb6127243, "drm_need_swiotlb" },
	{ 0xd7b3917a, "drm_dp_mst_topology_mgr_resume" },
	{ 0xbad1988, "drm_suballoc_new" },
	{ 0x9688de8b, "memstart_addr" },
	{ 0x8ebe50d, "drm_is_current_master" },
	{ 0x9e9eab95, "devcgroup_check_permission" },
	{ 0x74fa8337, "sysfs_remove_file_ns" },
	{ 0xdd64e639, "strscpy" },
	{ 0xe3ac15d5, "drm_mode_is_420_only" },
	{ 0xb3f985a8, "sg_alloc_table" },
	{ 0xd025f7d0, "irq_create_mapping_affinity" },
	{ 0x27225406, "drm_sched_job_add_dependency" },
	{ 0x2f9a80ba, "__pm_runtime_use_autosuspend" },
	{ 0xcfea1bec, "drm_suballoc_dump_debug_info" },
	{ 0xdd9c3522, "drm_suballoc_manager_fini" },
	{ 0x6f33fed0, "class_create" },
	{ 0x3e2c663c, "drm_crtc_vblank_count" },
	{ 0xde42671a, "__mmap_lock_do_trace_released" },
	{ 0x5816f362, "sysfs_remove_link" },
	{ 0xa6f36eb1, "drm_crtc_cleanup" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0x3b992076, "dma_fence_array_create" },
	{ 0xcb6a59ac, "ttm_pool_alloc" },
	{ 0x7bca984a, "pci_irq_vector" },
	{ 0x6a5cb5ee, "__get_free_pages" },
	{ 0xad15c462, "drm_plane_create_zpos_immutable_property" },
	{ 0x6ac01ea8, "drm_edid_to_sad" },
	{ 0x304f885e, "drm_mode_destroy" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x47cfd825, "kstrtouint_from_user" },
	{ 0xa66107ad, "drm_crtc_vblank_put" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0xda6fc2ee, "seq_puts" },
	{ 0x9e19fade, "drm_ioctl" },
	{ 0x715c3168, "param_ops_ullong" },
	{ 0xeb39f234, "handle_simple_irq" },
	{ 0x8171f39f, "trace_event_reg" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x20a7f3b7, "drm_mode_duplicate" },
	{ 0xdd2764f9, "drm_exec_prepare_obj" },
	{ 0x7cd9f6d7, "drm_plane_create_alpha_property" },
	{ 0x74c134b9, "__sw_hweight32" },
	{ 0x8fd180e7, "kernel_neon_begin" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0x1f00c349, "drm_dev_printk" },
	{ 0x8dafaf22, "hdmi_avi_infoframe_pack" },
	{ 0xca21ebd3, "bitmap_free" },
	{ 0xedc03953, "iounmap" },
	{ 0x9dae1cfa, "simple_open" },
	{ 0x49083559, "drm_object_attach_property" },
	{ 0x5a4734d1, "drm_kms_helper_is_poll_worker" },
	{ 0xe478ef45, "module_layout" },
};

MODULE_INFO(depends, "drm,drm_kms_helper,drm_display_helper,ttm,gpu-sched,drm_buddy,amdxcp,drm_suballoc_helper,drm_exec,backlight,drm_ttm_helper,i2c-algo-bit");

MODULE_ALIAS("pci:v00001002d00006780sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006784sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006788sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000678Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006790sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006791sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006792sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006798sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006799sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000679Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000679Bsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000679Esv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000679Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006800sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006801sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006802sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006806sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006808sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006809sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006810sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006811sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006816sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006817sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006818sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006819sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006600sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006601sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006602sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006603sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006604sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006605sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006606sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006607sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006608sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006610sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006611sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006613sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006617sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006620sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006621sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006623sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006631sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006820sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006821sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006822sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006823sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006824sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006825sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006826sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006827sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006828sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006829sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000682Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000682Bsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000682Csv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000682Dsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000682Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006830sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006831sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006835sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006837sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006838sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006839sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000683Bsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000683Dsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000683Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006660sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006663sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006664sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006665sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006667sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000666Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00001304sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00001305sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00001306sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00001307sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00001309sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000130Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000130Bsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000130Csv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000130Dsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000130Esv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000130Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00001310sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00001311sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00001312sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00001313sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00001315sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00001316sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00001317sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00001318sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000131Bsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000131Csv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000131Dsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006640sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006641sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006646sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006647sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006649sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006650sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006651sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006658sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000665Csv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000665Dsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000665Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000067A0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000067A1sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000067A2sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000067A8sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000067A9sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000067AAsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000067B0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000067B1sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000067B8sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000067B9sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000067BAsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000067BEsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00009830sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00009831sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00009832sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00009833sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00009834sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00009835sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00009836sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00009837sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00009838sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00009839sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000983Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000983Bsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000983Csv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000983Dsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000983Esv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000983Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00009850sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00009851sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00009852sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00009853sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00009854sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00009855sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00009856sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00009857sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00009858sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00009859sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000985Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000985Bsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000985Csv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000985Dsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000985Esv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000985Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006900sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006901sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006902sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006903sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006907sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006920sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006921sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006928sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006929sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000692Bsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000692Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006930sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006938sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006939sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00007300sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000730Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00009870sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00009874sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00009875sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00009876sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00009877sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000098E4sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000067E0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000067E3sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000067E8sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000067EBsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000067EFsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000067FFsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000067E1sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000067E7sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000067E9sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000067C0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000067C1sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000067C2sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000067C4sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000067C7sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000067D0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000067DFsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000067C8sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000067C9sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000067CAsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000067CCsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000067CFsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006FDFsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006980sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006981sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006985sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006986sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006987sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006995sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006997sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000699Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000694Csv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000694Esv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000694Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006860sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006861sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006862sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006863sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006864sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006867sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006868sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00006869sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000686Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000686Bsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000686Csv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000686Dsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000686Esv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000686Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000687Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000069A0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000069A1sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000069A2sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000069A3sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000069AFsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000066A0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000066A1sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000066A2sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000066A3sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000066A4sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000066A7sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000066AFsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000015DDsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000015D8sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000738Csv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00007388sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000738Esv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00007390sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00007310sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00007312sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00007318sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00007319sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000731Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000731Bsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000731Esv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000731Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00007340sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00007341sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00007347sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000734Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000015E7sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00001636sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00001638sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000164Csv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00007360sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00007362sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073A0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073A1sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073A2sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073A3sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073A5sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073A8sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073A9sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073ABsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073ACsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073ADsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073AEsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073AFsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073BFsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000164Dsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00001681sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073C0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073C1sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073C3sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073DAsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073DBsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073DCsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073DDsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073DEsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073DFsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073E0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073E1sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073E2sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073E3sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073E8sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073E9sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073EAsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073EBsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073ECsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073EDsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073EFsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000073FFsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00007408sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000740Csv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000740Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00007410sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d000013FEsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000143Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00007420sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00007421sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00007422sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00007423sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00007424sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000743Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d*sv*sd*bc03sc00i00*");
MODULE_ALIAS("pci:v00001002d*sv*sd*bc03sc80i00*");
MODULE_ALIAS("pci:v00001002d*sv*sd*bc12sc00i00*");

MODULE_INFO(srcversion, "86D4E85B693F8BCED4EA4FD");
