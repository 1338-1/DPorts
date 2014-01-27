$FreeBSD: www/p5-HTTP-Recorder/files/patch-lib_HTTP_Recorder.pm 340725 2014-01-22 17:40:44Z mat $

--- lib/HTTP/Recorder.pm.orig	2012-04-23 22:20:16.000000000 +0800
+++ lib/HTTP/Recorder.pm	2012-04-25 01:11:56.207852080 +0800
@@ -352,11 +352,12 @@
 		return $content;
 	}
 
-    for my $key ($content->query_param) {
-	if ($key =~ /^$prefix-/) {
-	    $content->query_param_delete($key);
-	}
-    }
+    $content =~ s/$prefix-(.*?)\?(.*?)&//g;
+    $content =~ s/$prefix-(.*?)&//g;
+    $content =~ s/$prefix-(.*?)$//g;
+    $content =~ s/&$//g;
+    $content =~ s/\?$//g;
+
     return $content;
 }
 
