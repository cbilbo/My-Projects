#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title) : _name(name), _title(title) 
{
	std::cout << _name << ": This looks like another boring day.\n";
}

void Warlock::setTitle(const std::string &title)
{
	_title = title;
}

void Warlock::introduce ()const
{
	std::cout << _name << ": I am " << _name << ", " << _title << "!\n";
}

std::string const &Warlock::getName(void) const 
{
	return (_name);
}

std::string const &Warlock::getTitle(void) const 
{
	return (_title);
}

Warlock::~Warlock()
{
	std::cout << _name << ": My job here is done!\n";
}