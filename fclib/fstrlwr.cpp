#include <proto.h>

#ifdef __cplusplus
extern "C" {
#endif
LPSTR FAR __cdecl _fstrlwr(LPSTR st)
{
  LPSTR s = st;
  for (; *s; s++) *s = (char)_ftolower(*s);
  return st;
}
#ifdef __cplusplus
}                                           // extern "C"
#endif
