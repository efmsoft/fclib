#include <proto.h>

#ifdef __cplusplus
extern "C" {
#endif
int FAR __cdecl _fisdigit(int c)
{
  return (int)((c >= '0') && (c <= '9'));
}
#ifdef __cplusplus
}
#endif
