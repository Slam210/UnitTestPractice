#include "Password.h"
#include <cctype>

using std::string;

/*
constructor sets the default password to "ChicoCA-95929"
*/
Password::Password(){
    pass_history.push_back("ChicoCA-95929");
};

/*
The function receives a string and counts how many times the same character
occurs at the beginning of the string, before any other characters (or the
end of the string). The function is case-sensitive so 'Z' is different than
'z' and any ASCII characters are allowed.
*/
int Password::count_leading_characters(string str) {
    if (str.empty()) return 0;

    char first_char = str[0];
    int count = 1;
    for (size_t i = 1; i < str.size(); ++i) {
        if (str[i] == first_char)
            ++count;
        else
            break;
    }
    return count;
}

/*
Returns whether the phrase has both at least one upper-case letter and
at least one lower-case letter.
*/
bool Password::has_mixed_case(string str) {
    bool has_upper = false;
    bool has_lower = false;
    for (char c : str) {
        if (std::isupper(c))
            has_upper = true;
        else if (std::islower(c))
            has_lower = true;
        if (has_upper && has_lower)
            return true;
    }
    return false;
}

/*
Receives a password and sets the latest in pass_history to it if and only
if it meets all criteria:
1. The password is at least 8 letters long, but no longer than 20.
2. It has no more than 3 of the same leading characters.
3. It has mixed case (at least one upper case and at least one lower case).
4. It was not a previous password in the history.
*/
void Password::set(string password) {
    if(!(password.length() > 8 && password.length() < 20)){
        return;
    }
    if (count_leading_characters(password) > 3){
        return;
    }
    if(!has_mixed_case(password)){
        return;
    }
    for (string current : pass_history){
        if (current == password){
            return;
        }
    }
    pass_history.push_back(password);
    return;
}

/*
Receives a string and authenticates it against the latest password in the
pass_history, returning true for an exact match or false when it does not match
or if a password has not been set.
*/
bool Password::authenticate(string password) {
    // Implement this function
    int index = pass_history.size() -1;
    if (pass_history[index] == password){
        return true;
    }
    return false;
}
