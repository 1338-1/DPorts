--- sapi/apache2handler/config.m4.orig	2013-12-10 19:32:43.000000000 +0000
+++ sapi/apache2handler/config.m4	2013-12-13 21:55:54.331235888 +0000
@@ -67,7 +67,7 @@ if test "$PHP_APXS2" != "no"; then
   fi
 
   APXS_LIBEXECDIR='$(INSTALL_ROOT)'`$APXS -q LIBEXECDIR`
-  if test -z `$APXS -q SYSCONFDIR`; then
+  if true; then
     INSTALL_IT="\$(mkinstalldirs) '$APXS_LIBEXECDIR' && \
                  $APXS -S LIBEXECDIR='$APXS_LIBEXECDIR' \
                        -i -n php5"
