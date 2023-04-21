--- Source/WTF/wtf/NumberOfCores.cpp.orig	2023-02-20 11:57:19 UTC
+++ Source/WTF/wtf/NumberOfCores.cpp
@@ -31,6 +31,7 @@
 #if OS(DARWIN)
 #include <sys/sysctl.h>
 #elif OS(LINUX) || OS(AIX) || OS(OPENBSD) || OS(NETBSD) || OS(FREEBSD)
+#include <stdio.h> // sscanf
 #include <unistd.h>
 #elif OS(WINDOWS)
 #include <windows.h>
