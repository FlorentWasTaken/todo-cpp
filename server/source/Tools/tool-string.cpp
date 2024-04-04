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
 * Create an unique ID as a string.
 * @return string | the generated UUID.
**/
std::string createUUIDString()
{
    boost::uuids::random_generator generator;
    boost::uuids::uuid uuid = generator();

    return boost::uuids::to_string(uuid);
}