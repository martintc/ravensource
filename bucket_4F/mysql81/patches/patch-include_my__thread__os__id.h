--- include/my_thread_os_id.h.orig	2023-06-21 07:52:10 UTC
+++ include/my_thread_os_id.h
@@ -36,6 +36,10 @@
 #include <unistd.h>
 #endif
 
+#ifdef __NetBSD__
+#include <lwp.h>
+#endif
+
 #ifdef HAVE_PTHREAD_GETTHREADID_NP
 #include <pthread_np.h> /* pthread_getthreadid_np() */
 #endif                  /* HAVE_PTHREAD_GETTHREADID_NP */
@@ -83,17 +87,25 @@ static inline my_thread_os_id_t my_threa
   /* FreeBSD 10.2 */
   return pthread_getthreadid_np();
 #else
+#ifdef __NetBSD__
+  return (int)_lwp_self();
+#else
 #ifdef HAVE_INTEGER_PTHREAD_SELF
+#  ifdef __DragonFly__
+  return syscall(SYS_lwp_gettid);
+#  else
   /* Unknown platform, fallback. */
   return pthread_self();
+#  endif /* __DragonFly__ */
 #else
   /* Feature not available. */
   return 0;
 #endif /* HAVE_INTEGER_PTHREAD_SELF */
+#endif /* __NetBSD__ */
 #endif /* HAVE_PTHREAD_GETTHREADID_NP */
 #endif /* _WIN32 */
 #endif /* HAVE_SYS_GETTID */
-#endif /* HAVE_SYS_THREAD_SELFID */
+#endif /* HAVE_PTHREAD_THREADID_NP */
 }
 
 #endif /* MY_THREAD_OS_ID_INCLUDED */
