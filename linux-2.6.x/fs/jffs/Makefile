#
# Makefile for the linux Journalling Flash FileSystem (JFFS) routines.
#
# $Id: Makefile 573 2006-02-20 17:09:11Z stsp2 $
#

obj-$(CONFIG_JFFS_FS) += jffs.o

jffs-y 				:= jffs_fm.o intrep.o inode-v23.o
jffs-$(CONFIG_JFFS_PROC_FS)	+= jffs_proc.o
jffs-objs			:= $(jffs-y)
