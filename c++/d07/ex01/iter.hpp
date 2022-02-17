/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 21:07:21 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/24 21:52:53 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

template<typename T>
void	iter(T *arr, int i, void (*f)(T &))
{
	for (int j = 0; j < i; ++j)
	{
		f(arr[j]);
	}
};

template<typename T>
void it(T &i)
{
	i++;
};

template<>
void it(const char &c)
{
	std::cout << c << " ";
};