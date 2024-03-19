#include "ICard.hpp"

std::string todo::ACard::getTitle() const
{
	return mTitle;
}

void todo::ACard::setTitle(const std::string &title)
{
	if (!isAlphaNum(title))
		return;
	mTitle = title;
}

std::string todo::ACard::getDescription() const
{
	return mDescription;
}

void todo::ACard::setDescription(const std::string& description)
{
	if (!isAlphaNum(description))
		return;
	mDescription = description;
}

unsigned int todo::ACard::getStartDate() const
{
	return mStartDate;
}

unsigned int todo::ACard::getDueDate() const
{
	return mDueDate;
}