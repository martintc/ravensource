.if ${OPSYS} == FreeBSD && ${OSVERSION} > 1100000
CFLAGS+=	-DMAP_NORESERVE=0
.endif
