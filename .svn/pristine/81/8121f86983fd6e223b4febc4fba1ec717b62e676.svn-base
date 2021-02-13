/*----------------------------------------------------------------------------
 * File    : bt_io.c
 * Library : typhoon
 * OS      : UNIX, OS/2, DOS
 * Author  : Thomas B. Pedersen
 *
 * Copyright (c) 1994 Thomas B. Pedersen.  All rights reserved.
 *
 * Permission is hereby granted, without written agreement and without
 * license or royalty fees, to use, copy, modify, and distribute this
 * software and its documentation for any purpose, provided that the above
 * copyright notice and the following two  paragraphs appear (1) in all 
 * source copies of this software and (2) in accompanying documentation
 * wherever the programatic interface of this software, or any derivative
 * of it, is described.
 *
 * IN NO EVENT SHALL THOMAS B. PEDERSEN BE LIABLE TO ANY PARTY FOR DIRECT,
 * INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES ARISING OUT OF
 * THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN IF HE HAS BEEN 
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * THOMAS B. PEDERSEN SPECIFICALLY DISCLAIMS ANY WARRANTIES, INCLUDING, BUT
 * NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS ON AN "AS IS" 
 * BASIS, AND THOMAS B. PEDERSEN HAS NO OBLIGATION TO PROVIDE MAINTENANCE,
 * SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.
 *
 * Description:
 *   Contains functions for opening and closing B-tree index files.
 *
 * Functions:
 *
 *--------------------------------------------------------------------------*/

/*
 * This banner added by Alexios Chouchoulas because this file was
 * modified to enable it to be compiled on modern (2003) operating
 * systems.
 *
 * $Id: bt_io.c,v 1.2 2003/08/12 15:30:38 alexios Exp $
 *
 * $Log: bt_io.c,v $
 * Revision 1.2  2003/08/12 15:30:38  alexios
 * Slight modifications to allow compilation on modern Linux boxen.
 *
 */

static char rcsid[] = "$Id: bt_io.c,v 1.2 2003/08/12 15:30:38 alexios Exp $";

#include <string.h>
#include <stdio.h>
#ifndef UNIX
#if 0
#	include <io.h>
#endif
#else
#	include <unistd.h>
#endif
#include <sys/types.h>
#include <typhoon.h>
#include "ty_dbd.h"
#include "ty_type.h"
#include "btree.h"


ix_addr noderead(I, node, page)
INDEX   *I;
char    *node;
ix_addr  page;
{
    lseek(I->fh, (long)page * I->H.nodesize, SEEK_SET);
    if( read(I->fh, node, I->H.nodesize) < I->H.nodesize )
        return (ix_addr)-1;
 
    return page;
}


ix_addr nodewrite(I, node, page)
INDEX   *I;
char    *node;
ix_addr  page;
{
    if( page == NEWPOS )
    {
        if( I->H.first_deleted )
        {
            page = I->H.first_deleted;
            lseek(I->fh, (long)I->H.nodesize * page, SEEK_SET);
            read(I->fh, &I->H.first_deleted, sizeof I->H.first_deleted);
        }
        else
			page = (lseek(I->fh, 0L, SEEK_END) / I->H.nodesize);
    }

	lseek(I->fh, (long)page * I->H.nodesize, SEEK_SET);
	write(I->fh, node, I->H.nodesize);

    return page;
}
 
/* end-of-file */					
