/*----------------------------------------------------------------------------
 * File    : ty_prot.h
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
 *   Contains function prototypes.
 *
 * $Id: ty_prot.h,v 1.1.1.1 2003/08/12 14:51:29 alexios Exp $
 *
 * $Log: ty_prot.h,v $
 * Revision 1.1.1.1  2003/08/12 14:51:29  alexios
 * Original CVS imported source tree.
 *
 * Revision 1.1  1995/05/21  16:47:37  tbp
 * Added file to repository.
 *
 * Revision 1.2  1995/04/03  22:30:20  tbp
 * Added sequence support.
 *
 * Revision 1.1  1994/09/13  21:28:37  tbp
 * Added to repository.
 * 
 *
 *--------------------------------------------------------------------------*/

/*-------------------------------- Constants -------------------------------*/
#define UNCOMPRESS	0					/* Command to compress_vlr()		*/
#define COMPRESS	1					/* Command to compress_vlr()		*/

/*------------------------------- ty_auxfn.c -------------------------------*/
int		 aux_getkey		PRM( (Id, Key **);								)
int		 report_err		PRM( (int);										)
void	 set_subcode	PRM( (Key *);									)
int		 set_recfld		PRM( (Id, Record **, Field **);					)
void 	*set_keyptr		PRM( (Key *, void *);							)
int		 keyfind		PRM( (Key *, void *, ulong *);					)
int		 keyadd			PRM( (Key *, void *, ulong);					)
int		 keydel			PRM( (Key *, void *, ulong);					)
int		 reckeycmp		PRM( (Key *, void *, void *);					)
int		 compress_vlr	PRM( (int, Record *, void *, void *, unsigned *);)
int		 null_indicator	PRM( (Key *, void *);							)
int		 update_recbuf  PRM( (void);									)


/*------------------------------- ty_refin.c -------------------------------*/
void	 update_foreign_keys	PRM( (Record *, int);					)
int		 check_foreign_keys 	PRM( (Record *, void *, int);			)
void	 delete_foreign_keys	PRM( (Record *);						)
int		 check_dependent_tables PRM( (Record *, void *, int); 			)


/*--------------------------------- ty_io.c --------------------------------*/
int      ty_openfile    PRM( (File *, Fh *, int);  			            )
int      ty_closefile   PRM( (Fh *);      		                        )
int		 ty_keyadd		PRM( (Key *, void *, ulong);   	   	  			)
int      ty_keydel      PRM( (Key *, void *, ulong);   	   	  			)
int		 ty_keyfind		PRM( (Key *, void *, ulong *); 	   	  			)
int		 ty_keyread		PRM( (Key *, void *);		   		  			)
int		 ty_keyfrst		PRM( (Key *, ulong *);		   		  			)
int		 ty_keylast		PRM( (Key *, ulong *);		   	   	  			)
int		 ty_keynext		PRM( (Key *, ulong *);		   		  			)
int		 ty_keyprev		PRM( (Key *, ulong *);		   	   	  			)
int		 ty_recadd      PRM( (Record *, void *, ulong *);	  			)
int      ty_recwrite    PRM( (Record *, void *, ulong);		  			)
int      ty_recread     PRM( (Record *, void *, ulong);		  			)
int      ty_recread     PRM( (Record *, void *, ulong);		  			)
int      ty_recdelete   PRM( (Record *, ulong);				  			)
ulong    ty_numrecords  PRM( (Record *, ulong *);						)
int      ty_recfrst     PRM( (Record *, void *);						)
int      ty_reclast     PRM( (Record *, void *);						)
int      ty_recnext     PRM( (Record *, void *);						)
int      ty_recprev     PRM( (Record *, void *);						)
int		 ty_vlradd		PRM( (Record *, void *, unsigned, ulong *);		)
int		 ty_vlrwrite	PRM( (Record *, void *, unsigned, ulong); 		)
unsigned ty_vlrread		PRM( (Record *, void *, ulong, unsigned *);		)
int		 ty_vlrdel		PRM( (Record *, ulong);							)
int		 ty_reccurr		PRM( (Record *, ulong *);						)
int		 ty_closeafile	PRM( (void); )

void	 ty_logerror	PRM( (char *, ...); )

/*------------------------------- ty_repl.c --------------------------------*/
void	 ty_log			PRM( (int); )


