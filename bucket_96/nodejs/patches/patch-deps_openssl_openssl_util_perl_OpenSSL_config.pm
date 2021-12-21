--- deps/openssl/openssl/util/perl/OpenSSL/config.pm.orig	2021-12-17 21:21:07 UTC
+++ deps/openssl/openssl/util/perl/OpenSSL/config.pm
@@ -744,6 +744,7 @@ EOF
       [ 'sparc64-.*-.*bsd.*',     { target => "BSD-sparc64" } ],
       [ 'ia64-.*-.*bsd.*',        { target => "BSD-ia64" } ],
       [ 'x86_64-.*-dragonfly.*',  { target => "BSD-x86_64" } ],
+      [ 'x86_64-.*-*bsd.*',       { target => "BSD-x86_64" } ],
       [ 'amd64-.*-.*bsd.*',       { target => "BSD-x86_64" } ],
       [ '.*86.*-.*-.*bsd.*',
         sub {
