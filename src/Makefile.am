## Process this file with automake to produce Makefile.in
#
# $Id: Makefile.am,v 1.1 2003/08/12 15:31:23 alexios Exp $
#
# $Log: Makefile.am,v $
# Revision 1.1  2003/08/12 15:31:23  alexios
# Initial revision.
#

lib_LTLIBRARIES = libtyphoon.la

SRCS		= bt_del.c bt_funcs.c bt_io.c bt_open.c cmpfuncs.c os.c \
		  readdbd.c record.c ty_auxfn.c ty_find.c ty_ins.c \
		  ty_io.c ty_log.c ty_open.c ty_refin.c ty_repl.c \
		  ty_util.c unix.c vlr.c ansi.c sequence.c
noinst_HEADERS	= btree.h catalog.h ty_dbd.h ty_glob.h ty_log.h ty_prot.h \
		  ty_repif.h ty_type.h


libtyphoon_la_SOURCES = $(SRCS)
libtyphoon_la_LDFLAGS = -version-info $(LIBVERSION)
AM_CFLAGS = -DUNIX -I../include
