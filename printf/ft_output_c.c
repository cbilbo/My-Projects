/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 21:11:05 by cbilbo            #+#    #+#             */
/*   Updated: 2021/01/28 17:59:14 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	output_c(t_printf *prf)
{
	int		c;
	char	space;

	space = (prf->zero && !prf->minus) ? '0' : ' ';
	if (prf->type == ERR)
		c = prf->str[prf->length];
	else
		c = (prf->type == PERC) ? '%' : va_arg(prf->arg, int);
	if (prf->type == ERR && prf->length == prf->str_len)
		return ;
	if (prf->width > 0)
	{
		if (prf->minus == 1)
		{
			prf->num += write(1, &c, 1);
			prf->num += ft_putcharl(space, prf->width - 1);
		}
		else
		{
			prf->num += ft_putcharl(space, prf->width - 1);
			prf->num += write(1, &c, 1);
		}
	}
	else
		prf->num += write(1, &c, 1);
}
