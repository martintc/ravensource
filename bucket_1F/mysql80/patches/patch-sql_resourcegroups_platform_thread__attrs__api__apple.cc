--- sql/resourcegroups/platform/thread_attrs_api_apple.cc.orig	2022-09-13 16:15:16 UTC
+++ sql/resourcegroups/platform/thread_attrs_api_apple.cc
@@ -85,7 +85,11 @@ bool set_thread_priority(int, my_thread_
 uint32_t num_vcpus_using_affinity() { return 0; }
 
 uint32_t num_vcpus_using_config() {
+#ifdef __APPLE__
   int name[2] = {CTL_HW, HW_AVAILCPU};
+#else
+  int name[2] = {CTL_HW, HW_NCPU};
+#endif
   int ncpu;
 
   size_t size = sizeof(ncpu);
