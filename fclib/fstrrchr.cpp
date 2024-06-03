#include <proto.h>

#ifdef __cplusplus
extern "C" {
#endif
LPSTR FAR __cdecl _fstrrchr(LPCSTR s, int c)
{
  LPCSTR s1 = s + _fstrlen(s) + 1;        // s1 point to a first byte after
  // end of the string,
  // it's normal situation if s1 step
  // over top of segment since next
  // is (--s1).
  do
  {
    if (*(--s1) == (char)c)
      return (LPSTR)s1;
  } while (s1 > s);

  // Note: If a string is situated at the begin of a segment
  //       then
  //             do {...} while ((--s1) >= s), s  - pointer to the string
  //                                           s1 - scan pointer,
  //
  //       provide cross over bottom bound of the segment.
  //
  //       Now this function behavior is same with MicroSoft implementation.
  //
  //                                  ## GVG ## 27.11.99 4:08

  return NULL;
}
#ifdef __cplusplus
}                                           // extern "C"
#endif
