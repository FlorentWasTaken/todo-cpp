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

/**
 * Count occurence of a character in a string.
 * @param const std::string &str | the string to check
 * @param const char &character | the character to count
 * @return unsigned int | occurences of character.
**/
unsigned int countChar(const std::string &str, const char &character)
{
    unsigned int nb = 0;

    for (const char c : str)
        if (c == character)
            nb++;
    return nb;
}

/**
 * Create an unique ID as a string.
 * @return string | the generated UUID.
**/
std::string createUUIDString()
{
    boost::uuids::random_generator generator;
    boost::uuids::uuid uuid = generator();

    return boost::uuids::to_string(uuid);
}