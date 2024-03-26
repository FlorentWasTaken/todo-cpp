#include <string>
#include <cctype>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

bool isAlphaNum(const std::string& str);

std::string createUUIDString();