#include <proto.h>                         // Library function definitions

#ifdef __cplusplus
extern "C" {
#endif
char FAR* FAR __cdecl _fstrpbrk(const char FAR* lpszString, const char FAR* lpszCharSet)
{
  char FAR* lpTmpPtr = (char FAR*)lpszString;

  for (; *lpTmpPtr; lpTmpPtr++)
  {
    char ch = *lpTmpPtr;
    char FAR* lpTmpSet = (char FAR*)lpszCharSet;

    while (*lpTmpSet)
      if (ch == *lpTmpSet++)
        return lpTmpPtr;
  }

  return (char FAR*)NULL;
}
#ifdef __cplusplus
}
#endif

