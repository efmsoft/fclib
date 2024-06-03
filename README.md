# fclib library

This library contains a cross-platform implementation of standard C library functins. The code does not have any external references

### How to use
Just include proto.h and call c library functions with _f prefix. For example, 

```c++
#include <fclib/proto.h>
...
char str[64];
_fstrcpy(str, "Hellp World!");

if (_fstrcmp(str, "bla bla bla") == 0)
{
}
```

