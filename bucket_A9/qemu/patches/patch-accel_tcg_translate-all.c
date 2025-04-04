--- accel/tcg/translate-all.c.orig	2023-08-22 15:34:01 UTC
+++ accel/tcg/translate-all.c
@@ -27,7 +27,7 @@
 #include "qemu.h"
 #if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
 #include <sys/param.h>
-#if __FreeBSD_version >= 700104
+#if defined(__MidnightBSD__) || __FreeBSD_version >= 700104
 #define HAVE_KINFO_GETVMMAP
 #define sigqueue sigqueue_freebsd  /* avoid redefinition */
 #include <sys/proc.h>
