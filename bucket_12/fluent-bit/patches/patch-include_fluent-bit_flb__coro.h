NetBSD doesn't define THREAD_STACK_MIN, so pick an arbitrary 16 pages.
_XOPEN_SOURCE is messing up sys/socket.h on NetBSD so remove it.

--- include/fluent-bit/flb_coro.h.orig	2023-07-25 01:44:40 UTC
+++ include/fluent-bit/flb_coro.h
@@ -20,11 +20,6 @@
 #ifndef FLB_CORO_H
 #define FLB_CORO_H
 
-/* Required by OSX */
-#ifndef _XOPEN_SOURCE
-#define _XOPEN_SOURCE
-#endif
-
 #ifndef _DEFAULT_SOURCE
 #define _DEFAULT_SOURCE
 #endif
@@ -64,7 +59,12 @@ struct flb_coro {
 #ifdef FLB_CORO_STACK_SIZE
 #define FLB_CORO_STACK_SIZE_BYTE      FLB_CORO_STACK_SIZE
 #else
+# if defined(__NetBSD__) && !defined(PTHREAD_STACK_MIN)
+#include <machine/vmparam.h>
+#define FLB_CORO_STACK_SIZE_BYTE      (16 * PAGE_SIZE)
+# else
 #define FLB_CORO_STACK_SIZE_BYTE      ((3 * PTHREAD_STACK_MIN) / 2)
+# endif
 #endif
 
 #define FLB_CORO_DATA(coro)      (((char *) coro) + sizeof(struct flb_coro))
