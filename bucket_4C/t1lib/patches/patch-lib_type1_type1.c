--- lib/type1/type1.c.orig	2007-12-23 16:49:42.000000000 +0100
+++ lib/type1/type1.c	2019-06-06 15:20:11.590036000 +0200
@@ -1012,6 +1012,7 @@
   double nextdtana = 0.0;   /* tangent of post-delta against horizontal line */ 
   double nextdtanb = 0.0;   /* tangent of post-delta against vertical line */ 
   
+  if (ppoints == NULL || numppoints < 1) Error0v("FindStems: No previous point!\n");
  
   /* setup default hinted position */
   ppoints[numppoints-1].ax     = ppoints[numppoints-1].x;
@@ -1289,7 +1290,7 @@
 static int DoRead(CodeP)
   int *CodeP;
 {
-  if (strindex >= CharStringP->len) return(FALSE); /* end of string */
+  if (!CharStringP || strindex >= CharStringP->len) return(FALSE); /* end of string */
   /* We handle the non-documented Adobe convention to use lenIV=-1 to
      suppress charstring encryption. */
   if (blues->lenIV==-1) {
@@ -1700,6 +1701,7 @@
   long pindex = 0;
   
   /* compute hinting for previous segment! */
+  if (ppoints == NULL || numppoints < 2 ) Error0i("RLineTo: No previous point!\n");
   FindStems( currx, curry, currx-ppoints[numppoints-2].x, curry-ppoints[numppoints-2].y, dx, dy);
 
   /* Allocate a new path point and pre-setup data */
@@ -1728,6 +1730,7 @@
   long pindex = 0;
   
   /* compute hinting for previous point! */
+  if (ppoints == NULL || numppoints < 2) Error0i("RRCurveTo: No previous point!\n");
   FindStems( currx, curry, currx-ppoints[numppoints-2].x, curry-ppoints[numppoints-2].y, dx1, dy1);
 
   /* Allocate three new path points and pre-setup data */
@@ -1786,7 +1789,9 @@
   long tmpind;
   double deltax = 0.0;
   double deltay = 0.0;
-  
+ 
+  if (ppoints == NULL || numppoints < 1) Error0i("DoClosePath: No previous point!");
+ 
   /* If this ClosePath command together with the starting point of this
      path completes to a segment aligned to a stem, we would miss
      hinting for this point. --> Check and explicitly care for this! */
@@ -1801,6 +1806,7 @@
     deltax = ppoints[i].x - ppoints[numppoints-1].x;
     deltay = ppoints[i].y - ppoints[numppoints-1].y;
 
+    if (ppoints == NULL || numppoints <= i + 1) Error0i("DoClosePath: No previous point!");
     /* save nummppoints and reset to move point */
     tmpind = numppoints;
     numppoints = i + 1;
@@ -1903,6 +1909,7 @@
     FindStems( currx, curry, 0, 0, dx, dy);
   }
   else {
+    if (ppoints == NULL || numppoints < 2) Error0i("RMoveTo: No previous point!\n");
     FindStems( currx, curry, ppoints[numppoints-2].x, ppoints[numppoints-2].y, dx, dy);
   }
   
@@ -2152,6 +2159,7 @@
   DOUBLE cx, cy;
   DOUBLE ex, ey;
 
+  if (ppoints == NULL || numppoints < 8) Error0v("FlxProc: No previous point!");
 
   /* Our PPOINT list now contains 7 moveto commands which
      are about to be consumed by the Flex mechanism. --> Remove these
@@ -2321,6 +2329,7 @@
 /*   Returns currentpoint on stack          */
 static void FlxProc2()
 {
+  if (ppoints == NULL || numppoints < 1) Error0v("FlxProc2: No previous point!");
   /* Push CurrentPoint on fake PostScript stack */
   PSFakePush( ppoints[numppoints-1].x);
   PSFakePush( ppoints[numppoints-1].y);
