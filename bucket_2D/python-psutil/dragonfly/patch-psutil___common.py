--- psutil/_common.py.orig	2019-04-11 22:48:54 UTC
+++ psutil/_common.py
@@ -43,7 +43,7 @@ PY3 = sys.version_info[0] == 3
 __all__ = [
     # constants
     'FREEBSD', 'BSD', 'LINUX', 'NETBSD', 'OPENBSD', 'MACOS', 'OSX', 'POSIX',
-    'SUNOS', 'WINDOWS',
+    'SUNOS', 'WINDOWS', 'DRAGONFLY',
     'ENCODING', 'ENCODING_ERRS', 'AF_INET6',
     # connection constants
     'CONN_CLOSE', 'CONN_CLOSE_WAIT', 'CONN_CLOSING', 'CONN_ESTABLISHED',
@@ -81,7 +81,8 @@ OSX = MACOS  # deprecated alias
 FREEBSD = sys.platform.startswith("freebsd")
 OPENBSD = sys.platform.startswith("openbsd")
 NETBSD = sys.platform.startswith("netbsd")
-BSD = FREEBSD or OPENBSD or NETBSD
+DRAGONFLY = sys.platform.startswith("dragonfly")
+BSD = FREEBSD or OPENBSD or NETBSD or DRAGONFLY
 SUNOS = sys.platform.startswith(("sunos", "solaris"))
 AIX = sys.platform.startswith("aix")
 
