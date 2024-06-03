#include <proto.h>

#ifdef __cplusplus
extern "C" {
#endif
int FAR __cdecl _fstrncmp(LPCSTR lpszString1, LPCSTR lpszString2, size_t nCount)
{
  if (!nCount)
    return(0);

  while (--nCount && *lpszString1 && *lpszString1 == *lpszString2)
  {
    lpszString1++;
    lpszString2++;
  }
  return ((BYTE)*lpszString1 - (BYTE)*lpszString2);
}
#ifdef __cplusplus
}                                           // extern "C"
#endif
