/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:19:57 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/21 20:33:04 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <string>
# include <exception>
# include <ostream>

class convert
{
public:
	convert(const std::string &str = "0");
	~convert() {}
	char	getChar(void) const;
	int	getInt(void) const;
	float	getFloat(void) const;
	double	getDouble(void) const;
	std::string getStr(void) const {return _str;}
	bool getType(void) const {return _type;}
private:
	char	_c;
	int		_i;
	float	_f;
	double	_d;
	std::string _str;
	bool		_type;
	struct exceptionNan : public std::exception
	{
		exceptionNan () {}
		~exceptionNan () throw() {}
		const char* what() const throw();
	};
	struct exceptionPlusinf: public std::exception
	{
		exceptionPlusinf() {}
		~exceptionPlusinf() throw() {}
		const char* what() const throw();
	};
	struct exceptionMininf: public std::exception
	{
		exceptionMininf() {}
		~exceptionMininf() throw() {}
		const char* what() const throw();
	};
	struct exceptionErr: public std::exception
	{
		exceptionErr() {}
		~exceptionErr() throw() {}
		const char* what() const throw();
	};
	struct exceptionNd: public std::exception
	{
		exceptionNd() {}
		~exceptionNd() throw() {}
		const char* what() const throw();
	};
	struct exceptionImp: public std::exception
	{
		exceptionImp() {}
		~exceptionImp() throw() {}
		const char* what() const throw();
	};
	struct exceptionUb: public std::exception
	{
		exceptionUb() {}
		~exceptionUb() throw() {}
		const char* what() const throw();
	};
	exceptionNan _nan;
	exceptionPlusinf _pi;
	exceptionMininf	_mi;
	exceptionErr _err;
	exceptionNd _nd;
	exceptionImp _imp;
	exceptionUb _ub;
	void	check_exception();
	void	from_char();
	void	from_int();
	void	from_float();
	void	from_double();
};

std::ostream	&operator<<(std::ostream &os, const convert &con);