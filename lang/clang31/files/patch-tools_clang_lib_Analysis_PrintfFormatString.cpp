
$FreeBSD: lang/clang31/files/patch-tools_clang_lib_Analysis_PrintfFormatString.cpp 303039 2012-08-23 21:02:09Z jkim $

--- tools/clang/lib/Analysis/PrintfFormatString.cpp.orig
+++ tools/clang/lib/Analysis/PrintfFormatString.cpp
@@ -192,11 +192,20 @@
     case '@': k = ConversionSpecifier::ObjCObjArg; break;
     // Glibc specific.
     case 'm': k = ConversionSpecifier::PrintErrno; break;
+    // FreeBSD format extensions
+    case 'b': k = ConversionSpecifier::bArg; break; /* check for int and then char * */
+    case 'r': k = ConversionSpecifier::xArg; break;
+    case 'y': k = ConversionSpecifier::iArg; break;
+    case 'D': k = ConversionSpecifier::DArg; break; /* check for u_char * pointer and a char * string */
+
   }
   PrintfConversionSpecifier CS(conversionPosition, k);
   FS.setConversionSpecifier(CS);
   if (CS.consumesDataArgument() && !FS.usesPositionalArg())
     FS.setArgIndex(argIndex++);
+  // FreeBSD extension
+  if (k == ConversionSpecifier::bArg || k == ConversionSpecifier::DArg)
+    argIndex++;
 
   if (k == ConversionSpecifier::InvalidSpecifier) {
     // Assume the conversion takes one argument.
