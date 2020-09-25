--- Modules/_multiprocessing/posixshmem.c.orig	2020-09-23 12:36:32 UTC
+++ Modules/_multiprocessing/posixshmem.c
@@ -9,6 +9,9 @@ posixshmem - A Python extension that pro
 
 // for shm_open() and shm_unlink()
 #ifdef HAVE_SYS_MMAN_H
+# ifdef __sun__
+# define _XPG4_2
+# endif
 #include <sys/mman.h>
 #endif
 
