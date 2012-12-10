
$FreeBSD: ports/audio/flite/files/patch-src-audio-au_sun.c,v 1.2 2012/11/17 05:54:31 svnexp Exp $

--- src/audio/au_sun.c.orig
+++ src/audio/au_sun.c
@@ -45,6 +45,7 @@
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <errno.h>
+#include <sys/ioctl.h>
 #include <sys/filio.h>
 #include <sys/audioio.h>
 #include "cst_string.h"
@@ -76,7 +77,11 @@ cst_audiodev *audio_open_sun(int sps, in
 	    cst_error();
 	}
     }
+#ifdef __OpenBSD__
+    AUDIO_INITINFO(&ainfo);
+#else
     ioctl(fd,AUDIO_GETINFO,&ainfo);
+#endif
 
     switch (fmt)
     {
