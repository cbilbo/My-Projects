#pragma once
#include <string>
class ASpell
{
	protected:
		std::string _name;
		std::string _effects;
	public:
		ASpell(std::string const &name, std::string const &effects);
		ASpell(const ASpell &copy);
		ASpell &operator=(const ASpell &copy);
		std::string const &getName(void) const;
		std::string const &getEffects(void) const;
		virtual ASpell *clone() = 0;
};