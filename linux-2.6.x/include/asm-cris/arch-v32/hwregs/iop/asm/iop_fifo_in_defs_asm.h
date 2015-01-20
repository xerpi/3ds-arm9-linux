#ifndef __iop_fifo_in_defs_asm_h
#define __iop_fifo_in_defs_asm_h

/*
 * This file is autogenerated from
 *   file:           ../../inst/io_proc/rtl/iop_fifo_in.r
 *     id:           <not found>
 *     last modfied: Mon Apr 11 16:10:07 2005
 *
 *   by /n/asic/design/tools/rdesc/src/rdes2c -asm --outfile asm/iop_fifo_in_defs_asm.h ../../inst/io_proc/rtl/iop_fifo_in.r
 *      id: $Id: iop_fifo_in_defs_asm.h 573 2006-02-20 17:09:11Z stsp2 $
 * Any changes here will be lost.
 *
 * -*- buffer-read-only: t -*-
 */

#ifndef REG_FIELD
#define REG_FIELD( scope, reg, field, value ) \
  REG_FIELD_X_( value, reg_##scope##_##reg##___##field##___lsb )
#define REG_FIELD_X_( value, shift ) ((value) << shift)
#endif

#ifndef REG_STATE
#define REG_STATE( scope, reg, field, symbolic_value ) \
  REG_STATE_X_( regk_##scope##_##symbolic_value, reg_##scope##_##reg##___##field##___lsb )
#define REG_STATE_X_( k, shift ) (k << shift)
#endif

#ifndef REG_MASK
#define REG_MASK( scope, reg, field ) \
  REG_MASK_X_( reg_##scope##_##reg##___##field##___width, reg_##scope##_##reg##___##field##___lsb )
#define REG_MASK_X_( width, lsb ) (((1 << width)-1) << lsb)
#endif

#ifndef REG_LSB
#define REG_LSB( scope, reg, field ) reg_##scope##_##reg##___##field##___lsb
#endif

#ifndef REG_BIT
#define REG_BIT( scope, reg, field ) reg_##scope##_##reg##___##field##___bit
#endif

#ifndef REG_ADDR
#define REG_ADDR( scope, inst, reg ) REG_ADDR_X_(inst, reg_##scope##_##reg##_offset)
#define REG_ADDR_X_( inst, offs ) ((inst) + offs)
#endif

#ifndef REG_ADDR_VECT
#define REG_ADDR_VECT( scope, inst, reg, index ) \
         REG_ADDR_VECT_X_(inst, reg_##scope##_##reg##_offset, index, \
			 STRIDE_##scope##_##reg )
#define REG_ADDR_VECT_X_( inst, offs, index, stride ) \
                          ((inst) + offs + (index) * stride)
#endif

/* Register rw_cfg, scope iop_fifo_in, type rw */
#define reg_iop_fifo_in_rw_cfg___avail_lim___lsb 0
#define reg_iop_fifo_in_rw_cfg___avail_lim___width 3
#define reg_iop_fifo_in_rw_cfg___byte_order___lsb 3
#define reg_iop_fifo_in_rw_cfg___byte_order___width 2
#define reg_iop_fifo_in_rw_cfg___trig___lsb 5
#define reg_iop_fifo_in_rw_cfg___trig___width 2
#define reg_iop_fifo_in_rw_cfg___last_dis_dif_in___lsb 7
#define reg_iop_fifo_in_rw_cfg___last_dis_dif_in___width 1
#define reg_iop_fifo_in_rw_cfg___last_dis_dif_in___bit 7
#define reg_iop_fifo_in_rw_cfg___mode___lsb 8
#define reg_iop_fifo_in_rw_cfg___mode___width 2
#define reg_iop_fifo_in_rw_cfg_offset 0

/* Register rw_ctrl, scope iop_fifo_in, type rw */
#define reg_iop_fifo_in_rw_ctrl___dif_in_en___lsb 0
#define reg_iop_fifo_in_rw_ctrl___dif_in_en___width 1
#define reg_iop_fifo_in_rw_ctrl___dif_in_en___bit 0
#define reg_iop_fifo_in_rw_ctrl___dif_out_en___lsb 1
#define reg_iop_fifo_in_rw_ctrl___dif_out_en___width 1
#define reg_iop_fifo_in_rw_ctrl___dif_out_en___bit 1
#define reg_iop_fifo_in_rw_ctrl_offset 4

/* Register r_stat, scope iop_fifo_in, type r */
#define reg_iop_fifo_in_r_stat___avail_bytes___lsb 0
#define reg_iop_fifo_in_r_stat___avail_bytes___width 4
#define reg_iop_fifo_in_r_stat___last___lsb 4
#define reg_iop_fifo_in_r_stat___last___width 8
#define reg_iop_fifo_in_r_stat___dif_in_en___lsb 12
#define reg_iop_fifo_in_r_stat___dif_in_en___width 1
#define reg_iop_fifo_in_r_stat___dif_in_en___bit 12
#define reg_iop_fifo_in_r_stat___dif_out_en___lsb 13
#define reg_iop_fifo_in_r_stat___dif_out_en___width 1
#define reg_iop_fifo_in_r_stat___dif_out_en___bit 13
#define reg_iop_fifo_in_r_stat_offset 8

/* Register rs_rd1byte, scope iop_fifo_in, type rs */
#define reg_iop_fifo_in_rs_rd1byte___data___lsb 0
#define reg_iop_fifo_in_rs_rd1byte___data___width 8
#define reg_iop_fifo_in_rs_rd1byte_offset 12

/* Register r_rd1byte, scope iop_fifo_in, type r */
#define reg_iop_fifo_in_r_rd1byte___data___lsb 0
#define reg_iop_fifo_in_r_rd1byte___data___width 8
#define reg_iop_fifo_in_r_rd1byte_offset 16

/* Register rs_rd2byte, scope iop_fifo_in, type rs */
#define reg_iop_fifo_in_rs_rd2byte___data___lsb 0
#define reg_iop_fifo_in_rs_rd2byte___data___width 16
#define reg_iop_fifo_in_rs_rd2byte_offset 20

/* Register r_rd2byte, scope iop_fifo_in, type r */
#define reg_iop_fifo_in_r_rd2byte___data___lsb 0
#define reg_iop_fifo_in_r_rd2byte___data___width 16
#define reg_iop_fifo_in_r_rd2byte_offset 24

/* Register rs_rd3byte, scope iop_fifo_in, type rs */
#define reg_iop_fifo_in_rs_rd3byte___data___lsb 0
#define reg_iop_fifo_in_rs_rd3byte___data___width 24
#define reg_iop_fifo_in_rs_rd3byte_offset 28

/* Register r_rd3byte, scope iop_fifo_in, type r */
#define reg_iop_fifo_in_r_rd3byte___data___lsb 0
#define reg_iop_fifo_in_r_rd3byte___data___width 24
#define reg_iop_fifo_in_r_rd3byte_offset 32

/* Register rs_rd4byte, scope iop_fifo_in, type rs */
#define reg_iop_fifo_in_rs_rd4byte___data___lsb 0
#define reg_iop_fifo_in_rs_rd4byte___data___width 32
#define reg_iop_fifo_in_rs_rd4byte_offset 36

/* Register r_rd4byte, scope iop_fifo_in, type r */
#define reg_iop_fifo_in_r_rd4byte___data___lsb 0
#define reg_iop_fifo_in_r_rd4byte___data___width 32
#define reg_iop_fifo_in_r_rd4byte_offset 40

/* Register rw_set_last, scope iop_fifo_in, type rw */
#define reg_iop_fifo_in_rw_set_last_offset 44

/* Register rw_strb_dif_in, scope iop_fifo_in, type rw */
#define reg_iop_fifo_in_rw_strb_dif_in___last___lsb 0
#define reg_iop_fifo_in_rw_strb_dif_in___last___width 2
#define reg_iop_fifo_in_rw_strb_dif_in_offset 48

/* Register rw_intr_mask, scope iop_fifo_in, type rw */
#define reg_iop_fifo_in_rw_intr_mask___urun___lsb 0
#define reg_iop_fifo_in_rw_intr_mask___urun___width 1
#define reg_iop_fifo_in_rw_intr_mask___urun___bit 0
#define reg_iop_fifo_in_rw_intr_mask___last_data___lsb 1
#define reg_iop_fifo_in_rw_intr_mask___last_data___width 1
#define reg_iop_fifo_in_rw_intr_mask___last_data___bit 1
#define reg_iop_fifo_in_rw_intr_mask___dav___lsb 2
#define reg_iop_fifo_in_rw_intr_mask___dav___width 1
#define reg_iop_fifo_in_rw_intr_mask___dav___bit 2
#define reg_iop_fifo_in_rw_intr_mask___avail___lsb 3
#define reg_iop_fifo_in_rw_intr_mask___avail___width 1
#define reg_iop_fifo_in_rw_intr_mask___avail___bit 3
#define reg_iop_fifo_in_rw_intr_mask___orun___lsb 4
#define reg_iop_fifo_in_rw_intr_mask___orun___width 1
#define reg_iop_fifo_in_rw_intr_mask___orun___bit 4
#define reg_iop_fifo_in_rw_intr_mask_offset 52

/* Register rw_ack_intr, scope iop_fifo_in, type rw */
#define reg_iop_fifo_in_rw_ack_intr___urun___lsb 0
#define reg_iop_fifo_in_rw_ack_intr___urun___width 1
#define reg_iop_fifo_in_rw_ack_intr___urun___bit 0
#define reg_iop_fifo_in_rw_ack_intr___last_data___lsb 1
#define reg_iop_fifo_in_rw_ack_intr___last_data___width 1
#define reg_iop_fifo_in_rw_ack_intr___last_data___bit 1
#define reg_iop_fifo_in_rw_ack_intr___dav___lsb 2
#define reg_iop_fifo_in_rw_ack_intr___dav___width 1
#define reg_iop_fifo_in_rw_ack_intr___dav___bit 2
#define reg_iop_fifo_in_rw_ack_intr___avail___lsb 3
#define reg_iop_fifo_in_rw_ack_intr___avail___width 1
#define reg_iop_fifo_in_rw_ack_intr___avail___bit 3
#define reg_iop_fifo_in_rw_ack_intr___orun___lsb 4
#define reg_iop_fifo_in_rw_ack_intr___orun___width 1
#define reg_iop_fifo_in_rw_ack_intr___orun___bit 4
#define reg_iop_fifo_in_rw_ack_intr_offset 56

/* Register r_intr, scope iop_fifo_in, type r */
#define reg_iop_fifo_in_r_intr___urun___lsb 0
#define reg_iop_fifo_in_r_intr___urun___width 1
#define reg_iop_fifo_in_r_intr___urun___bit 0
#define reg_iop_fifo_in_r_intr___last_data___lsb 1
#define reg_iop_fifo_in_r_intr___last_data___width 1
#define reg_iop_fifo_in_r_intr___last_data___bit 1
#define reg_iop_fifo_in_r_intr___dav___lsb 2
#define reg_iop_fifo_in_r_intr___dav___width 1
#define reg_iop_fifo_in_r_intr___dav___bit 2
#define reg_iop_fifo_in_r_intr___avail___lsb 3
#define reg_iop_fifo_in_r_intr___avail___width 1
#define reg_iop_fifo_in_r_intr___avail___bit 3
#define reg_iop_fifo_in_r_intr___orun___lsb 4
#define reg_iop_fifo_in_r_intr___orun___width 1
#define reg_iop_fifo_in_r_intr___orun___bit 4
#define reg_iop_fifo_in_r_intr_offset 60

/* Register r_masked_intr, scope iop_fifo_in, type r */
#define reg_iop_fifo_in_r_masked_intr___urun___lsb 0
#define reg_iop_fifo_in_r_masked_intr___urun___width 1
#define reg_iop_fifo_in_r_masked_intr___urun___bit 0
#define reg_iop_fifo_in_r_masked_intr___last_data___lsb 1
#define reg_iop_fifo_in_r_masked_intr___last_data___width 1
#define reg_iop_fifo_in_r_masked_intr___last_data___bit 1
#define reg_iop_fifo_in_r_masked_intr___dav___lsb 2
#define reg_iop_fifo_in_r_masked_intr___dav___width 1
#define reg_iop_fifo_in_r_masked_intr___dav___bit 2
#define reg_iop_fifo_in_r_masked_intr___avail___lsb 3
#define reg_iop_fifo_in_r_masked_intr___avail___width 1
#define reg_iop_fifo_in_r_masked_intr___avail___bit 3
#define reg_iop_fifo_in_r_masked_intr___orun___lsb 4
#define reg_iop_fifo_in_r_masked_intr___orun___width 1
#define reg_iop_fifo_in_r_masked_intr___orun___bit 4
#define reg_iop_fifo_in_r_masked_intr_offset 64


/* Constants */
#define regk_iop_fifo_in_dif_in                   0x00000002
#define regk_iop_fifo_in_hi                       0x00000000
#define regk_iop_fifo_in_neg                      0x00000002
#define regk_iop_fifo_in_no                       0x00000000
#define regk_iop_fifo_in_order16                  0x00000001
#define regk_iop_fifo_in_order24                  0x00000002
#define regk_iop_fifo_in_order32                  0x00000003
#define regk_iop_fifo_in_order8                   0x00000000
#define regk_iop_fifo_in_pos                      0x00000001
#define regk_iop_fifo_in_pos_neg                  0x00000003
#define regk_iop_fifo_in_rw_cfg_default           0x00000024
#define regk_iop_fifo_in_rw_ctrl_default          0x00000000
#define regk_iop_fifo_in_rw_intr_mask_default     0x00000000
#define regk_iop_fifo_in_rw_set_last_default      0x00000000
#define regk_iop_fifo_in_rw_strb_dif_in_default   0x00000000
#define regk_iop_fifo_in_size16                   0x00000002
#define regk_iop_fifo_in_size24                   0x00000001
#define regk_iop_fifo_in_size32                   0x00000000
#define regk_iop_fifo_in_size8                    0x00000003
#define regk_iop_fifo_in_yes                      0x00000001
#endif /* __iop_fifo_in_defs_asm_h */
