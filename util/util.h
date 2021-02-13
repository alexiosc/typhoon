/*----------------------------------------------------------------------------
 * File    : util.h
 * Program : tybackup, tyrestore
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
 *   Prototypes for functions in util.c.
 *
 * $Id: util.h,v 1.1.1.1 2003/08/12 14:51:29 alexios Exp $
 *
 * $Log: util.h,v $
 * Revision 1.1.1.1  2003/08/12 14:51:29  alexios
 * Original CVS imported source tree.
 *
 * Revision 1.1  1995/05/21  16:47:51  tbp
 * Added file to repository.
 *
 * Revision 1.2  1994/09/19  19:58:00  tbp
 * Removed rcsid[] definition.
 *
 * Revision 1.1  1994/09/19  19:57:11  tbp
 * Moved files from src/util to util.
 *
 * Revision 1.1  1994/09/13  21:29:01  tbp
 * Added to repository.
 *
 * Added to repository.
 * 
 *
 *--------------------------------------------------------------------------*/

/*-------------------------- Function prototypes ---------------------------*/
void	clock_on					PRM( (void); )
void	clock_off					PRM( (void); )
ulong	clock_secs					PRM( (void); )
char	*printlong					PRM( (ulong); )


/* end-of-file */
