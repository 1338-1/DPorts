
$FreeBSD: net/l2tpd/files/patch-aaa.h 300897 2012-07-14 14:29:18Z beat $

--- aaa.h
+++ aaa.h
@@ -46,7 +46,6 @@
 };
 
 extern struct lns *get_lns (struct tunnel *);
-extern struct addr_ent *uaddr[];
 extern unsigned int get_addr (struct iprange *);
 extern void reserve_addr (unsigned int);
 extern void unreserve_addr (unsigned int);
