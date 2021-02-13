## Process this file with automake to produce Makefile.in
#
# $Id: Makefile.am,v 1.1 2003/08/12 16:14:08 alexios Exp $
#
# $Log: Makefile.am,v $
# Revision 1.1  2003/08/12 16:14:08  alexios
# Initial revision.
#

bin_PROGRAMS = ddlp dbdview tyexport tyimport
HDR = ddlpglob.h lex.h ddlp.h ddlpsym.h export.h import.h util.h
ddlp_SOURCES = ddl.y ddlp.c ddlplex.c ddlpsym.c $(HDR)
dbdview_SOURCES = dbdview.c $(HDR)
tyexport_SOURCES = exp.y export.c exportlx.c expspec.c $(HDR)
tyimport_SOURCES = imp.y import.c importlx.c impspec.c $(HDR)
AM_CFLAGS = -DUNIX -I../src -I../include
LDADD = ../src/.libs/libtyphoon.a
AM_YFLAGS = -d
