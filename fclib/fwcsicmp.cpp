#include <proto.h>

#ifdef __cplusplus
extern "C" {
#endif
int FAR __cdecl _fwcsicmp(const wchar_t *s1, const wchar_t *s2)
{
  int iRet = 0;                           // Return value

  // If length of strings is different, but all characters of shorter
  // string match to beginning of longer string, we return:
  // < 0, if 's1' is shorter than 's2'
  // > 0, if 's1' is greater than 's2'
  // This same is behaviour as Microsoft implementation.

  while (*s1 || *s2)
  {
    if ((iRet = (int)(_ftoupper(*s1++) - _ftoupper(*s2++))) != 0)
      break;
  }
  return iRet;
}
#ifdef __cplusplus
}                                           // extern "C"
#endif

