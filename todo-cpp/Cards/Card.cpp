#include "Card.hpp"

todo::Card::Card()
{

}

todo::Card::Card(const std::string &title, const std::string &description)
{
	setTitle(title);
	setDescription(description);
}

todo::Card::~Card()
{

}