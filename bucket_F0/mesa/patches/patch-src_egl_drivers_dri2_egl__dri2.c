--- src/egl/drivers/dri2/egl_dri2.c.orig	2020-07-22 20:47:01 UTC
+++ src/egl/drivers/dri2/egl_dri2.c
@@ -1003,11 +1003,13 @@ dri2_setup_screen(_EGLDisplay *disp)
              disp->Extensions.KHR_gl_texture_3D_image = EGL_TRUE;
       }
 #ifdef HAVE_LIBDRM
+# ifndef __DragonFly__
       if (dri2_dpy->image->base.version >= 8 &&
           dri2_dpy->image->createImageFromDmaBufs) {
          disp->Extensions.EXT_image_dma_buf_import = EGL_TRUE;
          disp->Extensions.EXT_image_dma_buf_import_modifiers = EGL_TRUE;
       }
+# endif
 #endif
    }
 
