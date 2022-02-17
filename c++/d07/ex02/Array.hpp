/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 21:53:56 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/28 16:19:44y cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <iostream>
# include <exception>

template<class T>
class Array
{
public:
	Array(): _len(0), _arr(nullptr) {} 
	Array(const unsigned int &n): _len(n), _arr(new T[_len]) {}
	Array(Array<T> const &copy)
	{
		_len = copy._len;
		_arr = new T[_len];
		for (unsigned int i = 0; i < _len; ++i)
			_arr[i] = copy._arr[i];
	}
	T &operator[](const unsigned int &index)
	{
		if (index > _len - 1 || index < 0)
			throw _oor;
		return (_arr[index]);
	}
	unsigned int size(void) const { return (_len);}
	T &operator=(const Array<T> &copy)
	{
		if (*this != &copy)
		{
			_len = copy._len;
			_arr = new T[_len];
			for (unsigned int i = 0; i < _len; ++i)
				_arr[i] = copy._arr[i];
		}
		return (this);
	}
	~Array() { delete [] _arr; }
	struct OutOfRange:public std::exception
	{
		const char *what() const throw()
		{
			return ("Out of range");
		}
	};
private:
	unsigned int _len;
	T *_arr;
	OutOfRange _oor;
};
