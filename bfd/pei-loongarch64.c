/* BFD back-end for LoongArch64 PE IMAGE COFF files.
   Copyright (C) 2022-2023 Free Software Foundation, Inc.

   This file is part of BFD, the Binary File Descriptor library.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston,
   MA 02110-1301, USA.  */

#include "sysdep.h"
#include "bfd.h"

#define TARGET_SYM		loongarch64_pei_vec
#define TARGET_NAME		"pei-loongarch64"
#define TARGET_ARCHITECTURE	bfd_arch_loongarch
#define TARGET_PAGESIZE		0x4000
#define TARGET_BIG_ENDIAN	0
#define TARGET_ARCHIVE		0
#define TARGET_PRIORITY		0

#define COFF_IMAGE_WITH_PE
/* Rename the above into...  */
#define COFF_WITH_peLoongArch64
#define COFF_WITH_PE
#define PCRELOFFSET	   true

/* Long section names not allowed in executable images, only object files.  */
#define COFF_LONG_SECTION_NAMES 0

#define COFF_SECTION_ALIGNMENT_ENTRIES \
{ COFF_SECTION_NAME_EXACT_MATCH (".bss"), \
  COFF_ALIGNMENT_FIELD_EMPTY, COFF_ALIGNMENT_FIELD_EMPTY, 2 }, \
{ COFF_SECTION_NAME_EXACT_MATCH (".data"), \
  COFF_ALIGNMENT_FIELD_EMPTY, COFF_ALIGNMENT_FIELD_EMPTY, 2 }, \
{ COFF_SECTION_NAME_EXACT_MATCH (".rdata"), \
  COFF_ALIGNMENT_FIELD_EMPTY, COFF_ALIGNMENT_FIELD_EMPTY, 2 }, \
{ COFF_SECTION_NAME_EXACT_MATCH (".text"), \
  COFF_ALIGNMENT_FIELD_EMPTY, COFF_ALIGNMENT_FIELD_EMPTY, 2 }, \
{ COFF_SECTION_NAME_PARTIAL_MATCH (".idata"), \
  COFF_ALIGNMENT_FIELD_EMPTY, COFF_ALIGNMENT_FIELD_EMPTY, 2 }, \
{ COFF_SECTION_NAME_EXACT_MATCH (".pdata"), \
  COFF_ALIGNMENT_FIELD_EMPTY, COFF_ALIGNMENT_FIELD_EMPTY, 2 }, \
{ COFF_SECTION_NAME_PARTIAL_MATCH (".debug"), \
  COFF_ALIGNMENT_FIELD_EMPTY, COFF_ALIGNMENT_FIELD_EMPTY, 0 }, \
{ COFF_SECTION_NAME_PARTIAL_MATCH (".gnu.linkonce.wi."), \
  COFF_ALIGNMENT_FIELD_EMPTY, COFF_ALIGNMENT_FIELD_EMPTY, 0 }

#include "sysdep.h"
#include "bfd.h"
#include "libbfd.h"
#include "coff/loongarch64.h"
#include "coff/internal.h"
#include "coff/pe.h"
#include "libcoff.h"
#include "libpei.h"
#include "libiberty.h"

/* Make sure we're setting a 64-bit format.  */
#undef AOUTSZ
#define AOUTSZ          PEPAOUTSZ
#define PEAOUTHDR       PEPAOUTHDR

#include "coff-loongarch64.c"
