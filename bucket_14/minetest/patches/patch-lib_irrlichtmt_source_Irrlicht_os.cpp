--- lib/irrlichtmt/source/Irrlicht/os.cpp.orig	2023-04-18 01:30:38 UTC
+++ lib/irrlichtmt/source/Irrlicht/os.cpp
@@ -23,7 +23,7 @@
 	#define bswap_16(X) OSReadSwapInt16(&X,0)
 	#define bswap_32(X) OSReadSwapInt32(&X,0)
 	#define bswap_64(X) OSReadSwapInt64(&X,0)
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
 	#include <sys/endian.h>
 	#define bswap_16(X) bswap16(X)
 	#define bswap_32(X) bswap32(X)
