// SPDX-License-Identifier: GPL-2.0-only
// SPDX-FileCopyrightText: 1991,1992 Linus Torvalds
// SPDX-FileCopyrightText: 2007 rPath, Inc.
// SPDX-FileCopyrightText: 2009 Intel Corporation

/* Author: H. Peter Anvin and others */

/**
 * @file
 * @brief Very simple screen I/O for the initialization stage
 *
 * @todo Probably should add very simple serial I/O?
 * @attention This is real mode code!
 */

#include <asm/segment.h>
#include "boot.h"

/* be aware of: */
THIS_IS_REALMODE_CODE

static void __bootcode putchar(int ch)
{
	struct biosregs ireg;

	if (ch == '\n')
		putchar('\r');	/* \n -> \r\n */

	initregs(&ireg);
	ireg.bx = 0x0007;
	ireg.cx = 0x0001;
	ireg.ah = 0x0e;
	ireg.al = ch;
	intcall(0x10, &ireg, NULL);
}

void __bootcode boot_puts(char *str)
{
	while (*str)
		putchar(*str++);
}
