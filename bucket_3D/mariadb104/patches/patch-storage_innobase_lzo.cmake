--- storage/innobase/lzo.cmake.orig	2020-11-01 23:38:10 UTC
+++ storage/innobase/lzo.cmake
@@ -17,12 +17,10 @@ SET(WITH_INNODB_LZO AUTO CACHE STRING
 
 MACRO (MYSQL_CHECK_LZO_STATIC)
   IF (WITH_INNODB_LZO STREQUAL "ON" OR WITH_INNODB_LZO STREQUAL "AUTO")
-    CHECK_INCLUDE_FILES(lzo/lzo1x.h HAVE_LZO_H)
-    CHECK_LIBRARY_EXISTS(liblzo2.a lzo1x_1_compress "" HAVE_LZO_LIB)
-
+    CHECK_LIBRARY_EXISTS(lzo2 lzo1x_1_compress "${LZO_LIBDIR}" HAVE_LZO_LIB)
     IF(HAVE_LZO_LIB AND HAVE_LZO_H)
       ADD_DEFINITIONS(-DHAVE_LZO=1)
-      LINK_LIBRARIES(liblzo2.a)
+      LINK_LIBRARIES(lzo2)
     ELSE()
       IF (WITH_INNODB_LZO STREQUAL "ON")
 	MESSAGE(FATAL_ERROR "Required lzo library is not found")
@@ -33,12 +31,16 @@ ENDMACRO()
 
 MACRO (MYSQL_CHECK_LZO)
   IF (WITH_INNODB_LZO STREQUAL "ON" OR WITH_INNODB_LZO STREQUAL "AUTO")
-    CHECK_INCLUDE_FILES(lzo/lzo1x.h HAVE_LZO_H)
-    CHECK_LIBRARY_EXISTS(lzo2 lzo1x_1_compress "" HAVE_LZO_SHARED_LIB)
-
+    find_path(LZO_INCLUDE NAMES lzo/lzo1x.h)
+    find_library(LZO_LIBRARY NAMES lzo2)
+    get_filename_component(LZO_LIBDIR ${LZO_LIBRARY} DIRECTORY)
+    IF (LZO_INCLUDE)
+      SET(HAVE_LZO_H 1)
+    ENDIF()
+    CHECK_LIBRARY_EXISTS(lzo2 lzo1x_1_compress ${LZO_LIBDIR} HAVE_LZO_SHARED_LIB)
     IF(HAVE_LZO_SHARED_LIB AND HAVE_LZO_H)
       ADD_DEFINITIONS(-DHAVE_LZO=1)
-      LINK_LIBRARIES(lzo2)
+      LINK_LIBRARIES(${LZO_LIBRARY})
     ELSE()
       IF (WITH_INNODB_LZO STREQUAL "ON")
 	MESSAGE(FATAL_ERROR "Required lzo library is not found")
