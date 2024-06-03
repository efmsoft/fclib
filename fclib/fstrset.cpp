#include <proto.h>

#ifdef __cplusplus
extern "C" {
#endif
LPSTR FAR __cdecl _fstrset(LPSTR lpszString, int c)
{
  return (LPSTR)_fmemset(lpszString, c, _fstrlen(lpszString));
}

#ifdef __cplusplus
}                                           // extern "C"
#endif

