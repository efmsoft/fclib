#include <proto.h>

#ifdef __cplusplus
extern "C" {
#endif
int FAR __cdecl _ftolower(int c)
{
  if (c >= 'A' && c <= 'Z')
    return c |= 0x20;
  return c;
}
#ifdef __cplusplus
}                                           // extern "C"
#endif
