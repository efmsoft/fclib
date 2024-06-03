#include <proto.h>

#pragma warning(disable : 26819)

#ifdef __cplusplus
extern "C" {
#endif
long FAR __cdecl _fatox(const char FAR *pString)
{
    short Neg  = 0;                         // Assumes positive
    long  iRet = 0;                         // Return value accumulator

                                            // Skip leading wait space
    while (*pString == ' ' || *pString == '\t') pString++;

    switch (*pString)
    {
        case '-':   Neg = 1;                // Intentional break though
        case '+':   pString++; break;
        default:    break;
    }

    while (_fisdigit(*pString)) iRet = iRet * 10 + (*pString++ - '0');

    return (iRet * (Neg ? -1 : 1));
}
#ifdef __cplusplus
}
#endif
