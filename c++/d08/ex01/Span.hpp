/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 16:56:17 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/29 18:19:53 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <vector>
# include <exception>

class Span
{
public:
	Span(unsigned int len = 0) : _len(len) {}
	Span(const Span &copy) : _len(copy._len), _arr(copy._len) {}
	Span &operator=(const Span &copy);
	void addNumber(int num);
	int shortestSpan(void);
	int longestSpan(void);

	template<typename T>
	void addNumber(T first, T last)
	{
		while (first != last)
		{
			if (_arr.size() == _len)
				throw _fa;
			_arr.push_back(*first);
			first++;
		}
	}

private:
	unsigned int _len;
	std::vector<int> _arr;
	class FullArray: public std::exception
	{
		const char *what() const throw() { return ("Array is full!");}
	};
	class TooLowElements: public std::exception
	{
		const char *what() const throw() { return ("Too low elements!");}
	};
	FullArray _fa;
	TooLowElements _tle;
};