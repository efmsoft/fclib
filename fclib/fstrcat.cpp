#include <proto.h>

#ifdef __cplusplus
extern "C" {
#endif
LPSTR FAR __cdecl _fstrcat(LPSTR lpszDest, LPCSTR lpszSrc)
{
  lpszDest += _fstrlen(lpszDest);
  return _fstrcpy(lpszDest, lpszSrc);
}

#ifdef __cplusplus
}                                           // extern "C"
#endif

