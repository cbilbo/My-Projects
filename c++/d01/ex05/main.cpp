/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:27:06 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/08 16:27:07 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int main(void)
{
	Karen karen;
	karen.complain("debug");
	karen.complain("info");
	karen.complain("warning");
	karen.complain("error");
	karen.complain("Hello");
	return (0); 
}