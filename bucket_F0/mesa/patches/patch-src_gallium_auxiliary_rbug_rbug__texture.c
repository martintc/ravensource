--- src/gallium/auxiliary/rbug/rbug_texture.c.orig	2021-12-29 21:05:19 UTC
+++ src/gallium/auxiliary/rbug/rbug_texture.c
@@ -36,6 +36,10 @@
 
 #include "c99_alloca.h"
 
+#ifdef __sun
+#include <alloca.h>
+#endif
+
 #include "rbug_internal.h"
 #include "rbug_texture.h"
 
