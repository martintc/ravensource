--- src/command.c.orig	2020-06-10 21:33:34 UTC
+++ src/command.c
@@ -114,6 +114,9 @@ int thread_rl_RetCode = -1; /* return co
 
 #ifndef _WIN32
 # include "help.h"
+# if defined __FreeBSD__ || defined __DragonFly__
+# include <sys/wait.h>
+# endif
 #endif
 
 #ifdef _WIN32
