
#pragma once
# include <string>
# include <iostream>

class Warlock
{
private:
	std::string _name;
	std::string _title;
	Warlock();
	Warlock(const Warlock &copy);
	Warlock &operator=(const Warlock &copy);
public:
	Warlock(const std::string &name, const std::string &title);
	void setTitle(const std::string &title);
	void introduce ()const;
	std::string const &getName(void) const;
	std::string const &getTitle(void) const;
	~Warlock();
};