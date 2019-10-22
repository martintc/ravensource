--- vendor/openssl-sys/src/ssl.rs.orig	2019-08-13 08:30:02 UTC
+++ vendor/openssl-sys/src/ssl.rs
@@ -1057,7 +1057,7 @@ extern "C" {
 }
 
 cfg_if! {
-    if #[cfg(ossl110)] {
+    if #[cfg(any(ossl110, libressl291))] {
         extern "C" {
             pub fn TLS_method() -> *const SSL_METHOD;
 
