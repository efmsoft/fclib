#include <proto.h>

#ifdef __cplusplus
extern "C" {
#endif
LPSTR FAR __cdecl _fstrstr(LPCSTR s1, LPCSTR s2)
{
  LPCSTR s = s1;
  LPCSTR src;
  LPCSTR dst;

  while (*s)
  {
    src = s;
    dst = s2;

    // Note: The old version compiled incorrectly for _DOS
    //       because pointers in the while expresion
    //       (*src++ == *dst++) were incremented despite of
    //       the value of the first expression (*dst) ## VVK ##

    while (*dst && *src == *dst)
    {
      src++;
      dst++;
    }

    if (*dst == 0) return (LPSTR)s;
    s++;
  }

  return NULL;
}
#ifdef __cplusplus
}                                           // extern "C"
#endif
