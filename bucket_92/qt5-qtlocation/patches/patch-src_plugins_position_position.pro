--- src/plugins/position/position.pro.orig	2022-08-16 17:37:28 UTC
+++ src/plugins/position/position.pro
@@ -2,8 +2,8 @@ TEMPLATE = subdirs
 
 QT_FOR_CONFIG += positioning-private
 
-linux|freebsd|openbsd|netbsd:qtHaveModule(dbus):SUBDIRS += geoclue
-linux|freebsd|openbsd|netbsd:qtHaveModule(dbus):SUBDIRS += geoclue2
+linux|freebsd|openbsd|netbsd|midnightbsd|dragonfly:qtHaveModule(dbus):SUBDIRS += geoclue
+linux|freebsd|openbsd|netbsd|midnightbsd|dragonfly:qtHaveModule(dbus):SUBDIRS += geoclue2
 qtConfig(gypsy):SUBDIRS += gypsy
 qtConfig(winrt_geolocation):SUBDIRS += winrt
 qtHaveModule(simulator):SUBDIRS += simulator
