/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 18:26:22 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/29 16:29:27 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <exception>
# include <vector>
# include <list>
# include <stack>
# include <algorithm>

struct NotFound: public std::exception
{
	const char *what() const throw() { return ("Not found");}
};

template<typename T>
bool	easyfind(T &arr, int i)
{
	NotFound nf;
	if (std::find(arr.begin(), arr.end(), i) != arr.end())
		return (true);
	throw nf;
}
