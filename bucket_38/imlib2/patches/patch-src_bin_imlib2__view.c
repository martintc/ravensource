$NetBSD: patch-src_bin_imlib2__view.c,v 1.1 2020/02/20 15:14:57 nia Exp $

Include sys/time.h for timeval.

--- src/bin/imlib2_view.c.orig	2021-09-16 10:32:41 UTC
+++ src/bin/imlib2_view.c
@@ -2,6 +2,7 @@
 
 #include <X11/Xlib.h>
 #include <X11/keysym.h>
+#include <sys/time.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <errno.h>
