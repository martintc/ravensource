--- src/util/u_atomic.h.orig	2023-08-16 17:19:13 UTC
+++ src/util/u_atomic.h
@@ -20,11 +20,7 @@
  * locally coded assembly, compiler intrinsic or ultimately a
  * mutex-based implementation.
  */
-#if defined(__sun)
-#define PIPE_ATOMIC_OS_SOLARIS
-#elif defined(_MSC_VER)
-#define PIPE_ATOMIC_MSVC_INTRINSIC
-#elif defined(__GNUC__)
+#if defined(__GNUC__)
 #define PIPE_ATOMIC_GCC_INTRINSIC
 #else
 #error "Unsupported platform"
