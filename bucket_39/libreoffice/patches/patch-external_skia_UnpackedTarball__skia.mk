--- external/skia/UnpackedTarball_skia.mk.orig	2021-09-21 19:11:56 UTC
+++ external/skia/UnpackedTarball_skia.mk
@@ -41,6 +41,7 @@ skia_patches := \
     fix-warnings.patch.1 \
     disable-freetype-colrv1.1 \
     windows-libraries-system32.patch.1 \
+    jrm-fix.patch
 
 $(eval $(call gb_UnpackedTarball_set_patchlevel,skia,1))
 
