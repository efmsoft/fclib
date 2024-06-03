#include <proto.h>

#ifdef __cplusplus
extern "C" {
#endif

#define Linear(s) (DWORD)((((DWORD)_FP_SEG(s)) << 4) + _FP_OFF(s))

FPTR FAR  __cdecl _fmemmove(FPTR dest, const void FAR* src, size_t count)
{
  if (src != dest && count > 0)
  {
    int     step = 1;                   // Assumes: no overlap problem
    LPSTR   s = (LPSTR)src;
    LPSTR   d = (LPSTR)dest;


    // Note: This overlap test will work in real mode and in protected mode
    //       for pointers with the same segment value. For protected mode
    //       intersegment copy we assume no overlap.

#if defined(_OS2)
    if ((_FP_SEG(src) == _FP_SEG(dest)) && (_FP_OFF(src) < _FP_OFF(dest)))
    {
      step = -1;
      s += count - 1;
      d += count - 1;
    }
#elif defined(_DPMS)
    if (((DPMS_Status == DPMS_InUse) &&
      (_FP_SEG(src) == _FP_SEG(dest)) &&
      (_FP_OFF(src) < _FP_OFF(dest))) ||
      (Linear(src) < Linear(dest)))
    {
      // dest     쳐컴컴컴컴컴캑   In this situation usual copy from
      // src   쳐컴컴컴컴컴캑      left to right is not possible

      step = -1;
      s += count - 1;
      d += count - 1;
    }
#elif defined(_DOS)                         // We are in DOS/real mode
    DWORD   dwSrcStart = Linear(src);
    DWORD   dwDstStart = Linear(dest);
    if ((dwDstStart >= dwSrcStart) && (dwDstStart <= (dwSrcStart + count)))
    {
      // dest     쳐컴컴컴컴컴캑   In this situation usual copy from
      // src   쳐컴컴컴컴컴캑      left to right is not possible

      step = -1;
      s += count - 1;
      d += count - 1;
    }
#else                                       // 32-bit OS
    if (s < d)
    {
      // dest     쳐컴컴컴컴컴캑   In this situation usual copy from
      // src   쳐컴컴컴컴컴캑      left to right is not possible

      step = -1;
      s += count - 1;
      d += count - 1;
    }
#endif                                      // 32-bit OS

    // Else: dest  쳐컴컴컴컴컴캑        or dest 쳐컴컴컴캑
    //       src       쳐컴컴컴컴컴캑       src              쳐컴컴컴?
    // Copy from left to right is possible

    while (count--)
    {
      *d = *s;
      d += step;
      s += step;
    }
  }
  return dest;
}

#ifdef __cplusplus
}                                           // extern "C"
#endif
