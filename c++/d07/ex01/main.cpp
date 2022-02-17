/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 21:10:19 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/24 21:50:44 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

int main(void)
{
	int i[5] = {0, 1, 2, 3, 4};
	double d[5] = {0.1, 1.2, 2.3, 3.4, 4.5};
	char s[] = {'a', 'b', 'c', 'd', 'e'};
	std::string a("hello");
	::iter(a.c_str(), 5, it);
	std::cout << std::endl;
	::iter(i, 5, it);
	::iter(d, 5, it);
	::iter(s, 5, it);
	for (int j = 0; j < 5; ++j)
	{
		std::cout << i[j] << " " << d[j] << " " << s[j] << std::endl;
	}
	return (0);
}