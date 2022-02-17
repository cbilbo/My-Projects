#include <fstream>
#include <iostream>
#include <string>

int	replace(std::string file, std::string s1, std::string s2)
{
	std::string		str;
	unsigned long	 i;

	std::ifstream	in(file);
	if (!in.is_open())
	{
		std::cout << "Can't open file" << std::endl;
		return (0);
	}
	std::ofstream	out(file + ".replace");
	if (!out.is_open())
	{
		std::cout << "Can't create file" << std::endl;
		return (0);
	}
	while (std::getline(in, str))
	{
		i = 0;
		while ((i = str.find(s1, i)) != std::string::npos)
		{
			str.erase(i, s1.length());
			str.insert(i, s2);
			i += s2.length();
		}
		out << str;
		std::getline(in, str);
		if (!in.eof())
			out << "\n";
	}
	in.close();
	out.close();
	return (0);
}

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Wrong number of arguments!" << std::endl;
		return (1);
	}
	if (!av[2] || !av[3])
	{
		std::cout << "Empty string(s)!" << std::endl;
		return (1);
	}
	return(replace(av[1], av[2], av[3]));
}