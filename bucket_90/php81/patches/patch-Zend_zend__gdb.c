--- Zend/zend_gdb.c.orig	2023-07-04 23:26:29 UTC
+++ Zend/zend_gdb.c
@@ -25,7 +25,9 @@
 #include <fcntl.h>
 #include <unistd.h>
 
-#if defined(__FreeBSD__)
+#if defined(__MidnightBSD__)
+# include <sys/user.h>
+#elif defined(__FreeBSD__)
 # include <sys/user.h>
 # include <libutil.h>
 #endif
