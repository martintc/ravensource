$NetBSD: patch-store_source_storbase.hxx,v 1.2 2019/08/10 11:41:29 ryoon Exp $

include <cstdlib> for std::free()

--- store/source/storbase.hxx.orig	2023-02-22 19:52:27 UTC
+++ store/source/storbase.hxx
@@ -34,6 +34,7 @@
 
 #include <memory>
 #include <utility>
+#include <cstdlib>
 
 /** @file store common internals.
 */
