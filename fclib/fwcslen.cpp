#include <proto.h>

#ifdef __cplusplus
extern "C" {
#endif
size_t FAR __cdecl _fwcslen(const wchar_t* lpsz)
{
  size_t iRet = 0;

  while (*lpsz++ != '\0')
    iRet++;

  return iRet;
}
#ifdef __cplusplus
}                                           // extern "C"
#endif

