#include <proto.h>

#ifdef __cplusplus
extern "C" {
#endif
static bool __IsCharSeparator(char c, LPCSTR sep)
{
  while (*sep)
  {
    if (*sep++ == c) return true;
  }
  return false;
}

LPSTR FAR __cdecl _fstrtok(LPSTR str, LPCSTR sep)
{
  static LPSTR head;                      // Used for token processing
  static LPSTR tail;                      // Used for token processing

  if (str)                                // First call
  {
    head = str;
    while (*head &&
      __IsCharSeparator(*head, sep))  // Skip leading separators
      head++;
  }
  else
  {
    if (tail == (LPSTR)(-1)) return (NULL);
    head = tail + 1;
  }

  tail = head;
  do
  {
    if (__IsCharSeparator(*tail, sep))
    {
      *tail = 0;
      return head;
    }
  } while (*(++tail));

  tail = (LPSTR)(-1);
  return head;
}
#ifdef __cplusplus
}                                           // extern "C"
#endif
