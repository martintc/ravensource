--- tools/llvm-objcopy/MachO/Object.cpp.orig	2020-07-07 16:21:37 UTC
+++ tools/llvm-objcopy/MachO/Object.cpp
@@ -1,6 +1,18 @@
 #include "Object.h"
 #include "../llvm-objcopy.h"
 
+#ifdef __sun__
+static size_t
+strnlen(const char *s, size_t maxlen)
+{
+       size_t len;
+       for (len = 0; len < maxlen; len++, s++) {
+               if (!*s) break;
+       }
+       return (len);
+}
+#endif
+
 namespace llvm {
 namespace objcopy {
 namespace macho {
