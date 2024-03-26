#include "Label.hpp"

todo::Label::Label()
{

}

todo::Label::Label(const std::string &title, const unsigned short &priority, const todo::LabelColor &color)
{
	setTitle(title);
	setPriority(priority);
	setColor(color);
};

todo::Label::~Label()
{

}