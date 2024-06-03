#include <proto.h>

size_t FAR __cdecl _fstrcspn(const char FAR* str1, const char FAR* str2)
{
  char FAR* str = (char FAR*) str1;

  while (*str)
  {
    if (_fstrchr(str2, *str))
      break;
    str++;
  }

  return (size_t)(str - str1);
}

size_t FAR __cdecl _fstrspn(const char FAR* str1, const char FAR* str2)
{
  char FAR* str = (char FAR*) str1;

  while (*str)
  {
    if (!_fstrchr(str2, *str))
      break;
    str++;
  }

  return (size_t)(str - str1);
}
