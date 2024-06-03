#include <proto.h>

#ifdef __cplusplus
extern "C" {
#endif
int FAR __cdecl _fstrcmp(LPCSTR lpszStr1, LPCSTR lpszStr2)
{
  while (*lpszStr1 && *lpszStr1 == *lpszStr2)
  {
    ++lpszStr1;
    ++lpszStr2;
  }
  return ((BYTE)*lpszStr1 - (BYTE)*lpszStr2);
}
#ifdef __cplusplus
}                                           // extern "C"
#endif

