--- nmap.cc.orig	2020-10-09 22:18:58 UTC
+++ nmap.cc
@@ -69,6 +69,7 @@
 #include <shlobj.h>
 #endif
 
+#include <getopt.h>
 #include "nmap.h"
 #include "osscan.h"
 #include "scan_engine.h"
