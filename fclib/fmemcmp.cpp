#include <proto.h>

#ifdef __cplusplus
extern "C" {
#endif
int FAR __cdecl _fmemcmp(
  const void FAR* fpBuf1
  , const void FAR* fpBuf2
  , size_t iCount
)
{
  int iRet = 0;                           // Assumes: equal buffers
  BYTE FAR* fp1 = (BYTE FAR*)fpBuf1;
  BYTE FAR* fp2 = (BYTE FAR*)fpBuf2;

  while ((iRet == 0) && iCount--)
    iRet = *fp1++ - *fp2++;

  return iRet;
}
#ifdef __cplusplus
}                                           // extern "C"
#endif
