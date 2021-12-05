--- lib/mkmf.rb.orig	2021-11-24 11:12:15 UTC
+++ lib/mkmf.rb
@@ -240,7 +240,7 @@ module MakeMakefile
   end
   $extmk ||= false
   if not $extmk and File.exist?(($hdrdir = RbConfig::CONFIG["rubyhdrdir"]) + "/ruby/ruby.h")
-    $topdir = $hdrdir
+    $topdir = $hdrdir + "/" + "#{CONFIG['arch']}/ruby/"
     $top_srcdir = $hdrdir
     $arch_hdrdir = RbConfig::CONFIG["rubyarchhdrdir"]
   elsif File.exist?(($hdrdir = ($top_srcdir ||= topdir) + "/include")  + "/ruby.h")
