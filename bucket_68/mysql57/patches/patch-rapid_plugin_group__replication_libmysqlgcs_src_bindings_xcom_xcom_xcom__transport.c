$NetBSD: patch-rapid_plugin_group__replication_libmysqlgcs_src_bindings_xcom_xcom_xcom__transport.c,v 1.1 2017/03/16 15:46:22 maya Exp $

Workaround netbsd prototype of xdrproc_t being 2 arguments.

--- rapid/plugin/group_replication/libmysqlgcs/src/bindings/xcom/xcom/xcom_transport.c.orig	2023-06-21 13:02:02 UTC
+++ rapid/plugin/group_replication/libmysqlgcs/src/bindings/xcom/xcom/xcom_transport.c
@@ -360,7 +360,11 @@ int apply_xdr(xcom_proto x_proto, gpoint
 	*/
 	if (xdr.x_ops){
 		xdr.x_public = (caddr_t)&x_proto; /* Supply protocol version in user field of xdr */
+#ifdef __NetBSD__
+		s = xdrfunc(&xdr, xdrdata);
+#else
 		s = xdrfunc(&xdr, xdrdata, 0);
+#endif
 	}
 	xdr_destroy(&xdr);
 	return s;
@@ -594,7 +598,11 @@ xdr_proto_sizeof (xcom_proto x_proto, xd
     is the case). This will keep this code cross-platform
     and cross-version compatible.
   */
+#ifdef __NetBSD__
+  stat = func (&x, data);
+#else
   stat = func (&x, data, 0);
+#endif
   free (x.x_private);
   // x_handy is int type for old XDR
   return stat == TRUE ? (uint64_t)x.x_handy : 0;
