--- src/cast_helpers.h.orig	2023-04-12 16:45:12 UTC
+++ src/cast_helpers.h
@@ -16,6 +16,7 @@
 #error "cast_helpers.h file contains private xmlsec definitions and should not be used outside xmlsec or xmlsec-$crypto libraries"
 #endif /* XMLSEC_PRIVATE */
 
+#include <stdint.h>
 #include <limits.h>
 #include <stdint.h>
 #include "errors_helpers.h"
