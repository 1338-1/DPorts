--- bitap.c.orig	1992-01-17 22:00:15.000000000 +0100
+++ bitap.c	2011-11-27 13:33:41.000000000 +0100
@@ -13,6 +13,8 @@
 
 #include "agrep.h"
 
+#include <unistd.h>
+
 extern unsigned Init1, D_endpos, endposition, Init[], Mask[], Bit[];
 extern int DELIMITER, FILENAMEONLY, D_length, I, AND, REGEX, JUMP, INVERSE; 
 extern char D_pattern[];
@@ -22,7 +24,7 @@
 
 /* bitap dispatches job */
 
-bitap(old_D_pat, Pattern, fd, M, D)
+void bitap(old_D_pat, Pattern, fd, M, D)
 char old_D_pat[], *Pattern;  int fd, M, D;  
 {
 char c;  
@@ -143,7 +145,7 @@
   return;
 }
 
-fill_buf(fd, buf, record_size)
+int fill_buf(fd, buf, record_size)
 int fd, record_size; unsigned char *buf;
 {
 int num_read=1;
