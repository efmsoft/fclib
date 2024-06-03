#include <proto.h>                       // Library function definitions

#ifdef __cplusplus
extern "C" {
#endif
void FAR __cdecl __fltoa(LONG lValue, char FAR* pString, UINT cbString, int radix)
{
  UINT nDigits = 0;                       // Digits counter

  if (radix < 2 || radix > 36) return;    // Cannot convert

  //-------------------------- Consider sign of value --------------------------

  if (lValue < 0 && radix == 10)
  {
    lValue = -lValue;                   // Make positive
    *pString++ = '-';
    nDigits++;
  }

  //------------------------------ Create Divisor ------------------------------

  DWORD dwDivisor = 1;                    // Divisor

  while ((DWORD)(lValue / dwDivisor) >= (DWORD)radix) dwDivisor *= radix;

  //------------------------------- Create string -------------------------------

  while (dwDivisor && nDigits++ < cbString)
  {
    int i = (int)((DWORD)lValue / dwDivisor);

    if (i < 10) *pString++ = i + '0';  // A digit
    else        *pString++ = (i - 10) + 'A';

    lValue = (DWORD)lValue % dwDivisor;
    dwDivisor /= radix;
  }

  *pString = '\0';
}

char FAR* FAR __cdecl _fltoa(LONG lValue, char FAR* pString, int radix)
{
  __fltoa(lValue, pString, 33, radix);
  return pString;
}

char FAR* FAR __cdecl _fitoa(int iValue, char FAR* pString, int radix)
{
  __fltoa((LONG)iValue, pString, 17, radix);
  return pString;
}
#ifdef __cplusplus
}
#endif
