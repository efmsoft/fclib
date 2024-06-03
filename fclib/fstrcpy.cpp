#include <proto.h>

#ifdef __cplusplus
extern "C" {
#endif
LPSTR FAR __cdecl _fstrcpy(LPSTR lpszDest, LPCSTR lpszSrc)
{
  return (LPSTR)_fmemcpy(lpszDest, lpszSrc, _fstrlen(lpszSrc) + 1);
}
#ifdef __cplusplus
}                                           // extern "C"
#endif

