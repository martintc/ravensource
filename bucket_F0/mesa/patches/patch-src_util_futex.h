--- src/util/futex.h.orig	2022-11-16 23:02:11 UTC
+++ src/util/futex.h
@@ -30,14 +30,36 @@
 #include <limits.h>
 #include <stdint.h>
 #include <unistd.h>
+#if defined __FreeBSD__
+#include <errno.h>
+#include <sys/umtx.h>
+#else
 #include <linux/futex.h>
 #include <sys/syscall.h>
+#endif
 #include <sys/time.h>
 
 #ifndef SYS_futex
 #define SYS_futex SYS_futex_time64
 #endif
 
+#if defined(__FreeBSD__)
+static inline int futex_wake(uint32_t *addr, int count)
+{
+   return _umtx_op(addr, UMTX_OP_WAKE, (uint32_t)count, NULL, NULL) == -1 ? errno : 0;
+}
+
+static inline int futex_wait(uint32_t *addr, int32_t value, struct timespec *timeout)
+{
+   void *uaddr = NULL, *uaddr2 = NULL;
+   if (timeout != NULL) {
+      const struct _umtx_time tmo = { ._timeout = *timeout, ._flags = UMTX_ABSTIME, ._clockid = CLOCK_MONOTONIC };
+      uaddr = (void *)(uintptr_t)sizeof(tmo);
+      uaddr2 = (void *)&tmo;
+   }
+   return _umtx_op(addr, UMTX_OP_WAIT_UINT, (uint32_t)value, uaddr, uaddr2) == -1 ? errno : 0;
+}
+#else
 static inline long sys_futex(void *addr1, int op, int val1, const struct timespec *timeout, void *addr2, int val3)
 {
    return syscall(SYS_futex, addr1, op, val1, timeout, addr2, val3);
@@ -55,6 +77,7 @@ static inline int futex_wait(uint32_t *a
    return sys_futex(addr, FUTEX_WAIT_BITSET, value, timeout, NULL,
                     FUTEX_BITSET_MATCH_ANY);
 }
+#endif
 
 #elif defined(__FreeBSD__)
 #define UTIL_FUTEX_SUPPORTED 1
