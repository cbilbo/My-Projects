/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_prf.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 21:50:52 by cbilbo            #+#    #+#             */
/*   Updated: 2021/01/28 19:19:50 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base_prf(long number, t_printf *prf)
{
	unsigned char	symbol;

	if (number == 0)
	{
		prf->num += write(1, "0", 1);
		return ;
	}
	if (number < 0)
	{
		prf->num += write(1, "-", 1);
		number = -number;
	}
	if (number >= prf->base)
	{
		ft_putnbr_base_prf(number / prf->base, prf);
		symbol = number % prf->base + \
					(number % prf->base > 9 ? prf->upper - 10 : '0');
		prf->num += write(1, &symbol, 1);
	}
	else
	{
		symbol = number + (number % prf->base > 9 ? prf->upper - 10 : '0');
		prf->num += write(1, &symbol, 1);
	}
}
