From cc9bc2387fe19d6cb130460defe52ee8ecefe968 Mon Sep 17 00:00:00 2001
From: =?UTF-8?q?=C4=90o=C3=A0n=20Tr=E1=BA=A7n=20C=C3=B4ng=20Danh?=
 <congdanhqx@gmail.com>
Date: Tue, 29 Nov 2022 07:34:17 +0700
Subject: [PATCH] stl/tuple: change uarg##N to internal linkage

8b6a9c2 (std::tuple support (Resolving #103) (#104), 2021-03-11) put
uarg##N in all translation units, which includes
boost/phoenix/stl/tuple.hpp or boost/phoenix/stl.hpp, with external
linkage. Thus, we'll run into below error:

> multiple definition of `boost::phoenix::placeholders::uarg1'

Change it to internal linkage.
---
 include/boost/phoenix/stl/tuple.hpp | 2 +-
 1 file changed, 1 insertion(+), 1 deletion(-)

--- boost/phoenix/stl/tuple.hpp.orig	2023-08-08 21:02:54 UTC
+++ boost/phoenix/stl/tuple.hpp
@@ -110,7 +110,7 @@ namespace boost { namespace phoenix {
     namespace placeholders {
         #define BOOST_PP_LOCAL_LIMITS (1, BOOST_PHOENIX_ARG_LIMIT)
         #define BOOST_PP_LOCAL_MACRO(N)                                                \
-            auto uarg##N =                                                             \
+            const auto uarg##N =                                                       \
             boost::phoenix::get_<(N)-1>(boost::phoenix::placeholders::arg1);
         #include BOOST_PP_LOCAL_ITERATE()
     }
