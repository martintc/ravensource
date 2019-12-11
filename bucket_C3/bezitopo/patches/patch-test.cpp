--- test.cpp.orig	2018-12-19 05:21:41 UTC
+++ test.cpp
@@ -147,7 +147,8 @@ void aster(document &doc,int n)
 /* Fill points with asteraceous pattern. Pattern invented by H. Vogel in 1979
    and later by me, not knowing of Vogel. */
 {int i;
- double angle=(sqrt(5)-1)*M_PI;
+ double fred = 5;
+ double angle=(sqrt(fred)-1)*M_PI;
  xy pnt;
  for (i=0;i<n;i++)
      {pnt=xy(cos(angle*i)*sqrt(i+0.5),sin(angle*i)*sqrt(i+0.5));
@@ -159,7 +160,8 @@ void _ellipse(document &doc,int n,double
 /* Skewness is not eccentricity. When skewness=0.01, eccentricity=0.14072. */
 {
   int i;
-  double angle=(sqrt(5)-1)*M_PI;
+  double fred = 5;
+  double angle=(sqrt(fred)-1)*M_PI;
   xy pnt;
   for (i=0;i<n;i++)
   {
@@ -204,11 +206,12 @@ void straightrow(document &doc,int n)
 {
   int i;
   double angle;
+  double dn = n;
   xy pnt;
   for (i=0;i<n;i++)
   {
     angle=(2.0*i/(n-1)-1)*M_PI/6;
-    pnt=xy(0,sqrt(n)*tan(angle));
+    pnt=xy(0,sqrt(dn)*tan(angle));
     doc.pl[1].addpoint(i+1,point(pnt,testsurface(pnt),"test"));
   }
 }
@@ -217,10 +220,11 @@ void lozenge(document &doc,int n)
 // Add points on the short diagonal of a rhombus, then add the two other points.
 {
   xy pnt;
+  double dn = n;
   straightrow(doc,n);
-  pnt=xy(-sqrt(n),0);
+  pnt=xy(-sqrt(dn),0);
   doc.pl[1].addpoint(n+1,point(pnt,testsurface(pnt),"test"));
-  pnt=xy(sqrt(n),0);
+  pnt=xy(sqrt(dn),0);
   doc.pl[1].addpoint(n+2,point(pnt,testsurface(pnt),"test"));
 }
 
