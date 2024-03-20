#include "ICard.hpp"

/**
 * Get card's title.
 * @return std::string | card's title
**/
std::string todo::ACard::getTitle() const
{
	return mTitle;
}

/**
 * Set card's title (only accept alphabetic and/or numeric characters).
 * @param const std::string & | title to set
 * @return void
**/
void todo::ACard::setTitle(const std::string &title)
{
	if (!isAlphaNum(title))
		return;
	mTitle = title;
}

/**
 * Get card's description.
 * @return std::string | card's description
**/
std::string todo::ACard::getDescription() const
{
	return mDescription;
}

/**
 * Set card's description.
 * @param const std::string & | description to set
 * @return void
**/
void todo::ACard::setDescription(const std::string &description)
{
	mDescription = description;
}

/**
 * Get card's start date (UNIX timestamp).
 * @return unsigned int | card's start date
**/
unsigned int todo::ACard::getStartDate() const
{
	return mStartDate;
}

/**
 * Set card's start date (UNIX timestamp).
 * @param const unsigned int & | date to set
 * @return void
**/
void todo::ACard::setStartDate(const unsigned int &date)
{
	mStartDate = date;
}

/**
 * Get card's due date (UNIX timestamp).
 * @return unsigned int | card's due date
**/
unsigned int todo::ACard::getDueDate() const
{
	return mDueDate;
}

/**
 * Set card's due date (UNIX timestamp).
 * @param const unsigned int & | date to set
 * @return void
**/
void todo::ACard::setDueDate(const unsigned int &date)
{
	mDueDate = date;
}