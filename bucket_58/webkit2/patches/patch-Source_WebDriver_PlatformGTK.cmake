--- Source/WebDriver/PlatformGTK.cmake.orig	2023-02-20 09:22:19 UTC
+++ Source/WebDriver/PlatformGTK.cmake
@@ -5,6 +5,7 @@ add_definitions(-DLIBEXECDIR="${CMAKE_IN
 list(APPEND WebDriver_SYSTEM_INCLUDE_DIRECTORIES
     "${GLIB_INCLUDE_DIRS}"
     "${LIBSOUP_INCLUDE_DIRS}"
+    "${ICU_INCLUDE_DIRS}"
 )
 
 list(APPEND WebDriver_SOURCES
