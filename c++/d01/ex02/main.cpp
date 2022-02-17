/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 19:18:36 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/09 20:18:51 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "Adress\nstr: " << &str << std::endl << "stringPTR: " << stringPTR << std::endl << "stringREF: " << &stringREF << std::endl;
	std::cout << "Data\nstr: " << str << std::endl << "stringPTR: " << *stringPTR << std::endl << "stringREF: " << stringREF << std::endl;
}