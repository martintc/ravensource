--- src/sys.h.orig	2022-10-09 12:16:55 UTC
+++ src/sys.h
@@ -48,6 +48,10 @@
 #include <sys/types.h>
 #endif
 
+#ifdef __sun__
+#include <sys/types.h>
+#endif
+
 #if !defined(__attribute__) && (defined(__cplusplus) || !defined(__GNUC__)  || __GNUC__ == 2 && __GNUC_MINOR__ < 8)
 # define __attribute__(A)
 #endif
@@ -127,13 +131,4 @@ typedef unsigned int	u_int32_t;
 #define	REGEX		/* Use POSIX.2 regular expression functions */
 #undef	REGEXP		/* Use UNIX V8 regular expression functions */
 
-#if defined(__sun)
-extern int tgetent(char *, const char *);
-extern int tgetflag(char *);
-extern int tgetnum(char *);
-extern int tputs(const char *, int, int (*)(int));
-extern char* tgoto(const char*, int, int);
-extern char* tgetstr(char*, char**);
-#endif
-
 #endif /* _h_sys */
