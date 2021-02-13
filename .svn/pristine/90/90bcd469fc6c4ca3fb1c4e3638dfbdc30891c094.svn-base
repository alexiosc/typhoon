/*----------------------------------------------------------------------------
 * File    : unix.c
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
 *   Contiains functions specific to UNIX.
 *
 *   Locking with lockf is *not* the solution. But it'll fix the
 *   problem with semop.
 *
 * Functions:
 *   ty_openlock	- Create/open the locking resource.
 *   ty_closelock	- Close the locking resource.
 *   ty_lock		- Obtain the lock.
 *   ty_unlock		- Release the lock.
 *
 *--------------------------------------------------------------------------*/

/*
 * This banner added by Alexios Chouchoulas because this file was
 * modified to enable it to be compiled on modern (2003) operating
 * systems.
 *
 * $Id: unix.c,v 1.2 2003/08/12 15:30:38 alexios Exp $
 *
 * $Log: unix.c,v $
 * Revision 1.2  2003/08/12 15:30:38  alexios
 * Slight modifications to allow compilation on modern Linux boxen.
 *
 */

static char rcsid[] = "$Id: unix.c,v 1.2 2003/08/12 15:30:38 alexios Exp $";

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <typhoon.h>
#ifdef __linux__
#	include <sys/file.h>
#       ifndef F_TLOCK
#	        define F_TLOCK	LOCK_NB
#	        define F_LOCK	LOCK_EX
#	        define F_ULOCK	LOCK_UN
#	        define lockf(fd,op,len)	flock(fd,op)
#       endif
#endif
#include "ty_dbd.h"
#include "ty_type.h"

/*#define SEMLOCK quick fix */

#define TIMEOUT		10000L		/* Wait maximum 10 seconds for excl. access	*/

/*---------------------------- Global variables ----------------------------*/
#ifdef SEMLOCK
static struct sembuf sem_wait_buf[2] = {
	0, 0, 0,						/* wait for sem to become 0			*/
	0, 1, SEM_UNDO					/* then increment sem by 1			*/
};

static struct sembuf sem_clear_buf[1] = {
	0,-1, IPC_NOWAIT | SEM_UNDO,	/* decrease sem by 1				*/
};


static int 	sem_id;
#else
static int lock_fh = -1;
#endif


/*------------------------------ ty_openlock  ------------------------------*\
 *
 * Purpose	 : This function ensures that only one instance of a Typhoon
 *             function is active at the time, at least in its critical
 *             section.
 *
 * Parameters: None.
 *
 * Returns	 : -1		- Semaphore could not be created.
 *			   0		- Successful.
 *
 */

ty_openlock()
{
#ifndef SEMLOCK
	static char lockfname[] = "/tmp/typhoonsem";
	int pid = getpid();
	int old_umask = umask(0);

	if( lock_fh == -1 )
	{
		if( (lock_fh = open(lockfname, O_RDWR|O_CREAT, 0666)) == -1 )	
		{
			printf("Cannot open %s\n", lockfname);
			umask(old_umask);
			return -1;
		}

		write(lock_fh, &pid, sizeof pid);
	}

	umask(old_umask);

#endif
	return 0;
}


ty_closelock()
{
	close(lock_fh);
	lock_fh = -1;

	return 0;
}


ty_lock()
{
#ifdef SEMLOCK
#if 1
	while( semop(sem_id, sem_wait_buf, 2) == -1 && errno == EINTR )
		puts("ty_lock EAGAIN");
#else
	if( sem_wait(sem_id) == -1 )
		puts("ty_lock failed");
#endif
#endif

#ifndef SEMLOCK
	lseek(lock_fh, 0, SEEK_SET);

	while( lockf(lock_fh, F_LOCK, 1) == -1 )
	{
		if( errno != EINTR && errno != EAGAIN )	
		{
			printf("ty_lock failed (errno %d, lock_fh %d)\n", errno, lock_fh);
			break;
		}
	}
#endif
}


ty_unlock()
{
#ifdef SEMLOCK
#if 1
	while( semop(sem_id, sem_clear_buf, 1) == -1 && errno == EINTR )
		puts("ty_unlock EAGAIN");
#else
	if( sem_clear(sem_id) == -1 )	
		puts("ty_unlock failed");
#endif
#endif

#ifndef SEMLOCK
	lseek(lock_fh, 0, SEEK_SET);

	while( lockf(lock_fh, F_ULOCK, 1) == -1 )
	{
		if( errno != EINTR && errno != EAGAIN )
		{
			printf("ty_unlock failed (errno %d, lock_fh %d)\n", errno, lock_fh);
			break;
		}
	}
#endif


	return 0;
}




shm_alloc(db)
Dbentry *db;
{
	char dbdname[128];
	key_t key;
	long flags = IPC_CREAT|0770;
	int created = 0;

	sprintf(dbdname, "%s.dbd", db->name);
	key = ftok(dbdname, 30);
	
	if( (db->shm_id = shmget(key, sizeof(*db->shm), 0)) == -1 )
	    if( (db->shm_id = shmget(key, sizeof(*db->shm), flags)) == -1 )
	    	return -1;
	    else
	    	created = 1;
#ifdef SEMLOCK
#if 1
	if( (sem_id = semget(key, 1, 0)) == -1 )
		if( (sem_id = semget(key, 1, IPC_CREAT|0660)) == -1 )
		{
			shmdt((char *)db->shm);
			if( created )
				shmctl(db->shm_id, IPC_RMID, NULL);
			return -1;
		}
#else
	if( (sem_id = sem_open(key)) == -1 )
		if( (sem_id = sem_create(key, 1)) == -1 )
		{
			shmdt((char *)db->shm);
			if( created )
				shmctl(db->shm_id, IPC_RMID, NULL);
			return -1;
		}
#endif
#endif

	if( (db->shm = (TyphoonSharedMemory *)shmat(db->shm_id,0,0)) == (void *)-1 )
	{
		if( created )
			shmctl(db->shm_id, IPC_RMID, NULL);
		return -1;
	}

	if( created )
		memset(db->shm, 0, sizeof *db->shm);
	db->shm->use_count++;

	return 0;
}


shm_free(db)
Dbentry *db;
{
	if( --db->shm->use_count == 0 )
	{
		shmdt((char *)db->shm);
		shmctl(db->shm_id, IPC_RMID, NULL);
#ifdef SEMLOCK
		semctl(sem_id, 0, IPC_RMID, 0);
#endif
	}
	else
		shmdt((char *)db->shm);
#if 0
	sem_close(sem_id);
#endif
}


/* end-of-file */
