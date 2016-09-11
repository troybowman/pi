#include <stdio.h>
#include <CoreText/CoreText.h>

// This is the logic Qt uses to identify monospace fonts (see qtbase/src/platformsupport/fontdatabases/mac/qcoretextfontdatabase.mm.
// It does not correctly identify monospace fonts like Menlo and Monaco for some reason.

//-----------------------------------------------------------------------------
enum font_status_t
{
  FD_FIXEDWIDTH,
  FD_VARWIDTH,
  FD_NOMATCH,
};

//-----------------------------------------------------------------------------
static font_status_t get_font_status(const char *family)
{
  CFMutableDictionaryRef attributes = CFDictionaryCreateMutable(
      kCFAllocatorDefault,
      0,
      &kCFTypeDictionaryKeyCallBacks,
      &kCFTypeDictionaryValueCallBacks);

  CFDictionaryAddValue(
      attributes,
      kCTFontFamilyNameAttribute,
      CFStringCreateWithCString(NULL, family, kCFStringEncodingASCII));

  CTFontDescriptorRef nameOnlyDescriptor = CTFontDescriptorCreateWithAttributes(attributes);
  CFArrayRef matchingFonts = CTFontDescriptorCreateMatchingFontDescriptors(nameOnlyDescriptor, 0);

  if ( matchingFonts == NULL )
    return FD_NOMATCH;

  int numFonts = CFArrayGetCount(matchingFonts);
  for ( int i = 0; i < numFonts; i++ )
  {
    CTFontDescriptorRef font = CTFontDescriptorRef(CFArrayGetValueAtIndex(matchingFonts, i));
    CFDictionaryRef styles = CFDictionaryRef(CTFontDescriptorCopyAttribute(font, kCTFontTraitsAttribute));

    if ( !styles )
      continue;

    CFNumberRef symbolic = CFNumberRef(CFDictionaryGetValue(styles, kCTFontSymbolicTrait));
    if ( symbolic == NULL )
      continue;

    int d;
    if ( !CFNumberGetValue(symbolic, kCFNumberSInt32Type, &d) )
      continue;

    if ( (d & kCTFontMonoSpaceTrait) != 0 )
      return FD_FIXEDWIDTH;
  }

  return FD_VARWIDTH;
}

//-----------------------------------------------------------------------------
int main(int argc, char **argv)
{
  if ( argc != 2 )
  {
    printf("usage: %s <font family>\n", argv[0]);
    return 1;
  }

  switch ( get_font_status(argv[1]) )
  {
    case FD_NOMATCH:
      printf("Error: could not find any matching fonts for family \"%s\"\n", argv[1]);
      return 2;
    case FD_FIXEDWIDTH:
      printf("Hooray! Found at least one font for the given family that is monospaced\n");
      break;
    case FD_VARWIDTH:
      printf("Booooo. Could not find any matching fonts that are monospaced\n");
      break;
  }

  return 0;
}
