/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 18:25:55 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/29 16:37:42 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>

int main(void)
{
	std::vector<int> vec;
	std::list<int> lst;
	std::deque<int> deq;
	std::set<int> st;
	for (int i = 6; i > 0; --i)
	{
		vec.push_back(i);
		lst.push_back(i);
		deq.push_back(i);
		st.insert(i);
	}
	try
	{
		if (easyfind(vec, 2))
			std::cout << "int 2 has in vector" << std::endl;
		if (easyfind(vec, -1))
			std::cout << "int -1 has in vector" << std::endl;
		if (easyfind(vec, 9))
			std::cout << "int 9 has in vector" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		if (easyfind(lst, 2))
			std::cout << "int 2 has in list" << std::endl;
		if (easyfind(lst, -1))
			std::cout << "int -1 has in list" << std::endl;
		if (easyfind(lst, 9))
			std::cout << "int 9 has in list" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		if (easyfind(deq, 2))
			std::cout << "int 2 has in deque" << std::endl;
		if (easyfind(deq, -1))
			std::cout << "int -1 has in deque" << std::endl;
		if (easyfind(deq, 9))
			std::cout << "int 9 has in deque" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		if (easyfind(st, 2))
			std::cout << "int 2 has in set" << std::endl;
		if (easyfind(st, -1))
			std::cout << "int -1 has in set" << std::endl;
		if (easyfind(st, 9))
			std::cout << "int 9 has in set" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
