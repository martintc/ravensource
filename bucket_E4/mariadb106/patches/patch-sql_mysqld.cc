--- sql/mysqld.cc.orig	2023-11-08 15:01:59 UTC
+++ sql/mysqld.cc
@@ -4625,8 +4625,9 @@ static void init_ssl()
         sql_print_warning("SSL error: %s",buf);
       }
     }
-    else
+    else {
       ERR_remove_state(0);
+    }
   }
   else
   {
