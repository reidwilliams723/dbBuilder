/**************************************************************************
 *
 * Tag Database Config File
 *
 **************************************************************************
 *
 * This file is modifiable for the user to choose the functionality of setting and
 * getting persistent tags from the database. It also provides the flexibility for
 * customizing how the memory is verified for use. Be sure to include the header file for
 * whichever library the functions are mapped to.
 *
 * (c) 2019, IOT-eq LLC, All Rights Reserved
 * Programmed By: 	Reid Williams
 * 					Inaki Zuloaga
 *
 **************************************************************************
 */

#ifndef IOTEQDBCONFIG_H_
#define IOTEQDBCONFIG_H_

#include "fram_interface.h"
#include "em_core.h"
#include "ioteqDB.h"

#ifdef PERSISTENCE_ENABLED

#define setPersistentTag(tag, valueBuffer)  /* PLACE USER FUCTION HERE ->>>>>*/  	writePersistentMemory(tag, valueBuffer)
#define getPersistentTag(tag, valueBuffer)  /* PLACE USER FUCTION HERE ->>>>>*/  	readPersistentMemory(tag, valueBuffer)
#define verifyPersistentMemory()  			/* PLACE USER FUCTION HERE ->>>>>*/  	verifyPersistentMemory()
#define markVerifiedPersistentMemory()  	/* PLACE USER FUCTION HERE ->>>>>*/ 	markPersistentMemoryVerified()
#endif

#ifdef PRIVATE_ENABLED

#define setPrivateTag(tag, valueBuffer)  /* PLACE USER FUCTION HERE ->>>>>*/  	writePrivateMemory(tag, valueBuffer)
#define getPrivateTag(tag, valueBuffer)  /* PLACE USER FUCTION HERE ->>>>>*/  	readPrivateMemory(tag, valueBuffer)
#define verifyPrivateMemory()  			/* PLACE USER FUCTION HERE ->>>>>*/  	verifyPrivateMemory()
#define markVerifiedPrivateMemory()  	/* PLACE USER FUCTION HERE ->>>>>*/ 	markPrivateMemoryVerified()
#endif

#define lock()		CORE_CriticalDisableIrq()
#define	unlock()	CORE_CriticalEnableIrq()
#endif
