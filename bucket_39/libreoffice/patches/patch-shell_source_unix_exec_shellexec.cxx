--- shell/source/unix/exec/shellexec.cxx.orig	2023-07-07 16:45:40 UTC
+++ shell/source/unix/exec/shellexec.cxx
@@ -189,7 +189,7 @@ void SAL_CALL ShellExec::execute( const
         aBuffer.append(" --");
 #else
         // Just use xdg-open on non-Mac
-        aBuffer.append("xdg-open");
+        aBuffer.append("%%LOCALBASE%%/bin/xdg-open");
 #endif
         aBuffer.append(" ");
         escapeForShell(aBuffer, OUStringToOString(aURL, osl_getThreadTextEncoding()));
