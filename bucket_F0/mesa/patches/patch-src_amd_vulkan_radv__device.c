- Define CLOCK_MONOTONIC_RAW if missing

--- src/amd/vulkan/radv_device.c.orig	2023-08-16 17:19:13 UTC
+++ src/amd/vulkan/radv_device.c
@@ -443,6 +443,14 @@ radv_parse_force_vrs_config_file(const c
 
 #define BUF_LEN ((10 * (sizeof(struct inotify_event) + NAME_MAX + 1)))
 
+#ifndef CLOCK_MONOTONIC_RAW
+# ifdef CLOCK_MONOTONIC_FAST
+#  define CLOCK_MONOTONIC_RAW CLOCK_MONOTONIC_FAST
+# else
+#  define CLOCK_MONOTONIC_RAW CLOCK_MONOTONIC
+# endif
+#endif
+
 static int
 radv_notifier_thread_run(void *data)
 {
