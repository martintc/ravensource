Seems to be needed by NetBSD shell to get past the fact no files are generated.

--- solenv/gbuild/Gallery.mk.orig	2023-01-25 14:26:33 UTC
+++ solenv/gbuild/Gallery.mk
@@ -27,7 +27,7 @@ $(call gb_Helper_abbreviate_dirs,\
 			--filenames $(call gb_Helper_make_url,$$RESPONSEFILE) \
 			-env:UserInstallation=$(call gb_Helper_make_url,$(call gb_Gallery_get_workdir,$(2))/user),\
 		$@.log \
-	) && \
+	) ||: true && \
 	rm $$RESPONSEFILE && \
 	touch $@ \
 )
