--- glib/tests/utils.c.orig	2023-08-31 11:08:59 UTC
+++ glib/tests/utils.c
@@ -848,7 +848,7 @@ test_xdg_dirs (void)
 
   xdg = (gchar *)g_getenv ("XDG_CONFIG_DIRS");
   if (!xdg)
-    xdg = "/etc/xdg";
+    xdg = "/usr/local/etc/xdg:/etc/xdg";
 
   dirs = g_get_system_config_dirs ();
 
