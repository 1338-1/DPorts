$FreeBSD: audio/gsi/files/patch-lib::gsif::io.c 300895 2012-07-14 12:56:14Z beat $

--- lib/gsif/io.c.orig	Sat Jan 10 22:22:35 2004
+++ lib/gsif/io.c	Sat Jan 10 22:21:32 2004
@@ -80,7 +80,7 @@
 	fint = gsif_swap_int16(i);
 	status = write (fd, &fint, 2);
 #else
-	fint = val;
+	fint = i;
 	status = write (fd, &fint, 2);
 #endif
 	if (status != 2) (*s) = status;