/*--------------------------------- bt_open --------------------------------*/
void	btree_getheader	PRM( (INDEX *);									)
void	btree_putheader	PRM( (INDEX *);									)
INDEX  *btree_open		PRM( (char *, int, int, CMPFUNC, int, int);		)
void	btree_close		PRM( (INDEX *);									)
int		btree_dynopen	PRM( (INDEX *);									)
int		keydynclose		PRM( (INDEX *);									)
int		nodesearch		PRM( (INDEX *, void *, int *);					)
int		d_search		PRM( (INDEX *, void *, ix_addr *, int *);		)

/*------------------------------- bt_fucns.c -------------------------------*/
int		btree_add		PRM( (INDEX *, void *, ulong);					)
int		btree_find		PRM( (INDEX *, void *, ulong *);				)
int		btree_read		PRM( (INDEX *, void *);							)
int		btree_write		PRM( (INDEX *, void *);							)
int		btree_delall	PRM( (INDEX *);									)
int		btree_frst		PRM( (INDEX *, ulong *);						)
int		btree_last		PRM( (INDEX *, ulong *);						)
int		btree_next		PRM( (INDEX *, ulong *);						)
int		btree_prev		PRM( (INDEX *, ulong *);						)
int     btree_exist	    PRM( (INDEX *, void *, ulong);                  )

/*-------------------------------- bt_del.c --------------------------------*/
int     btree_del		PRM( (INDEX *, void *, ulong);					)

/*--------------------------------- bt_io.c --------------------------------*/
ix_addr noderead        PRM( (INDEX *, char *, ix_addr);                )
ix_addr nodewrite       PRM( (INDEX *, char *, ix_addr);                )

/*-------------------------------- record.c --------------------------------*/
RECORD  *rec_open     	PRM( (char *, unsigned, int);				    )
int      rec_close    	PRM( (RECORD *);								)
int		 rec_add      	PRM( (RECORD *, void *, ulong *);				)
int      rec_write    	PRM( (RECORD *, void *, ulong);					)
int      rec_read     	PRM( (RECORD *, void *, ulong);					)
int      rec_delete   	PRM( (RECORD *, ulong);							)
int      rec_curr     	PRM( (RECORD *, ulong *);						)
ulong    rec_numrecords	PRM( (RECORD *, ulong *);						)
int      rec_frst     	PRM( (RECORD *, void *);						)
int      rec_last     	PRM( (RECORD *, void *);						)
int      rec_next     	PRM( (RECORD *, void *);						)
int      rec_prev     	PRM( (RECORD *, void *);						)
int		 rec_lock		PRM( (RECORD *, ulong, int);			     	)
int		 rec_unlock		PRM( (RECORD *, ulong);							)

/*------------------------------- sequence.c -------------------------------*/
int		seq_open		PRM( (Dbentry *); )
int		seq_close		PRM( (Dbentry *); )

/*---------------------------------- vlr.c ---------------------------------*/
void	 vlr_close		PRM( (VLR *);									)
VLR		*vlr_open		PRM( (char *, unsigned, int);					)
int		 vlr_add		PRM( (VLR *, void *, unsigned, ulong *);		)
int		 vlr_write		PRM( (VLR *, void *, unsigned, ulong);			)
int		 vlr_read		PRM( (VLR *, void *, ulong, unsigned *);		)
int		 vlr_del		PRM( (VLR *, ulong);							)

/*---------------------------------- os.c ----------------------------------*/
int		os_lock			PRM( (int, long, unsigned, int);				)
int		os_unlock		PRM( (int, long, unsigned);						)
int		os_open			PRM( (char *, int, int);						)
int		os_close		PRM( (int); )


/*--------------------------------- osxxx.c --------------------------------*/
int		ty_openlock		PRM( (void);									)
int		ty_closelock	PRM( (void);									)
int		ty_lock			PRM( (void);									)
int		ty_unlock		PRM( (void);									)
int		shm_alloc		PRM( (Dbentry *);								)
int		shm_free		PRM( (Dbentry *);								)


/*------------------------------- cmpfuncs.c -------------------------------*/
int 	compoundkeycmp	PRM( (void *, void *);							)
int		refentrycmp		PRM( (REF_ENTRY *, REF_ENTRY *);				)
void    InitLowerTable  PRM( (void);									)

/* end-of-file */
