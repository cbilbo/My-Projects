#include "ASpell.hpp"

ASpell::ASpell(const std::string &name, const std::string &effects) : _name(name), _effects(effects)
{}
ASpell::ASpell(const ASpell &copy)
{
	*this = copy;
}
ASpell &ASpell::operator=(const ASpell &copy)
{
	if (this != &copy)
	{
		_name = copy._name;
		_effects = copy._effects;
	}
	return (*this);
}

std::string const &ASpell::getName(void) const
{
	return (_name);
}

std::string const &ASpell::getEffects(void) const
{
	return (_effects);
}
