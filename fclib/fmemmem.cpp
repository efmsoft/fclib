#include <proto.h>

#ifdef __cplusplus
extern "C" {
#endif

#pragma warning(disable : 6011)

LPBYTE _fmemmem(LPBYTE p1, UINT len1, LPBYTE p2, UINT len2)
{
  LPBYTE lpPos = p1;

  for (UINT i = 0; i < len1; i++)
  {
    LPBYTE lpSrc = &lpPos[i];
    LPBYTE lpDst = p2;

    UINT j = 0;
    for (; j < len2 && j + i < len1 && *lpSrc++ == *lpDst++; j++);

    if (j == len2) return &lpPos[i];
  }
  return NULL;
}

LPBYTE _fmemrmem(LPBYTE p1, UINT len1, LPBYTE p2, UINT len2)
{
  UINT i = len1 - len2;
  for (LPBYTE lpPos = p1 + i; int(i) >= 0; i--, lpPos--)
  {
    LPBYTE lpSrc = lpPos;
    LPBYTE lpDst = p2;

    UINT j = 0;
    for (; j < len2 && *lpSrc++ == *lpDst++; j++);

    if (j == len2) return lpPos;
  }
  return NULL;
}

LPBYTE _fmemrstr(LPBYTE p1, UINT len1, LPCTSTR p)
{
  LPBYTE p2 = LPBYTE(p);
  UINT   len2 = UINT(_ftcslen(p)) * UINT(sizeof(TCHAR));
  UINT   i = len1 - len2;
  for (LPBYTE lpPos = p1 + i; int(i) >= 0; i--, lpPos--)
  {
    LPBYTE lpSrc = lpPos;
    LPBYTE lpDst = p2;

    UINT j = 0;
    for (; j < len2 && *lpSrc++ == *lpDst++; j++);

    if (j == len2) return lpPos;
  }
  return NULL;
}

LPBYTE _fmemristr(LPBYTE p1, UINT len1, LPCTSTR p)
{
  LPBYTE p2 = LPBYTE(p);
  UINT   len2 = UINT(_ftcslen(p)) * UINT(sizeof(TCHAR));
  UINT   i = len1 - len2;
  for (LPBYTE lpPos = p1 + i; int(i) >= 0; i--, lpPos--)
  {
    LPBYTE lpSrc = lpPos;
    LPBYTE lpDst = p2;

    UINT j = 0;
    for (; j < len2 && _ftoupper(*lpSrc++) == _ftoupper(*lpDst++); j++);

    if (j == len2) return lpPos;
  }
  return NULL;
}

LPSTR _fstristr(LPCSTR s1, LPCSTR s2)
{
  LPCSTR s = s1;
  LPCSTR src;
  LPCSTR dst;

  while (*s)
  {
    src = s;
    dst = s2;

    while (*dst && _ftoupper(*src) == _ftoupper(*dst))
    {
      src++;
      dst++;
    }

    if (*dst == 0) return (LPSTR)s;
    s++;
  }

  return NULL;
}

#ifdef __cplusplus
}
#endif
