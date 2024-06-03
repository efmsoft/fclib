#include <proto.h>

#if   defined(_WINNTD)
#define IsAddressValid(p)      (IsBadReadPtr((PVOID)p) == BOOL_FALSE)
#elif defined(_WIN4)
#define IsAddressValid(p)      (DWORD(p) > 0xC0000000)
#else
#define IsAddressValid(p)      1
#endif

LPBYTE FindCodeByTemplate(LPBYTE p1, UINT len1, WORD* p2, UINT len2)
{
  for (; len2 && HIBYTE(*p2); len2--, p2++);

  LPBYTE lpPos = p1;

  for (UINT i = 0; i < len1; i++)
  {
    if (len1 - i < len2)
      break;

    LPBYTE lpSrc = &lpPos[i];

    if (IsAddressValid(lpSrc))
    {
      WORD* lpDst = p2;
      UINT j = 0;
      for (; j < len2 && j + i < len1; j++, lpSrc++, lpDst++)
      {
        if (HIBYTE(*lpDst))
          continue;
        else
          if (!IsAddressValid(lpSrc) || *lpSrc != LOBYTE(*lpDst))
            break;
      }

      if (j == len2)
        return &lpPos[i];
    }
  }
  return nullptr;
}
