#ifndef _PSP2_H_
#define _PSP2_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include <psp2/types.h>
#include <psp2/appmgr.h>
#include <psp2/udcd.h>
#include <psp2/io/fcntl.h>
#include <psp2/io/dirent.h>
#include <psp2/kernel/clib.h>
#include <psp2/kernel/modulemgr.h>
#include <psp2/kernel/threadmgr.h>
#include <psp2/kernel/processmgr.h>

#include <taihen.h>

typedef unsigned short u16;
typedef unsigned long u64;
typedef int (*PspDebugInputHandler)(char *data, int len);
typedef int (*PspDebugPrintHandler)(const char *data, int len);

#define Kprintf sceClibPrintf

#define SceModule SceKernelModuleInfo
#define sceKernelStartModule(a, b, c, d, e) sceKernelStartModule(a, b, c, 0, e, d)
#define sceKernelStopModule(a, b, c, d, e) sceKernelStopModule(a, b, c, 0, e, d)
#define sceKernelUnloadModule(a) sceKernelUnloadModule(a, 0, NULL)

#define sceKernelCreateThread(a, b, c, d, e, f) sceKernelCreateThread(a, b, c, d, e, 0x10000, f)
#define sceKernelReferThreadStatus sceKernelGetThreadInfo

#define sceKernelExitGame() sceKernelExitProcess(0)
#define scePowerTick sceKernelPowerTick

#define FIO_SO_ISLNK SCE_SO_ISLNK
#define FIO_SO_ISREG SCE_SO_ISREG
#define FIO_SO_ISDIR SCE_SO_ISDIR

#define FIO_S_ISLNK SCE_S_ISLNK
#define FIO_S_ISREG SCE_S_ISREG
#define FIO_S_ISDIR SCE_S_ISDIR

#define PSP_THREAD_RUNNING SCE_THREAD_RUNNING
#define PSP_THREAD_READY SCE_THREAD_READY
#define PSP_THREAD_WAITING SCE_THREAD_WAITING
#define PSP_THREAD_SUSPEND SCE_THREAD_SUSPEND
#define PSP_THREAD_STOPPED SCE_THREAD_STOPPED
#define PSP_THREAD_KILLED SCE_THREAD_KILLED

#define PSP_O_RDONLY	SCE_O_RDONLY
#define PSP_O_WRONLY	SCE_O_WRONLY
#define PSP_O_RDWR	    (SCE_O_RDONLY | SCE_O_WRONLY)
#define PSP_O_NBLOCK	SCE_O_NBLOCK
#define PSP_O_DIROPEN	SCE_O_DIROPEN	// Internal use for dopen
#define PSP_O_APPEND	SCE_O_APPEND
#define PSP_O_CREAT	    SCE_O_CREAT
#define PSP_O_TRUNC	    SCE_O_TRUNC
#define	PSP_O_EXCL      SCE_O_EXCL
#define PSP_O_NOWAIT	SCE_O_NOWAIT

#define PSP_SEEK_SET	SCE_SEEK_SET
#define PSP_SEEK_CUR	SCE_SEEK_CUR
#define PSP_SEEK_END	SCE_SEEK_END


#endif // _PSP2_H_
