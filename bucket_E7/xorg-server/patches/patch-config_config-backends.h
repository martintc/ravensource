--- config/config-backends.h.orig	2023-10-25 01:40:28 UTC
+++ config/config-backends.h
@@ -44,3 +44,8 @@ void config_hal_fini(void);
 int config_wscons_init(void);
 void config_wscons_fini(void);
 #endif
+
+#ifdef CONFIG_DEVD
+int config_devd_init(void);
+void config_devd_fini(void);
+#endif
