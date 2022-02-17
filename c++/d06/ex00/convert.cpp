/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:19:49 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/28 17:07:22 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"
#include <sstream>
#include <limits>
#include <iostream>
#include <iomanip>

convert::convert(const std::string &str) : _str(str)
{
	check_exception();
	if (_str.length() == 1)
	{
		int tmp = static_cast<int>(_str[0]);
		if ((tmp >= 48) && (tmp <= 57)) 
		{
			_type = false;
			from_int();
		}
		else
		{
			_type = false;
			from_char();
		}
	}
	else
	{
		size_t tmp;	
		int i = (_str[0] == '-' ? 1 : 0);
		if (_str.find_first_not_of("0123456789.f", i) == std::string::npos)
		{
			if ((tmp = _str.find('.', i)) == std::string::npos)
			{
				if (_str.find('f', i) == std::string::npos)
				{
					_type = false;
					from_int();
				}
				else if((tmp = _str.find('f', i) == _str.length() - 1))
				{
					_type = true;
					from_float();
				}
				else
					throw _err;
			}
			else if (_str.find('.', tmp + 1) == std::string::npos)
			{
				if ((tmp = _str.find('f', i)) == std::string::npos)
				{
					_type = true;
					from_double();
				}
				else if (tmp == _str.length() - 1)
				{
					_type = true;
					from_float();
				}
				else
					throw _err;
			}
			else
				throw _err;
		}
		else
			throw _err;
	}
}

void	convert::from_char()
{
	std::stringstream tmp;
	_c = static_cast<char>(_str[0]);
	_i = static_cast<int>(_c);
	_f = static_cast<float>(_c);
	_d = static_cast<double>(_c);
}

void	convert::from_int()
{
	std::stringstream temp;
	long double i;
	temp << _str;
	temp >> i;
	_i = static_cast<int>(i);
	if (_i != i)
		throw _ub;
	_c = static_cast<char>(_i);
	_f = static_cast<float>(_i);
	_d = static_cast<double>(_i);
	if (_i < 0)
	{
		if (_str.length() - 2 > 6)
			_type = true;
	}
	else
		if (_str.length() - 1 > 6)
			_type = true;
}

void	convert::from_float()
{
	_str.erase(_str.end() - 1);
	while (_str[_str.length() - 1] == '0')
		_str.erase(_str.end() - 1);	
	if (_str.find('.') == std::string::npos || _str[_str.length() - 1] == '.')
		_type = false;
	std::stringstream temp;
	float f;
	temp << _str;
	temp >> f;
	if (f < std::numeric_limits<float>::min() || f > std::numeric_limits<float>::max())
		throw _ub;
	_f = static_cast<float>(f);
	_i = static_cast<int>(_f);
	_c = static_cast<char>(_f);
	_d = static_cast<double>(_f);
	if (_str.length() - 1 > 6)
		_type = true;
}

void	convert::from_double()
{
	while (_str[_str.length() - 1] == '0')
		_str.erase(_str.end() - 1);	
	if (_str[_str.length() - 1] == '.')
		_type = false;
	std::stringstream temp;
	temp << _str;
	temp >> _d;
	if (_d < std::numeric_limits<double>::min() || _d > std::numeric_limits<double>::max())
		throw _ub;
	_i = static_cast<int>(_d);
	_c = static_cast<char>(_d);
	_f = static_cast<float>(_d);
	if (_str.length() - 1 > 6)
		_type = true;
}



void	convert::check_exception()
{
	std::string pseudo[6] = {"nanf", "nan", "+inff", "+inf", "-inff", "-inf"};
	int ps = 0;
	for (; ps < 6; ++ps)
	{
		if (!_str.compare(pseudo[ps]))
		{
			break;
		}
	}
	switch (ps)
	{
		case 0:
		case 1:
			throw _nan;
		case 2:
		case 3:
			throw _pi;
		case 4:
		case 5:
			throw _mi;
		default:
			break;
	}
}

char convert::getChar(void) const
{
	if (!::isascii(_i))
		throw _imp;
	else if (!::isprint(_i))
		throw _nd;
	return (_c);
}

int convert::getInt(void) const
{
	if ((std::atoi(_str.c_str()) == -1 && _str[0] != '-'))
		throw _imp;
 	if (std::atoi(_str.c_str()) == 0 && _str[0] == '-')
	 	throw _imp;
	return (_i);
}

float convert::getFloat(void) const
{
	return (_f);
}

double convert::getDouble(void) const
{
	return (_d);
}

const char	*convert::exceptionNan::what() const throw()
{
	return ("char: impossible\nint: impossible\nfloat: nanf\ndouble: nan\n");
}

const char	*convert::exceptionPlusinf::what() const throw()
{
	return ("char: impossible\nint: impossible\nfloat: +inff\ndouble: +inf\n");
}

const char	*convert::exceptionMininf::what() const throw()
{
	return ("char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf\n");
}

const char	*convert::exceptionErr::what() const throw()
{
	return ("Invalid parameter\n");
}

const char	*convert::exceptionImp::what() const throw()
{
	return ("impossible");
}

const char	*convert::exceptionUb::what() const throw()
{
	return ("char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n");
}

const char	*convert::exceptionNd::what() const throw()
{
	return ("Non Displayable");
}

std::ostream	&operator<<(std::ostream &os, const convert &con)
{
	os << "char: ";
	try
	{
		char c = con.getChar();
		os << "\'" << c << "\'";
	}
	catch(const std::exception& e)
	{
		os << e.what();
	}
	os << "\nint: ";
	try
	{
		os << con.getInt();
	}
	catch(const std::exception& e)
	{
		os << e.what();
	}
	os << "\nfloat: ";
	try
	{
		os << con.getFloat();
		if (!con.getType())
			os << ".0";
		os << "f";
	}
	catch(const std::exception& e)
	{
		os << e.what();
	}
	os << "\ndouble: ";
	try
	{
		os << con.getDouble();
		if (!con.getType())
			os << ".0";
	}
	catch(const std::exception& e)
	{
		os << e.what();
	}
	os << std::endl;
	return (os);
}
