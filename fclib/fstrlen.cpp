#include <proto.h>

#ifdef __cplusplus
extern "C" {
#endif
size_t FAR  __cdecl _fstrlen(LPCSTR lpsz)
{
  size_t iRet = 0;

  while (*lpsz++ != '\0')
    iRet++;

  return iRet;
}
#ifdef __cplusplus
}                                           // extern "C"
#endif

