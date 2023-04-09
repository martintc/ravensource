--- src/plugins/platforms/eglfs/deviceintegration/eglfs_kms/qeglfskmsgbmdevice.cpp.orig	2023-03-14 08:29:43 UTC
+++ src/plugins/platforms/eglfs/deviceintegration/eglfs_kms/qeglfskmsgbmdevice.cpp
@@ -13,6 +13,10 @@
 
 #define ARRAY_LENGTH(a) (sizeof (a) / sizeof (a)[0])
 
+#ifndef O_CLOEXEC
+#define O_CLOEXEC 0
+#endif
+
 QT_BEGIN_NAMESPACE
 
 Q_DECLARE_LOGGING_CATEGORY(qLcEglfsKmsDebug)
