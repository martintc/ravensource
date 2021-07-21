--- plugin/password_validation/validate_password.cc.orig	2021-07-01 07:53:49 UTC
+++ plugin/password_validation/validate_password.cc
@@ -25,6 +25,8 @@
 #include <mysql/plugin_validate_password.h>
 #include <mysql/service_my_plugin_log.h>
 #include <mysql/service_mysql_string.h>
+/* solve clash between libc++ bitset::test() and test macro from my_global.h */
+#undef test
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
