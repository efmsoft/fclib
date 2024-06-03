#include <proto.h>

#ifdef __cplusplus
extern "C" {
#endif
char FAR* FAR __cdecl _fstrncpy(char FAR* str1, const char FAR* str2, size_t nCount)
{
  LPSTR s = str1;                           // Keep a copy as return value
  while (nCount--)                          // Copy required number of chars
  {
    *str1++ = *str2;
    if (*str2) str2++;                      // Perform eventual padding
  }
  return s;
}
#ifdef __cplusplus
}                                           // extern "C"
#endif
