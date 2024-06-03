#include <proto.h>

#ifdef __cplusplus
extern "C" {
#endif
long FAR __cdecl _fatol(const char FAR * pString)
{
  return _fatox(pString);
}
#ifdef __cplusplus
}
#endif
