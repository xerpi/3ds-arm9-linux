/* vi: set sw=4 ts=4: */
/*
 * dup2() for uClibc
 *
 * Copyright (C) 2000-2004 by Erik Andersen <andersen@codepoet.org>
 *
 * GNU Library General Public License (LGPL) version 2 or later.
 */

#include "syscalls.h"
#include <unistd.h>
_syscall2(int, dup2, int, oldfd, int, newfd);
