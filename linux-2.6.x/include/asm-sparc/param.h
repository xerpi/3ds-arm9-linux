/* $Id: param.h 573 2006-02-20 17:09:11Z stsp2 $ */
#ifndef _ASMSPARC_PARAM_H
#define _ASMSPARC_PARAM_H

#ifdef __KERNEL__
# define HZ		100	/* Internal kernel timer frequency */
# define USER_HZ	100	/* .. some user interfaces are in "ticks" */
# define CLOCKS_PER_SEC (USER_HZ)
#endif

#ifndef HZ
#define HZ 100
#endif

#define EXEC_PAGESIZE	8192    /* Thanks for sun4's we carry baggage... */

#ifndef NOGROUP
#define NOGROUP		(-1)
#endif

#define MAXHOSTNAMELEN	64	/* max length of hostname */

#endif
