--- cmake/install_layout.cmake.orig	2023-08-10 19:55:48 UTC
+++ cmake/install_layout.cmake
@@ -128,8 +128,8 @@ SET(INSTALL_SUPPORTFILESDIR_STANDALONE
 SET(INSTALL_MYSQLDATADIR_STANDALONE     "data")
 
 SET(INSTALL_UNIX_ADDRDIR_STANDALONE     "/tmp/mysql.sock")
-SET(INSTALL_PAMDIR_STANDALONE           "share")
-SET(INSTALL_PAMDATADIR_STANDALONE       "share")
+SET(INSTALL_PAMDIR_STANDALONE           "lib/mysql/security")
+SET(INSTALL_PAMDATADIR_STANDALONE       "etc/mariadb")
 #
 # RPM layout
 #
