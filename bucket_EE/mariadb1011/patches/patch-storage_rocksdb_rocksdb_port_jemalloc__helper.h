--- storage/rocksdb/rocksdb/port/jemalloc_helper.h.orig	2022-11-14 18:13:58 UTC
+++ storage/rocksdb/rocksdb/port/jemalloc_helper.h
@@ -26,6 +26,10 @@
 #include <jemalloc/jemalloc.h>
 #endif
 
+#ifdef __FreeBSD__
+#define JEMALLOC_USABLE_SIZE_CONST const
+#endif
+
 #ifndef JEMALLOC_CXX_THROW
 #define JEMALLOC_CXX_THROW
 #endif
