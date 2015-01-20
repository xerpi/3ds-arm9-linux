/* $Id: siginfo.h 573 2006-02-20 17:09:11Z stsp2 $
 * siginfo.c:
 */

#ifndef _SPARC_SIGINFO_H
#define _SPARC_SIGINFO_H

#define __ARCH_SI_UID_T		unsigned int
#define __ARCH_SI_TRAPNO

#include <asm-generic/siginfo.h>

#define SI_NOINFO	32767		/* no information in siginfo_t */

/*
 * SIGEMT si_codes
 */
#define EMT_TAGOVF	(__SI_FAULT|1)	/* tag overflow */
#define NSIGEMT		1

#endif /* !(_SPARC_SIGINFO_H) */
