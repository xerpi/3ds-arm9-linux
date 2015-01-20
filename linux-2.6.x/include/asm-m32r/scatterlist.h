#ifndef _ASM_M32R_SCATTERLIST_H
#define _ASM_M32R_SCATTERLIST_H

/* $Id: scatterlist.h 573 2006-02-20 17:09:11Z stsp2 $ */

struct scatterlist {
    char *  address;    /* Location data is to be transferred to, NULL for
                         * highmem page */
    struct page * page; /* Location for highmem page, if any */
    unsigned int offset;/* for highmem, page offset */

    dma_addr_t dma_address;
    unsigned int length;
};

#define ISA_DMA_THRESHOLD (0x1fffffff)

#endif /* _ASM_M32R_SCATTERLIST_H */
