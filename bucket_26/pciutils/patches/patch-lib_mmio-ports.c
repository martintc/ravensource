--- lib/mmio-ports.c.orig	2022-11-20 12:06:14 UTC
+++ lib/mmio-ports.c
@@ -30,6 +30,10 @@
 #define OFF_MAX (off_t)((1ULL << (sizeof(off_t) * CHAR_BIT - 1)) - 1)
 #endif
 
+#ifndef O_DSYNC
+#define O_DSYNC 0
+#endif
+
 struct mmio_cache
 {
   off_t addr_page;
