$NetBSD: patch-cmake_config.h.cmake,v 1.1 2019/10/25 09:44:26 kamil Exp $

--- cmake/config.h.cmake.orig	2023-05-08 16:01:13 UTC
+++ cmake/config.h.cmake
@@ -29,7 +29,17 @@
 
 /* Define to `const' or to empty, depending on the second argument of `iconv'. */
 #cmakedefine ICONV_ACCEPTS_CONST_INPUT
-#if defined(ICONV_ACCEPTS_CONST_INPUT) || defined(__NetBSD__)
+
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#if __NetBSD_Prereq__(9,99,17)
+#define NETBSD_POSIX_ICONV 1
+#else
+#define NETBSD_POSIX_ICONV 0
+#endif
+#endif
+
+#if defined(ICONV_ACCEPTS_CONST_INPUT) || (defined(__NetBSD__) && !NETBSD_POSIX_ICONV)
 #define EXV_ICONV_CONST const
 #else
 #define EXV_ICONV_CONST
