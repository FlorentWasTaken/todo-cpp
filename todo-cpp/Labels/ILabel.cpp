#include "ILabel.hpp"

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