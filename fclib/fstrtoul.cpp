#include <proto.h>                       // Library function definitions

#ifdef __cplusplus
extern "C" {
#endif                                      // #ifdef __cplusplus
static int __CheckBase(LPCSTR FAR* str, int Base)
{
  if (Base == 0)                            // Base calculated from string
  {
    if (**str == '0')                       // Hexadecimal or octal
    {
      (*str)++;
      if (_ftoupper(**str) == 'X')          // Hexadecimal
      {
        Base = 16;
        (*str)++;
      }
      else                                  // Octal
        Base = 8;
    }
    else
      Base = 10;
  }
  else
  {
    if (Base < 2 || Base > 36)              // Base out of range
      Base = 0;
  }
  return Base;
}
#pragma warning (disable: 4791)             // Loss of debugging information
                                            // caused by optimization
unsigned long  FAR __cdecl _fstrtoul(LPCSTR str, LPSTR FAR* endptr, int base)
{
  unsigned long dwValue = 0;                // Result placeholder

  if (str != NULL)
  {

    str = EatWhite(str);                    // Skip white space

    //--------------------------------- Skip Sign ---------------------------------

    if (*str == '+') str++;

    str = EatWhite(str);                    // Skip white space

    //--------------------- Get base from number, if required ---------------------

    if ((base = __CheckBase(&str, base)) != 0)
    {
      while (*str)
      {
        unsigned long d = dwValue;          // Overflow may occurs

        if (_fisdigit(*str))
          dwValue = dwValue * base + (*str - '0');
        else
        {
          int n = _ftoupper(*str) - 'A';
          if (n >= 0)
          {
            n += 10;
            if (n < base)
              dwValue = dwValue * base + n;
            else
              break;
          }
          else
            break;
        }
        if (dwValue < d)                    // Overflow occurs
        {
          dwValue = ULONG_MAX;
          break;
        }
        str++;
      }
    }

    if (endptr)
      *endptr = (LPSTR)str;                 // Scan was stopped here

  }
  return dwValue;
}
#pragma warning (default: 4791)             // Loss of debugging information
                                            // caused by optimization
#ifdef __cplusplus
}                                           // extern "C"
#endif                                      // #ifdef __cplusplus
