--- src/amd/llvm/ac_llvm_build.h.orig	2021-06-30 18:18:55 UTC
+++ src/amd/llvm/ac_llvm_build.h
@@ -35,6 +35,10 @@
 
 #include <stdbool.h>
 
+#ifdef __sun
+#include <alloca.h>
+#endif
+
 #ifdef __cplusplus
 extern "C" {
 #endif
