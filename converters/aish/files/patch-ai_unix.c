$FreeBSD: converters/aish/files/patch-ai_unix.c 340725 2014-01-22 17:40:44Z mat $

--- ai_unix.c.orig	Fri Jun  7 12:59:05 2002
+++ ai_unix.c	Fri Jun  7 13:00:49 2002
@@ -15,7 +15,7 @@
 char	*ptr;
 {
 #ifdef BZ_BSD
-	return	bzero( ptr, len );
+	bzero( ptr, len );
 #else
 	return	memset( ptr, '\0', len );
 #endif
