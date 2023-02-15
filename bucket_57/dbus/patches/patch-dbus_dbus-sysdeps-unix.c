--- dbus/dbus-sysdeps-unix.c.orig	2023-02-08 10:30:57 UTC
+++ dbus/dbus-sysdeps-unix.c
@@ -24,6 +24,14 @@
 
 #include <config.h>
 
+#ifdef __sun
+#  if __STDC_VERSION__ - 0 < 199901L
+#define	_XOPEN_SOURCE	500
+#  else
+#define	_XOPEN_SOURCE	600
+#  endif
+#endif
+
 #include "dbus-internals.h"
 #include "dbus-sysdeps.h"
 #include "dbus-sysdeps-unix.h"
