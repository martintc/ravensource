--- Modules/_multiprocessing/posixshmem.c.orig	2021-08-30 14:26:41 UTC
+++ Modules/_multiprocessing/posixshmem.c
@@ -9,6 +9,9 @@ posixshmem - A Python extension that pro
 
 // for shm_open() and shm_unlink()
 #ifdef HAVE_SYS_MMAN_H
+# ifdef __sun__
+# define _XPG4_2
+# endif
 #include <sys/mman.h>
 #endif
 
