--- src/google/protobuf/compiler/command_line_interface.cc.orig	2023-05-08 16:48:50 UTC
+++ src/google/protobuf/compiler/command_line_interface.cc
@@ -70,7 +70,7 @@
 
 #if defined(__APPLE__)
 #include <mach-o/dyld.h>
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
 #include <sys/sysctl.h>
 #endif
 
@@ -220,7 +220,7 @@ bool GetProtocAbsolutePath(std::string*
     realpath(dirtybuffer, buffer);
     len = strlen(buffer);
   }
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
   char buffer[PATH_MAX];
   size_t len = PATH_MAX;
   int mib[4] = {CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1};
