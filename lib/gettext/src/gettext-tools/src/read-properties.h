/* Reading Java .properties files.
   Copyright (C) 2003, 2006 Free Software Foundation, Inc.
   Written by Bruno Haible <bruno@clisp.org>, 2003.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software Foundation,
   Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */

#ifndef _READ_PROPERTIES_H
#define _READ_PROPERTIES_H

#include "read-catalog-abstract.h"

/* Describes a .properties file parser.  */
extern DLL_VARIABLE const struct catalog_input_format input_format_properties;

#endif /* _READ_PROPERTIES_H */
