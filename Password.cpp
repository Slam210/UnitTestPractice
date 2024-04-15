#include "Password.h"
#include <cctype>

using std::string;

/*
  The function receives a string counts how many times the same character
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
*/
int Password::count_leading_characters(string phrase) {
  int repetition = 1;
  int index = 0;
  if (phrase == "") {
    return 0;
  }
  while (index < phrase.length() - 1 && phrase[index] == phrase[index + 1]) {
    repetition++;
    index++;
  }
  return repetition;
}

bool Password::has_mixed_case(string phrase) {
  bool uppercase = false;
  bool lowercase = false;
  for (char c : phrase) {
    if (c >= 'a' && c <= 'z') {
      lowercase = true;
    } else if (c >= 'A' && c <= 'Z') {
      uppercase = true;
    } else {
      continue;
    }
    if (uppercase && lowercase) {
      return uppercase && lowercase;
    }
  }
  return false;
}
