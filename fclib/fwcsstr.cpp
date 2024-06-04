#include <proto.h>

#ifdef __cplusplus
extern "C" {
#endif
const wchar_t* FAR __cdecl _fwcsstr(const wchar_t* s1, const wchar_t* s2)
{
  const wchar_t* s = s1;
  const wchar_t* src;
  const wchar_t* dst;

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

    if (*dst == 0) return (const wchar_t*)s;
    s++;
  }

  return NULL;
}
#ifdef __cplusplus
}                                           // extern "C"
#endif
