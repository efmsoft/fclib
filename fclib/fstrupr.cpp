#include <proto.h>                       // Library function definitions

#ifdef __cplusplus
extern "C" {
#endif
LPSTR FAR __cdecl _fstrupr(LPSTR st)
{
  LPSTR s = st;
  for (; *s; s++) *s = (char)_ftoupper(*s);
  return st;
}
#ifdef __cplusplus
}                                           // extern "C"
#endif
