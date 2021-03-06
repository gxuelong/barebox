/*
 * Copyright (C) 2013 Jean-Christophe PLAGNIOL-VILLARD <plagnio@jcrosoft.com>
 *
 * GPLv2 only
 */

#include <common.h>
#include <linux/sizes.h>
#include <asm/barebox-arm-head.h>
#include <asm/barebox-arm.h>
#include <asm/system_info.h>

void qemu_virt64_start(uint32_t, uint32_t, uint32_t);

void noinline qemu_virt64_start(uint32_t r0, uint32_t r1, uint32_t r2)
{
	arm_cpu_lowlevel_init();
	arm_setup_stack(0x40000000 + SZ_2G - SZ_16K);

	barebox_arm_entry(0x40000000, SZ_2G, NULL);
}
