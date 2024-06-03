#include <proto.h>

#ifdef __cplusplus
extern "C" {
#endif
long FAR __cdecl _fatoln(const char FAR * pString, int nLen)
{
  return _fatoxn(pString, nLen);
}
#ifdef __cplusplus
}
#endif

