--- tests/auto/network/access/qnetworkreply/test/test.pro.orig	2022-06-24 10:42:02 UTC
+++ tests/auto/network/access/qnetworkreply/test/test.pro
@@ -14,6 +14,7 @@ TESTDATA += ../empty ../rfc3252.txt ../r
             ../index.html ../smb-file.txt
 
 !android:!winrt: TEST_HELPER_INSTALLS = ../echo/echo
+solaris: LIBS += -lsocket
 
 CONFIG += unsupported/testserver
 QT_TEST_SERVER_LIST = vsftpd apache2 ftp-proxy danted squid
