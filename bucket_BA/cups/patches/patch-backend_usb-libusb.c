--- backend/usb-libusb.c.orig	2023-06-13 13:00:48 UTC
+++ backend/usb-libusb.c
@@ -1466,7 +1466,7 @@ open_device(usb_printer_t *printer,	/* I
   * works without the module attached.
   */
 
-  errcode = libusb_kernel_driver_active(printer->handle, printer->iface);
+  errcode = 0;
   if (errcode == 0)
     printer->usblp_attached = 0;
   else if (errcode == 1)
