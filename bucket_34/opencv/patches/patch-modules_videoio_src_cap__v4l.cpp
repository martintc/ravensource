--- modules/videoio/src/cap_v4l.cpp.orig	2017-08-03 23:58:23 UTC
+++ modules/videoio/src/cap_v4l.cpp
@@ -226,7 +226,9 @@ make & enjoy!
 #include <sys/ioctl.h>
 
 #ifdef HAVE_CAMV4L2
+#ifdef __linux__
 #include <asm/types.h>          /* for videodev2.h */
+#endif
 #include <linux/videodev2.h>
 #endif
 
