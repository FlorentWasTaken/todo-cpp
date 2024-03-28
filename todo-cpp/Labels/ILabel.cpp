#include "ILabel.hpp"

todo::ALabel::ALabel()
{
	mUUID = createUUIDString();
}

/**
 * Get label's title.
 * @return std::string | label's title
**/
std::string todo::ALabel::getTitle() const
{
	return mTitle;
}

/**
 * Set label's title (only accept alphabetic and/or numeric characters).
 * @param const std::string & | title to set
 * @return void
**/
void todo::ALabel::setTitle(const std::string &title)
{
	if (!isAlphaNum(title))
		return;
	mTitle = title;
}

/**
 * Get label's color (RGB).
 * @return todo::LabelColor (struct) | label's color
**/
todo::LabelColor todo::ALabel::getColor() const
{
	return mColor;
}

/**
 * Set label's color (RGB).
 * @param const todo::LabelColor & | color to set
 * @return void
**/
void todo::ALabel::setColor(const todo::LabelColor &color)
{
	mColor = color;
}

/**
 * Get label's priority (used to sort labels).
 * @return unsigned short | label's priority
**/
unsigned short todo::ALabel::getPriority() const
{
	return mPriority;
}

/**
 * Set label's priority (used to sort labels).
 * @param const unsigned short & | priority to set
 * @return void
**/
void todo::ALabel::setPriority(const unsigned short &priority)
{
	mPriority = priority;
}

/**
 * Get label's uuid (used to identify labels).
 * @return std::string | label's uuid
**/
std::string todo::ALabel::getUUID() const
{
	return mUUID;
}

/**
 * Get label's db id (index in SQL table).
 * @return unsigned int | label's db id
**/
unsigned int todo::ALabel::getDBiD() const
{
	return mDBiD;
}

/**
 * Set label's db id (index in SQL table) when using SELECT for example.
 * @param const unsigned int &id | the id to set
 * @return void
**/
void todo::ALabel::setDBiD(const unsigned int& id)
{
	mDBiD = id;
}