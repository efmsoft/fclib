#include <proto.h>

#ifdef __cplusplus
extern "C" {
#endif

void FAR* FAR __cdecl _fmemcpy(void FAR* fpDest, const void FAR* fpSrc, size_t iCount)
{
  int  i = int(iCount / sizeof(DWORD));

  union
  {
    DWORD FAR* fpdwDest;
    BYTE  FAR* fpbyDest;
  };

  union
  {
    DWORD FAR* fpdwSrc;
    BYTE  FAR* fpbySrc;
  };

  fpdwDest = (DWORD FAR*)fpDest;
  fpdwSrc = (DWORD FAR*)fpSrc;

  while (i--)
    *fpdwDest++ = *fpdwSrc++;

  i = iCount % sizeof(DWORD);

  while (i--)
    *fpbyDest++ = *fpbySrc++;

  return fpDest;
}
#ifdef __cplusplus
}                                           // extern "C"
#endif
