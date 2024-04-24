/**
 * Unit Tests for Password class
 **/

#include "Password.h"
#include <gtest/gtest.h>

class PasswordTest : public ::testing::Test {
protected:
  PasswordTest() {}          // constructor runs before each test
  virtual ~PasswordTest() {} // destructor cleans up after tests
  virtual void SetUp() {}    // sets up before each test (after constructor)
  virtual void TearDown() {} // clean up after each test, (before destructor)
};

TEST(PasswordTest, count_leading_characters_single_letter) {
  Password my_password;
  int actual = my_password.count_leading_characters("Z");
  ASSERT_EQ(1, actual);
}

TEST(PasswordTest, count_leading_characters_two_letters) {
  Password my_password;
  int actual = my_password.count_leading_characters("ZZ");
  ASSERT_EQ(2, actual);
}

TEST(PasswordTest, count_leading_characters_no_repeating_characters) {
  Password my_password;
  int actual = my_password.count_leading_characters("ABCDEF");
  ASSERT_EQ(1, actual);
}

TEST(PasswordTest, count_leading_characters_repeating_characters_at_beginning) {
  Password my_password;
  int actual = my_password.count_leading_characters("ZZXY");
  ASSERT_EQ(2, actual);
}

TEST(PasswordTest, count_leading_characters_repeating_characters_at_end) {
  Password my_password;
  int actual = my_password.count_leading_characters("XYZZ");
  ASSERT_EQ(1, actual);
}

TEST(PasswordTest, count_leading_characters_repeating_characters_in_middle) {
  Password my_password;
  int actual = my_password.count_leading_characters("ABCBBBABC");
  ASSERT_EQ(1, actual);
}

TEST(PasswordTest, count_leading_characters_empty_string) {
  Password my_password;
  int actual = my_password.count_leading_characters("");
  ASSERT_EQ(0, actual);
}

TEST(PasswordTest, count_leading_characters_mixed_case_repeating_characters) {
  Password my_password;
  int actual = my_password.count_leading_characters("aAbbBBccCC");
  ASSERT_EQ(1, actual);
}

TEST(PasswordTest, count_leading_characters_special_characters) {
  Password my_password;
  int actual = my_password.count_leading_characters("!@##$%!");
  ASSERT_EQ(1, actual);
}

TEST(PasswordTest, count_leading_characters_long_sequence_of_repeating_characters) {
  Password my_password;
  int actual = my_password.count_leading_characters("LLLLLLLLLLLLLLLLLLLLLLLLLLLLLL");
  ASSERT_EQ(30, actual);
}

TEST(PasswordTest, has_mixed_case_only_upper_case) {
  Password my_password;
  bool actual = my_password.has_mixed_case("AL");
  ASSERT_EQ(false, actual);
}

TEST(PasswordTest, has_mixed_case_only_lower_case) {
  Password my_password;
  bool actual = my_password.has_mixed_case("al");
  ASSERT_EQ(false, actual);
}

TEST(PasswordTest, has_mixed_case_both_upper_and_lower_case) {
  Password my_password;
  bool actual = my_password.has_mixed_case("Al");
  ASSERT_EQ(true, actual);
}

TEST(PasswordTest, has_mixed_case_only_numbers) {
  Password my_password;
  bool actual = my_password.has_mixed_case("123456");
  ASSERT_EQ(false, actual);
}

TEST(PasswordTest, has_mixed_case_special_characters) {
  Password my_password;
  bool actual = my_password.has_mixed_case("!@#$%^&*");
  ASSERT_EQ(false, actual);
}

TEST(PasswordTest, has_mixed_case_mixed_case_with_numbers_and_special_characters) {
  Password my_password;
  bool actual = my_password.has_mixed_case("aBcDeF123!@#");
  ASSERT_EQ(true, actual);
}

TEST(PasswordTest, has_mixed_case_only_uppercase_with_numbers) {
  Password my_password;
  bool actual = my_password.has_mixed_case("ABC123");
  ASSERT_EQ(false, actual);
}

TEST(PasswordTest, has_mixed_case_only_lowercase_with_numbers) {
  Password my_password;
  bool actual = my_password.has_mixed_case("abc123");
  ASSERT_EQ(false, actual);
}

TEST(PasswordTest, has_mixed_case_empty_string) {
  Password my_password;
  bool actual = my_password.has_mixed_case("");
  ASSERT_EQ(false, actual);
}

TEST(PasswordTest, constructor_default_password) {
  Password my_password;
  bool authenticated = my_password.authenticate("ChicoCA-95929");
  ASSERT_TRUE(authenticated);
}

TEST(PasswordTest, set_valid_password) {
  Password my_password;
  my_password.set("ValidPassword123");
  bool authenticated = my_password.authenticate("ValidPassword123");
  ASSERT_TRUE(authenticated);
}

TEST(PasswordTest, set_short_password) {
  Password my_password;
  my_password.set("Short");
  bool authenticated = my_password.authenticate("Short");
  ASSERT_FALSE(authenticated);
}

TEST(PasswordTest, set_long_password) {
  Password my_password;
  my_password.set("ThisIsAReallyLongPasswordThatIsInvalid");
  bool authenticated = my_password.authenticate("ThisIsAReallyLongPasswordThatIsInvalid");
  ASSERT_FALSE(authenticated);
}

TEST(PasswordTest, set_repeating_characters) {
  Password my_password;
  my_password.set("AAABBBCCC");
  bool authenticated = my_password.authenticate("AAABBBCCC");
  ASSERT_FALSE(authenticated);
}

TEST(PasswordTest, set_invalid_repeating_characters) {
  Password my_password;
  my_password.set("AAAABBBCCC");
  bool authenticated = my_password.authenticate("AAAABBBCCC");
  ASSERT_FALSE(authenticated);
}

TEST(PasswordTest, set_previous_password) {
  Password my_password;
  my_password.set("FirstPassword");
  my_password.set("SecondPassword");
  my_password.set("FirstPassword");
  bool authenticated = my_password.authenticate("FirstPassword");
  ASSERT_FALSE(authenticated);
}

TEST(PasswordTest, authenticate_without_setting_password) {
  Password my_password;
  bool authenticated = my_password.authenticate("Password123");
  ASSERT_FALSE(authenticated);
}

TEST(PasswordTest, authenticate_with_correct_password) {
  Password my_password;
  my_password.set("Password123");
  bool authenticated = my_password.authenticate("Password123");
  ASSERT_TRUE(authenticated);
}

TEST(PasswordTest, authenticate_with_incorrect_password) {
  Password my_password;
  my_password.set("Password123");
  bool authenticated = my_password.authenticate("WrongPassword");
  ASSERT_FALSE(authenticated);
}

TEST(PasswordTest, authenticate_with_empty_password) {
  Password my_password;
  my_password.set("Password123");
  bool authenticated = my_password.authenticate("");
  ASSERT_FALSE(authenticated);
}

TEST(PasswordTest, authenticate_without_setting_and_empty_password) {
  Password my_password;
  bool authenticated = my_password.authenticate("");
  ASSERT_FALSE(authenticated);
}
