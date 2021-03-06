/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 22:09:35 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/21 22:47:53 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dynamic.hpp"

int main()
{
	Base *d;
	d = generate();
	identify(d);
	identify(*d);
	delete d;
	return (0);
}