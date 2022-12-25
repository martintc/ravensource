--- ddf_raid.c.orig	2007-12-27 01:05:32 UTC
+++ ddf_raid.c
@@ -22,9 +22,9 @@
 #include <string.h>
 #include <errno.h>
 #include <ctype.h>
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__OpenBSD__)
 #include <sys/endian.h>
-#else
+#elif !defined(__APPLE__) && !defined(__sun__)
 #include <byteswap.h>
 #endif /* __FreeBSD__ */
 
