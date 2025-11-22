#pragma once

#include <limits.h>
#include <stddef.h>
#include <stdint.h>

#ifndef FAR
#define FAR
#endif

#ifndef _WIN32
#define __cdecl
#endif

typedef uint8_t BYTE;
typedef uint16_t WORD;

#ifndef _WINDOWS_
typedef uint32_t DWORD;
#endif

typedef long LONG;
typedef unsigned int UINT;

typedef char* LPSTR;
typedef const char* LPCSTR;
typedef BYTE* LPBYTE;

typedef void FAR* FPTR;

#if !defined(_UNICODE) && !defined(UNICODE)
#ifndef _ftcslen
#define _ftcslen _fstrlen
#endif // #ifndef _ftcslen

typedef char TCHAR;
#else
typedef wchar_t TCHAR;
#endif

typedef TCHAR* LPTSTR;
typedef const TCHAR* LPCTSTR;

#ifndef LOBYTE
#define LOBYTE(w) (BYTE)((w) & 0xFF)
#endif

#ifndef HIBYTE
#define HIBYTE(w) LOBYTE((WORD)(w) >> 8)
#endif

extern "C"
{
char FAR* FAR __cdecl _fstrncpy(char FAR* str1, const char FAR* str2, size_t nCount);
char FAR* FAR __cdecl _fstrpbrk(const char FAR* lpszString, const char FAR* lpszCharSet);
const wchar_t* FAR __cdecl _fwcsstr(const wchar_t* s1, const wchar_t* s2);
FPTR FAR __cdecl _fmemmove(FPTR dest, const void FAR* src, size_t count);
int FAR __cdecl _fisdigit(int c);
int FAR __cdecl _fmemcmp(const void FAR* fpBuf1, const void FAR* fpBuf2, size_t iCount);
int FAR __cdecl _fstrcmp(LPCSTR lpszStr1, LPCSTR lpszStr2);
int FAR __cdecl _fstricmp(LPCSTR s1, LPCSTR s2);
int FAR __cdecl _fstrncmp(LPCSTR lpszString1, LPCSTR lpszString2, size_t nCount);
int FAR __cdecl _fstrnicmp(const char FAR* str1, const char FAR* str2, size_t count);
int FAR __cdecl _ftolower(int c);
int FAR __cdecl _ftoupper(int c);
long FAR __cdecl _fstrtol(LPCSTR str, LPSTR FAR* endptr, int base);
LPBYTE _fmemmem(LPBYTE p1, UINT len1, LPBYTE p2, UINT len2);
LPBYTE _fmemristr(LPBYTE p1, UINT len1, LPCTSTR p);
LPBYTE _fmemrmem(LPBYTE p1, UINT len1, LPBYTE p2, UINT len2);
LPBYTE _fmemrstr(LPBYTE p1, UINT len1, LPCTSTR p);
LPSTR _fstristr(LPCSTR s1, LPCSTR s2);
LPSTR FAR __cdecl _fstrcat(LPSTR lpszDest, LPCSTR lpszSrc);
LPSTR FAR __cdecl _fstrchr(LPCSTR s, int c);
LPSTR FAR __cdecl _fstrcpy(LPSTR lpszDest, LPCSTR lpszSrc);
LPSTR FAR __cdecl _fstrlwr(LPSTR st);
LPSTR FAR __cdecl _fstrrchr(LPCSTR s, int c);
LPSTR FAR __cdecl _fstrset(LPSTR lpszString, int c);
LPSTR FAR __cdecl _fstrstr(LPCSTR s1, LPCSTR s2);
LPSTR FAR __cdecl _fstrtok(LPSTR str, LPCSTR sep);
LPSTR FAR __cdecl _fstrupr(LPSTR st);
size_t FAR __cdecl _fstrcspn(const char FAR* str1, const char FAR* str2);
size_t FAR __cdecl _fstrlen(LPCSTR lpsz);
size_t FAR __cdecl _fstrlen(LPCSTR lpsz);
size_t FAR __cdecl _fwcslen(const wchar_t* lpsz);
int FAR __cdecl _fwcsicmp(const wchar_t *string1, const wchar_t *string2);
unsigned long FAR __cdecl _fstrtoul(LPCSTR str, LPSTR FAR* endptr, int base);
void FAR* FAR __cdecl _fmemcpy(void FAR* fpDest, const void FAR* fpSrc, size_t iCount);
void FAR* FAR __cdecl _fmemset(void FAR* fpDest, int c, size_t iCount);

int _fvsprintf(char* buffer, const char* format, va_list va);
int _fvsnprintf(char* buffer, size_t count, const char* format, va_list va);
int _fsnprintf(char* buffer, size_t count, const char* format, ...);
int _fsprintf(char* buffer, const char* format, ...);

long FAR __cdecl _fatoxn(const char FAR* pString, int nLen);
long FAR __cdecl _fatox(const char FAR* pString);
long FAR __cdecl _fatoln(const char FAR* pString, int nLen);
long FAR __cdecl _fatol(const char FAR* pString);
int FAR __cdecl _fatoin(const char FAR* pString, int nLen);
int FAR __cdecl _fatoi(const char FAR* pString);

LPCSTR FAR __cdecl EatWhiteBegin(LPCSTR p);
void FAR __cdecl EatWhiteEnd(LPCSTR p);
LPCSTR FAR __cdecl EatWhite(LPCSTR p);

void InitSoftRandGenerator(DWORD dwStartValue);
WORD RandWord(void);
DWORD RandDWord(void);

typedef int (FAR __cdecl FAR* PQSORT_HANDLER)(const void FAR*, const void FAR*);
void FAR __cdecl _fqsort(void FAR* base, size_t num, size_t width, PQSORT_HANDLER comp);

void FAR __cdecl __fltoa(LONG lValue, char FAR* pString, UINT cbString, int radix);
char FAR* FAR __cdecl _fltoa(LONG lValue, char FAR* pString, int radix);
char FAR* FAR __cdecl _fitoa(int iValue, char FAR* pString, int radix);

LPBYTE FindCodeByTemplate(LPBYTE p1, UINT len1, WORD* p2, UINT len2);
}