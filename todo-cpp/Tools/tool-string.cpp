#include "tool-string.hpp"

/**
 * Check if a string is composed of alphabetic and/or numeric characters.
 * @param const std::string &str | the string to check
 * @return bool | true if it contains only alphabetic and/or numeric characters, false otherwise.
**/
bool isAlphaNum(const std::string &str)
{
    for (char c : str)
        if (!std::isalnum(c))
            return false;
    return true;
}