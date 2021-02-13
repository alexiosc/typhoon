/*----------------------------------------------------------------------------
 * File    : import.h
 * Program : tyimport
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
 *   Header file for tyexport.
 *
 * $Id: import.h,v 1.1.1.1 2003/08/12 14:51:29 alexios Exp $
 *
 * $Log: import.h,v $
 * Revision 1.1.1.1  2003/08/12 14:51:29  alexios
 * Original CVS imported source tree.
 *
 * Revision 1.1  1995/05/21  16:47:48  tbp
 * Added file to repository.
 *
 * Revision 1.1  1994/09/19  19:57:09  tbp
 * Moved files from src/util to util.
 *
 * Revision 1.1  1994/09/13  21:28:58  tbp
 * Added to repository.
 *
 * Added to repository.
 * 
 *
 *--------------------------------------------------------------------------*/

#ifdef DEFINE_GLOBALS
#define CLASS
#define I(x)	= x
#else
#define CLASS	extern
#define I(x)
#endif

/*--------------------------- Function prototypes --------------------------*/
int	yyerror				PRM( (char *fmt ELLIPSIS); )

void err_quit			PRM( (char * ELLIPSIS); )
void GenerateImportSpec	PRM( (char *); )
void ReadImportSpec		PRM( (char *); )

/*------------------------------- Constants --------------------------------*/
#define FT_INCLUDE		0x8000					/* Set in field[].type if	*/
												/* field should be included	*/
												/* import.					*/


/*---------------------------- Global variables ----------------------------*/
CLASS Dbentry	dbd;
CLASS char		dbd_fname[256];
CLASS char		spec_fname[256];
CLASS int		lex_lineno			I( 1 );		/* Current line number		*/
CLASS int		errors				I( 0 );		/* Number of errors			*/
CLASS Header	header;							/* .dbd file header			*/

#undef CLASS
#undef I

/* end-of-file */









































