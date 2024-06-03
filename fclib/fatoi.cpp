#include <proto.h>

#ifdef __cplusplus
extern "C" {
#endif
int FAR __cdecl _fatoi(const char FAR* pString)
{
  return (int)_fatox(pString);
}
#ifdef __cplusplus
}
#endif
