--- client/mysql.cc.orig	2023-08-10 19:55:47 UTC
+++ client/mysql.cc
@@ -61,8 +61,8 @@ static char *server_version= NULL;
 
 extern "C" {
 #if defined(HAVE_CURSES_H) && defined(HAVE_TERM_H)
-#include <curses.h>
-#include <term.h>
+#include <ncurses/curses.h>
+#include <ncurses/term.h>
 #else
 #if defined(HAVE_TERMIOS_H)
 #include <termios.h>
@@ -81,7 +81,7 @@ extern "C" {
 #endif
 #undef SYSV				// hack to avoid syntax error
 #ifdef HAVE_TERM_H
-#include <term.h>
+#include <ncurses/term.h>
 #endif
 #endif
 #endif /* defined(HAVE_CURSES_H) && defined(HAVE_TERM_H) */
