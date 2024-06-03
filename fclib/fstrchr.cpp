#include <proto.h>

#ifdef __cplusplus
extern "C" {
#endif
LPSTR FAR __cdecl _fstrchr(LPCSTR s, int c)
{
  do
  {
    if (*s == (char)c)
      return (LPSTR)s;
  } while (*(s++));

  return NULL;
}
#ifdef __cplusplus
}                                           // extern "C"
#endif
