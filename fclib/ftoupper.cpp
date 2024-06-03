#include <proto.h>

#ifdef __cplusplus
extern "C" {
#endif
int FAR __cdecl _ftoupper(int c)
{
  if (c >= 'a' && c <= 'z')
      return c & 0x5F;
  return c;
}
#ifdef __cplusplus
}                                           // extern "C"
#endif
