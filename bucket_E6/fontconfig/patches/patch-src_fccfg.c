--- src/fccfg.c.orig	2018-02-04 11:01:46 UTC
+++ src/fccfg.c
@@ -2654,9 +2654,8 @@ FcConfigFileInfoIterGet (FcConfig		*conf
     if (name)
 	*name = FcStrdup (r->name && r->name[0] ? r->name : (const FcChar8 *) "fonts.conf");
     if (description)
-	*description = FcStrdup (!r->description ? _("No description") :
-				 dgettext (r->domain ? (const char *) r->domain : GETTEXT_PACKAGE "-conf",
-					   (const char *) r->description));
+	*description = FcStrdup (!r->description ? "No description" :
+					   (const char *) r->description);
     if (enabled)
 	*enabled = r->enabled;
 
