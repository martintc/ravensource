--- src/wayland-os.h.orig	2019-03-21 00:55:25 UTC
+++ src/wayland-os.h
@@ -36,7 +36,7 @@ ssize_t
 wl_os_recvmsg_cloexec(int sockfd, struct msghdr *msg, int flags);
 
 int
-wl_os_epoll_create_cloexec(void);
+wl_os_kqueue_create_cloexec(void);
 
 int
 wl_os_accept_cloexec(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
