/**
 * Unit Tests for Password class
 **/

#include "Password.h"
#include <gtest/gtest.h>

class PracticeTest : public ::testing::Test {
protected:
  PracticeTest() {}          // constructor runs before each test
  virtual ~PracticeTest() {} // destructor cleans up after tests
  virtual void SetUp() {}    // sets up before each test (after constructor)
  virtual void TearDown() {} // clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password) {
  Password my_password;
  int actual = my_password.count_leading_characters("Z");
  ASSERT_EQ(1, actual);
}

TEST(PasswordTest, two_letter_password) {
  Password my_password;
  int actual = my_password.count_leading_characters("ZZ");
  ASSERT_EQ(2, actual);
}

TEST(PasswordTest, no_repeating_characters) {
  Password my_password;
  int actual = my_password.count_leading_characters("ABCDEF");
  ASSERT_EQ(1, actual);
}

TEST(PasswordTest, repeating_characters_at_beggining) {
  Password my_password;
  int actual = my_password.count_leading_characters("ZZXY");
  ASSERT_EQ(2, actual);
}

TEST(PasswordTest, repeating_characters_at_end) {
  Password my_password;
  int actual = my_password.count_leading_characters("XYZZ");
  ASSERT_EQ(1, actual);
}

TEST(PasswordTest, repeating_characters_in_middle) {
  Password my_password;
  int actual = my_password.count_leading_characters("ABCBBBABC");
  ASSERT_EQ(1, actual);
}

TEST(PasswordTest, empty_string) {
  Password my_password;
  int actual = my_password.count_leading_characters("");
  ASSERT_EQ(0, actual);
}

TEST(PasswordTest, mixed_case_repeating_characters) {
  Password my_password;
  int actual = my_password.count_leading_characters("aAbbBBccCC");
  ASSERT_EQ(1, actual);
}

TEST(PasswordTest, special_characters) {
  Password my_password;
  int actual = my_password.count_leading_characters("!@##$%!");
  ASSERT_EQ(1, actual);
}

TEST(PasswordTest, long_sequence_of_repeating_characters) {
  Password my_password;
  int actual =
      my_password.count_leading_characters("LLLLLLLLLLLLLLLLLLLLLLLLLLLLLL");
  ASSERT_EQ(30, actual);
}

TEST(PasswordTest, onlyupperCase) {
  Password my_password;
  bool actual = my_password.has_mixed_case("AL");
  ASSERT_EQ(false, actual);
}

TEST(PasswordTest, onlylowerCase) {
  Password my_password;
  bool actual = my_password.has_mixed_case("al");
  ASSERT_EQ(false, actual);
}

TEST(PasswordTest, bothupperandlowerCase) {
  Password my_password;
  bool actual = my_password.has_mixed_case("Al");
  ASSERT_EQ(true, actual);
}

TEST(PasswordTest, onlyNumbers) {
  Password my_password;
  bool actual = my_password.has_mixed_case("123456");
  ASSERT_EQ(false, actual);
}

TEST(PasswordTest, specialCharacters) {
  Password my_password;
  bool actual = my_password.has_mixed_case("!@#$%^&*");
  ASSERT_EQ(false, actual);
}

TEST(PasswordTest, mixedCaseWithNumbersAndSpecialCharacters) {
  Password my_password;
  bool actual = my_password.has_mixed_case("aBcDeF123!@#");
  ASSERT_EQ(true, actual);
}

TEST(PasswordTest, onlyUppercaseWithNumbers) {
  Password my_password;
  bool actual = my_password.has_mixed_case("ABC123");
  ASSERT_EQ(false, actual);
}

TEST(PasswordTest, onlyLowercaseWithNumbers) {
  Password my_password;
  bool actual = my_password.has_mixed_case("abc123");
  ASSERT_EQ(false, actual);
}

TEST(PasswordTest, emptyString) {
  Password my_password;
  bool actual = my_password.has_mixed_case("");
  ASSERT_EQ(false, actual);
}
