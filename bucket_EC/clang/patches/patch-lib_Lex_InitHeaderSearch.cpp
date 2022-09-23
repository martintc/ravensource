--- lib/Lex/InitHeaderSearch.cpp.orig	2022-09-20 06:05:50 UTC
+++ lib/Lex/InitHeaderSearch.cpp
@@ -234,7 +234,6 @@ void InitHeaderSearch::AddDefaultCInclud
   if (HSOpts.UseStandardSystemIncludes) {
     switch (os) {
     case llvm::Triple::CloudABI:
-    case llvm::Triple::FreeBSD:
     case llvm::Triple::NetBSD:
     case llvm::Triple::OpenBSD:
     case llvm::Triple::NaCl:
@@ -413,8 +412,15 @@ void InitHeaderSearch::AddDefaultCPlusPl
       break;
     }
     break;
+  case llvm::Triple::FreeBSD:
+    AddPath("@RAVEN_GXX_HEADERS_DIR@", CXXSystem, false);
+    AddPath("@RAVEN_GXX_HEADERS_DIR@/backward", CXXSystem, false);
+    AddPath("@RAVEN_GXX_HEADERS_DIR@/" + triple.getTriple(), CXXSystem, false);
+    break;
   case llvm::Triple::DragonFly:
-    AddPath("/usr/include/c++/5.0", CXXSystem, false);
+    AddPath("@RAVEN_GXX_HEADERS_DIR@", CXXSystem, false);
+    AddPath("@RAVEN_GXX_HEADERS_DIR@/backward", CXXSystem, false);
+    AddPath("@RAVEN_GXX_HEADERS_DIR@/" + triple.getTriple(), CXXSystem, false);
     break;
   case llvm::Triple::Minix:
     AddGnuCPlusPlusIncludePaths("/usr/gnu/include/c++/4.4.3",
