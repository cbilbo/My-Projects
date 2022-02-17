/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 21:48:27 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/21 21:59:05 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <cstdint>
# include <string>

struct Data
{
	std::string _str;
	Data(const std::string &str = "hello") : _str(str) {}
	~Data() {}
};

Data* deserialize(uintptr_t raw);
uintptr_t serialize(Data* ptr);