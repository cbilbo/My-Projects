/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 18:26:12 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/29 19:28:04 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <stack>
# include <list>
# include <vector>
# include <deque>


template<class T>
class MutantStack: public std::stack<T>
{
public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	MutantStack() : std::stack<T>() {}
	MutantStack(const MutantStack &copy) : std::stack<T>(copy) {}
	MutantStack &operator=(const MutantStack &copy)
	{
		if (this != &copy)
			std::stack<T>::operator=(copy);
		return (*this);
	}
	iterator operator[](int num)
	{
		iterator it = std::stack<T>::c.begin();
		for (int i = 0; i < num; ++i)
			++it;
		return (it);
	}
	iterator begin() {return (std::stack<T>::c.begin());}
	iterator end() {return (std::stack<T>::c.end());}
	~MutantStack() {}
};
