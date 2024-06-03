#include <proto.h>                       // Library function definitions

#ifdef __cplusplus
extern "C" {
#endif
LPCSTR FAR __cdecl EatWhiteBegin(LPCSTR p)
{
  if (p == NULL) return p;

  while ((*p) && ((*p == ' ') || (*p == '\t') || (*p == ','))) p++;
  return p;
}

void FAR __cdecl EatWhiteEnd(LPCSTR p)
{
  if (p == NULL) return;

  WORD wLen = (WORD)_fstrlen(p);
  // Use unsigned char to avoid eating characters above 127
  unsigned char   FAR* q = (unsigned char   FAR*)p + wLen - 1;

  while (wLen && ((*q <= ' ') || (*q == ',')))
  {
    *q-- = '\0';
    wLen--;
  }
}

LPCSTR FAR __cdecl EatWhite(LPCSTR p)
{
  EatWhiteEnd(p);
  return EatWhiteBegin(p);
}
#ifdef __cplusplus
}
#endif
