--- scripts/mysql_config.sh.orig	2021-08-03 14:48:41 UTC
+++ scripts/mysql_config.sh
@@ -87,7 +87,9 @@ fi
 
 # Create options 
 libs="-L$pkglibdir @RPATH_OPTION@ @LIBS_FOR_CLIENTS@"
+libs="$libs -L%%LOCALBASE%%/lib "
 embedded_libs="-L$pkglibdir @RPATH_OPTION@ @EMB_LIBS_FOR_CLIENTS@"
+embedded_libs="$embedded_libs -L%%LOCALBASE%%/lib "
 
 include="-I$pkgincludedir"
 if [ "$basedir" != "/usr" ]; then
