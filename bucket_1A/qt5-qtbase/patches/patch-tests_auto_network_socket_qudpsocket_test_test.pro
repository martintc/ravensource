--- tests/auto/network/socket/qudpsocket/test/test.pro.orig	2020-05-11 08:15:08 UTC
+++ tests/auto/network/socket/qudpsocket/test/test.pro
@@ -17,6 +17,7 @@ win32:debug_and_release {
 }
 
 TARGET = tst_qudpsocket
+solaris: LIBS+= -lsocket
 
 # Only on Linux until 'echo' has been added to docker-compose-for-{windows,macOS}.yml and tested
 linux {
