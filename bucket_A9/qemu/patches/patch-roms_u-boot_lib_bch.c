--- roms/u-boot/lib/bch.c.orig	2023-04-19 16:32:34 UTC
+++ roms/u-boot/lib/bch.c
@@ -63,7 +63,7 @@
 #include <linux/bitops.h>
 #else
 #include <errno.h>
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 #include <sys/endian.h>
 #elif defined(__APPLE__)
 #include <machine/endian.h>
