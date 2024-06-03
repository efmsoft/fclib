#include <proto.h>

#ifdef __cplusplus
extern "C" {
#endif
long  FAR __cdecl _fstrtol(LPCSTR str, LPSTR FAR* endptr, int base)
{
  long    lValue = 0;                       // Result placeholder
  int     fSign = 1;                        // Positive or negative

  if (str != NULL)
  {
    str = EatWhite(str);                    // Skip white space

    if (*str == '-')
    {
      fSign = -1;                           // Skip sign, if any
      str++;
    }
    else if (*str == '+')
      str++;

    DWORD dwValue = _fstrtoul(str, endptr, base);

    if (dwValue > LONG_MAX)
      lValue = LONG_MAX;
    else
      lValue = (long)dwValue;
  }
  return (lValue * fSign);
}
#ifdef __cplusplus
}                                           // extern "C"
#endif
