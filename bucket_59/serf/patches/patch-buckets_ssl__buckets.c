--- buckets/ssl_buckets.c.orig	2023-05-18 09:33:55 UTC
+++ buckets/ssl_buckets.c
@@ -52,7 +52,7 @@
 #define APR_ARRAY_PUSH(ary,type) (*((type *)apr_array_push(ary)))
 #endif
 
-#if defined(OPENSSL_VERSION_NUMBER) && OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if defined(OPENSSL_VERSION_NUMBER) && OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
 #define USE_OPENSSL_1_1_API
 #endif
 
