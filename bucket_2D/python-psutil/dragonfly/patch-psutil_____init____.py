--- psutil/__init__.py.orig	2019-04-11 22:47:53 UTC
+++ psutil/__init__.py
@@ -82,6 +82,7 @@ from ._common import LINUX
 from ._common import MACOS
 from ._common import NETBSD  # NOQA
 from ._common import OPENBSD  # NOQA
+from ._common import DRAGONFLY # NOQA
 from ._common import OSX  # deprecated alias
 from ._common import POSIX  # NOQA
 from ._common import SUNOS
@@ -201,7 +202,7 @@ __all__ = [
     "POWER_TIME_UNKNOWN", "POWER_TIME_UNLIMITED",
 
     "BSD", "FREEBSD", "LINUX", "NETBSD", "OPENBSD", "MACOS", "OSX", "POSIX",
-    "SUNOS", "WINDOWS", "AIX",
+    "SUNOS", "WINDOWS", "AIX", "DRAGONFLY",
 
     # classes
     "Process", "Popen",
