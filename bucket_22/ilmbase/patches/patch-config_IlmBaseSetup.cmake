--- config/IlmBaseSetup.cmake.orig	2021-02-12 16:56:19 UTC
+++ config/IlmBaseSetup.cmake
@@ -48,10 +48,6 @@ set(ILMBASE_OUTPUT_SUBDIR OpenEXR CACHE
 # but is pretty harmless to set globally
 set(CMAKE_INCLUDE_CURRENT_DIR ON)
 
-# Suffix for debug configuration libraries
-# (if you should choose to install those)
-set(CMAKE_DEBUG_POSTFIX "_d" CACHE STRING "Suffix for debug builds")
-
 # Usual cmake option to build shared libraries or not
 option(BUILD_SHARED_LIBS "Build shared library" ON)
 # This allows a "double library" setup, where we compile both
