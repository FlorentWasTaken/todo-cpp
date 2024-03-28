#include "IList.hpp"

todo::AList::AList()
{
	mUUID = createUUIDString();
}

/**
 * Get list's title.
 * @return std::string | list's title
**/
std::string todo::AList::getTitle() const
{
	return mTitle;
}

/**
 * Set list's title (only accept alphabetic and/or numeric characters).
 * @param const std::string & | title to set
 * @return void
**/
void todo::AList::setTitle(const std::string &title)
{
	if (!isAlphaNum(title))
		return;
	mTitle = title;
}

/**
 * Get list's priority (used to sort lists).
 * @return unsigned short | list's priority
**/
unsigned short todo::AList::getPriority() const
{
	return mPriority;
}

/**
 * Set list's priority (used to sort lists).
 * @param const unsigned short & | priority to set
 * @return void
**/
void todo::AList::setPriority(const unsigned short &priority)
{
	mPriority = priority;
}

/**
 * Get list's uuid (used to identify lists).
 * @return std::string | list's uuid
**/
std::string todo::AList::getUUID() const
{
	return mUUID;
}

/**
 * Get list's db id (index in SQL table).
 * @return unsigned int | list's db id
**/
unsigned int todo::AList::getDBiD() const
{
	return mDBiD;
}

/**
 * Set list's db id (index in SQL table) when using SELECT for example.
 * @param const unsigned int &id | the id to set
 * @return void
**/
void todo::AList::setDBiD(const unsigned int &id)
{
	mDBiD = id;
}