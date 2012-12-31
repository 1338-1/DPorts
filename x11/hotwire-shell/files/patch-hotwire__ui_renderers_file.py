
$FreeBSD: ports/x11/hotwire-shell/files/patch-hotwire__ui_renderers_file.py,v 1.2 2012/11/17 06:03:16 svnexp Exp $

--- hotwire_ui/renderers/file.py.orig
+++ hotwire_ui/renderers/file.py
@@ -245,7 +245,10 @@
                 menuitem = gtk.ImageMenuItem(_('Edit with %s') % (prefeditor.name,))
                 menuitem.connect('activate', self.__on_edit_activated, self.context.get_cwd(), prefeditor, fobj.path)
                 pbcache = PixbufCache.getInstance()
-                pixbuf = pbcache.get(prefeditor.icon, size=16, trystock=True, stocksize=gtk.ICON_SIZE_MENU)
+		if prefeditor.icon:
+	                pixbuf = pbcache.get(prefeditor.icon, size=16, trystock=True, stocksize=gtk.ICON_SIZE_MENU)
+		else:
+			pixbuf = None
                 if pixbuf:
                     img = gtk.image_new_from_pixbuf(pixbuf)
                     menuitem.set_property('image', img)
