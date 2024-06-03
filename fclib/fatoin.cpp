#include <proto.h>

#ifdef __cplusplus
extern "C" {
#endif
int FAR __cdecl _fatoin(const char FAR* pString, int nLen)
{
  return (int)_fatoxn(pString, nLen);
}
#ifdef __cplusplus
}
#endif

