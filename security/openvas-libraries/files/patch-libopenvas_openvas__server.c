
$FreeBSD: head/security/openvas-libraries/files/patch-libopenvas_openvas__server.c 340725 2014-01-22 17:40:44Z mat $

--- libopenvas/openvas_server.c.orig
+++ libopenvas/openvas_server.c
@@ -32,6 +32,8 @@
 
 #include <glib.h>
 #include <arpa/inet.h>
+#include <netinet/in.h>
+#include <sys/socket.h>
 #include <unistd.h>
 #include <fcntl.h>
 #include <string.h>
