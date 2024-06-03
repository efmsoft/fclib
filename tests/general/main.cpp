#include <fclib/proto.h>
#include <gtest/gtest.h>

#include <cstring>

TEST(fclib, _fstrncpy)
{
  // No null-character is implicitly appended at the end of destination 
  // if source is longer than num. Thus, in this case, destination shall 
  // not be considered a null terminated C string
  char dst1[5] = { '1', '2', '3', '4', '5' };
  char src1[5] = { '9', '8', '7', '6', '\0' };
  auto p1 = _fstrncpy(dst1, src1, 3);
  EXPECT_EQ(p1, dst1);
  EXPECT_EQ(dst1[0], '9');
  EXPECT_EQ(dst1[1], '8');
  EXPECT_EQ(dst1[2], '7');
  EXPECT_EQ(dst1[3], '4');
  EXPECT_EQ(dst1[4], '5');

  auto p2 = _fstrncpy(dst1, src1, 5);
  EXPECT_EQ(p2, dst1);
  EXPECT_EQ(dst1[0], '9');
  EXPECT_EQ(dst1[1], '8');
  EXPECT_EQ(dst1[2], '7');
  EXPECT_EQ(dst1[3], '6');
  EXPECT_EQ(dst1[4], '\0');
}

TEST(fclib, _fstrpbrk)
{
  char str[] = "This is a sample string";
  char key[] = "aeiou";
  char rc[] = { 'i', 'i', 'a', 'a', 'e', 'i' };

  char* pch = _fstrpbrk(str, key);
  for (int i = 0; pch != nullptr; ++i)
  {
    EXPECT_EQ(*pch, rc[i]);
    pch = _fstrpbrk(pch + 1, key);
  }
}

TEST(fclib, _fmemmove)
{
  char str1[9] = "aabbccdd";
  _fmemmove(str1 + 2, str1, 6);
  EXPECT_EQ(_fstrcmp(str1, "aaaabbcc"), 0);
}

TEST(fclib, _fisdigit)
{
  EXPECT_EQ(_fisdigit('0'), true);
  EXPECT_EQ(_fisdigit('1'), true);
  EXPECT_EQ(_fisdigit('2'), true);
  EXPECT_EQ(_fisdigit('3'), true);
  EXPECT_EQ(_fisdigit('4'), true);
  EXPECT_EQ(_fisdigit('5'), true);
  EXPECT_EQ(_fisdigit('6'), true);
  EXPECT_EQ(_fisdigit('7'), true);
  EXPECT_EQ(_fisdigit('8'), true);
  EXPECT_EQ(_fisdigit('9'), true);

  EXPECT_EQ(_fisdigit('a'), false);
  EXPECT_EQ(_fisdigit('Z'), false);
}

TEST(fclib, _fmemcmp)
{
  EXPECT_NE(_fmemcmp("abcdef", "abcdEf", 6), 0);
  EXPECT_EQ(_fmemcmp("abcdef", "abcdEf", 4), 0);
  EXPECT_EQ(_fmemcmp("abcdef", "abcdEf", 0), memcmp("abcdef", "abcdEf", 0));
}

TEST(fclib, _fmemmcpy)
{
  char str1[9] = "aabbccdd";
  _fmemcpy(str1 + 2, str1, 6);
  EXPECT_EQ(_fstrcmp(str1, "aaaabbbb"), 0);
}

TEST(fclib, _fstrcmp)
{
  EXPECT_EQ(_fstrcmp("", ""), 0);
  EXPECT_NE(_fstrcmp("A", ""), 0);
  EXPECT_NE(_fstrcmp("", "a"), 0);

  EXPECT_EQ(_fstrcmp("abcd", "abcd"), 0);
  EXPECT_NE(_fstrcmp("abcd", "aBcd"), 0);
}

TEST(fclib, _fstricmp)
{
  EXPECT_EQ(_fstricmp("", ""), 0);
  EXPECT_NE(_fstricmp("A", ""), 0);
  EXPECT_NE(_fstricmp("", "a"), 0);

  EXPECT_EQ(_fstricmp("abcd", "abcd"), 0);
  EXPECT_EQ(_fstricmp("abcd", "aBcd"), 0);
}