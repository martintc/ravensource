--- sql/mysqld.cc.orig	2020-09-23 12:00:04 UTC
+++ sql/mysqld.cc
@@ -3423,7 +3423,7 @@ int warn_self_signed_ca()
 static int init_ssl()
 {
 #ifdef HAVE_OPENSSL
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
   CRYPTO_malloc_init();
 #else /* OPENSSL_VERSION_NUMBER < 0x10100000L */
   OPENSSL_malloc_init();
