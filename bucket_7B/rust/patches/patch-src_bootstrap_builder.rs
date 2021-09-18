--- src/bootstrap/builder.rs.orig	2021-09-06 18:42:35 UTC
+++ src/bootstrap/builder.rs
@@ -1148,12 +1148,13 @@ impl<'a> Builder<'a> {
                 rustflags.arg("-Zosx-rpath-install-name");
                 Some("-Wl,-rpath,@loader_path/../lib")
             } else if !target.contains("windows") {
-                Some("-Wl,-rpath,$ORIGIN/../lib")
+                Some("-Wl,-rpath,$ORIGIN/../lib:@OPENSSLLIB@")
             } else {
                 None
             };
             if let Some(rpath) = rpath {
-                rustflags.arg(&format!("-Clink-args={}", rpath));
+                rustflags.arg(&format!("-Clink-arg={}", "-Wl,-z,origin"));
+                rustflags.arg(&format!("-Clink-arg={}", rpath));
             }
         }
 
