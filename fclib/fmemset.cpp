#include <proto.h>

#ifdef __cplusplus
extern "C" {
#endif
void FAR* FAR __cdecl _fmemset(void FAR* fpDest, int c, size_t iCount)
{
  BYTE FAR* fpbyDest = (BYTE FAR*)fpDest;

  while (iCount--)
    *fpbyDest++ = (char)c;

  return fpDest;
}
#ifdef __cplusplus
}                                           // extern "C"
#endif

