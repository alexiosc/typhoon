/*----------------------------------------------------------------------------
 * File    : ty_log.h
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
 *   Contains the definitions used for online backup.
 *
 * $Id: ty_log.h,v 1.1.1.1 2003/08/12 14:51:29 alexios Exp $
 *
 * $Log: ty_log.h,v $
 * Revision 1.1.1.1  2003/08/12 14:51:29  alexios
 * Original CVS imported source tree.
 *
 * Revision 1.1  1995/05/21  16:47:36  tbp
 * Added file to repository.
 *
 * Revision 1.1  1994/09/13  21:28:36  tbp
 * Added to repository.
 * 
 *
 *--------------------------------------------------------------------------*/

#define LOG_FNAME	"typhoon.log"
#define LOG_UPDATE	1
#define LOG_DELETE	2

typedef struct {
	short	id;							/* = LOG_INSERT						*/
	ushort	len;						/* Length of entire block			*/
	ulong	recid;
	ulong	recno;
/*	char	data[1];*/
} LogUpdate;

typedef struct {
	short	id;							/* = LOG_DELETE						*/
	ushort	len;						/* Length of entire block			*/
	ulong	recid;
	ulong	recno;
} LogDelete;


#define ARCHIVE_MEDIA		1
#define ARCHIVE_RECORD		2
#define ARCHIVE_FILE		3
#define ARCHIVE_FILEDATA	4
#define ARCHIVE_TABLE		5
#define ARCHIVE_END			6

#define ARCHIVE_BLOCK		99

typedef struct {
	ulong	id;							/* = ARCHIVE_MEDIA					*/
	char	dbname[DBNAME_LEN+1];
	char	spare[3];
	long	date;						/* Date of backup					*/
	ulong	seqno;						/* Media number in backup			*/
	char	spare2[512];
} ArchiveMediaHeader;

typedef struct {
	ulong	id;							/* = ARCHIVE_RECORD					*/
	ulong	recid;
	ulong	recno;
} ArchiveRecordHeader;

typedef struct {
	ulong	id;							/* = ARCHIVE_FILE					*/
	ulong	recsize;
	char	table[IDENT_LEN+1];
	char	fname[128];
} ArchiveTableHeader;

typedef struct {
	ulong	id;							/* = ARCHIVE_FILE					*/
	char	fname[128];
} ArchiveFileHeader;

typedef struct {
	ulong	id;							/* = ARCHIVE_FILEDATA				*/
	ulong	size;
} ArchiveFileDataHeader;

typedef struct {
	ulong	id;							/* = ARCHIVE_END					*/
} ArchiveEnd;

typedef struct {
	ulong	id;
	ulong	size;
} ArchiveBlockHeader;


/* 
	Archive structure
	==============================
	
	[MediaHeader]

	[FileHeader]				----+
	[FileDataHeader]				|
	data							+---	dbd-file
	[FileDataHeader]				|
	data							|
	...								|
	[FileDataHeader size=0]		----+

	[TableHeader]				----+
	[RecordHeader]					|
	record							|
	[RecordHeader]					+---	database
	record							|
	...								|
	[RecordHeader]					|
	record						----+

	[FileHeader]				----+
	[FileDataHeader]				|
	data							+---	log file
	[FileDataHeader]				|
	data							|
	...								|
	[FileDataHeader size=0]		----+
	
	[End]
*/


/* end-of-file */
