--- src/egl/main/eglglobals.c.orig	2023-01-26 17:07:55 UTC
+++ src/egl/main/eglglobals.c
@@ -41,6 +41,10 @@
 #include "util/macros.h"
 #include "util/os_misc.h"
 
+#ifdef __DragonFly__
+#undef HAVE_MINCORE
+#endif
+
 #ifdef HAVE_MINCORE
 #include <unistd.h>
 #include <sys/mman.h>
