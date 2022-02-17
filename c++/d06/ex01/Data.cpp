/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 21:47:50 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/21 22:03:47 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

uintptr_t serialize(Data* ptr)
{
	uintptr_t res;
	res = reinterpret_cast<uintptr_t>(ptr);
	return (res);
}

Data* deserialize(uintptr_t raw)
{
	Data *res;
	res = reinterpret_cast<Data*>(raw);
	return (res);
}