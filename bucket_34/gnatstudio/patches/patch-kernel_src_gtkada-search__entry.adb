--- kernel/src/gtkada-search_entry.adb.orig	2021-06-18 05:08:58 UTC
+++ kernel/src/gtkada-search_entry.adb
@@ -21,13 +21,13 @@ with Gtk.Style_Context;  use Gtk.Style_C
 with Gtk.Widget;         use Gtk.Widget;
 with Gtkada.Handlers;    use Gtkada.Handlers;
 with GPS.Intl;           use GPS.Intl;
+with Gtk.Main;
 
 package body Gtkada.Search_Entry is
 
    procedure On_Clear_Entry
-      (Self  : access Gtk_Entry_Record'Class;
-       Pos   : Gtk_Entry_Icon_Position;
-       Event : Gdk_Event);
+      (Self : access Gtk_Entry_Record'Class;
+       Pos  : Gtk_Entry_Icon_Position);
    --  Called when the user presses the "clear" icon
 
    procedure On_Changed (Self : access Gtk_Widget_Record'Class);
@@ -39,14 +39,14 @@ package body Gtkada.Search_Entry is
 
    function Get_Icon_Position
      (Self   : access Gtkada_Search_Entry_Record'Class;
-      Event  : Gdk_Event_Button) return Gtk_Entry_Icon_Position
+      Event  : Gdk_Event) return Gtk_Entry_Icon_Position
    is
       Alloc : Gtk_Allocation;
       Rect  : Gdk_Rectangle;
       X, Y  : Gint;
    begin
       Self.Get_Allocation (Alloc);
-      Get_Position (Event.Window, X, Y);
+      Get_Position (Get_Window (Event), X, Y);
 
       Self.Get_Icon_Area (Gtk_Entry_Icon_Primary, Rect);
 
@@ -62,14 +62,13 @@ package body Gtkada.Search_Entry is
    --------------------
 
    procedure On_Clear_Entry
-      (Self  : access Gtk_Entry_Record'Class;
-       Pos   : Gtk_Entry_Icon_Position;
-       Event : Gdk_Event)
+      (Self : access Gtk_Entry_Record'Class;
+       Pos  : Gtk_Entry_Icon_Position)
    is
       pragma Unreferenced (Pos);  --  unreliable with gtk+ 3.8
    begin
-      if Gtkada_Search_Entry (Self).Get_Icon_Position (Event.Button) =
-        Gtk_Entry_Icon_Secondary
+      if Gtkada_Search_Entry (Self).Get_Icon_Position (
+        Gtk.Main.Get_Current_Event) = Gtk_Entry_Icon_Secondary
       then
          Self.Set_Text ("");
 
