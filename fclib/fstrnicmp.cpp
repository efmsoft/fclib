#include <proto.h>

#ifdef __cplusplus
extern "C" {
#endif
int FAR __cdecl _fstrnicmp(const char FAR* str1, const char FAR* str2, size_t count)
{
  size_t nCount = 0;
  int    nVal1, nVal2;                    // Used to store values of
  // _ftoupper
  while (nCount < count)
  {
    // Here we also cover the situation that one or both characters are '\0' !
    // string1=abcd is lexicographically greater than string2=abc
    if ((nVal1 = _ftoupper(str1[nCount])) != (nVal2 = _ftoupper(str2[nCount])))
    {
      if (nVal1 > nVal2)
        return 1;
      else
        return -1;
    }
    nCount++;
  }

  // If we come to this point than the first count characters of the strings are
  // equal
  return 0;
}
#ifdef __cplusplus
}
#endif

