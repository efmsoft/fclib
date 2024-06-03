#include <fclib/proto.h>
#include <gtest/gtest.h>

TEST(fclib, strcmp)
{
  EXPECT_EQ(_fstrcmp("", ""), 0);
  EXPECT_NE(_fstrcmp("A", ""), 0);
  EXPECT_NE(_fstrcmp("", "a"), 0);

  EXPECT_EQ(_fstrcmp("abcd", "abcd"), 0);
  EXPECT_NE(_fstrcmp("abcd", "aBcd"), 0);
}