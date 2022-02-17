/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 17:09:56 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/29 18:09:23 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <cstdlib>
#include <cmath>

Span	&Span::operator=(const Span &copy)
{
	if (this != &copy)
	{
		_len = copy._len;
		_arr = copy._arr;
	}
	return (*this);
}

void	Span::addNumber(int num)
{
	if (_arr.size() == _len)
		throw _fa;
	_arr.push_back(num);
}

int Span::shortestSpan(void)
{
	if (_arr.size() < 2)
		throw _tle;
	std::vector<int> temp;
	temp = _arr;
	int res = std::abs(temp[0] - temp[1]);
	for (int i = 1, tmp; temp[i + 1] != *temp.end(); ++i)
	{
		tmp = std::abs(temp[i] - temp[i + 1]);
		res = std::min(res, tmp);
	}
	return (res);
}

int Span::longestSpan(void)
{
	if (_arr.size() < 2)
		throw _tle;
	std::vector<int>::iterator min;
	std::vector<int>::iterator max;
	min = std::min_element(_arr.begin(), _arr.end());
	max = std::max_element(_arr.begin(), _arr.end());
	return (*max - *min);
}