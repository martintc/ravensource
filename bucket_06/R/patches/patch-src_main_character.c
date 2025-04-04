$NetBSD: patch-src_main_character.c,v 1.5 2021/06/13 13:10:47 wen Exp $

--- src/main/character.c.orig	2023-05-01 22:15:02 UTC
+++ src/main/character.c
@@ -1751,7 +1751,7 @@ attribute_hidden SEXP do_strtrim(SEXP ca
     return s;
 }
 
-static int strtoi(SEXP s, int base)
+static int my_strtoi(SEXP s, int base)
 {
     if(s == NA_STRING || CHAR(s)[0] == '\0') return(NA_INTEGER);
 
@@ -1784,7 +1784,7 @@ attribute_hidden SEXP do_strtoi(SEXP cal
 
     PROTECT(ans = allocVector(INTSXP, n = LENGTH(x)));
     for(i = 0; i < n; i++)
-	INTEGER(ans)[i] = strtoi(STRING_ELT(x, i), base);
+	INTEGER(ans)[i] = my_strtoi(STRING_ELT(x, i), base);
     UNPROTECT(1);
 
     return ans;
