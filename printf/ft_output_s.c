/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 23:26:51 by cbilbo            #+#    #+#             */
/*   Updated: 2021/01/28 19:14:45 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	s_with_acc(char *str, int len, t_printf *prf)
{
	char	space;

	space = (prf->zero == 1) ? '0' : ' ';
	if (len < prf->accuracy)
		prf->accuracy = len;
	if (prf->width < prf->accuracy)
		prf->width = prf->accuracy;
	if (prf->minus == 1)
	{
		prf->num += ft_putstrl(str, prf->accuracy);
		prf->num += ft_putcharl(' ', prf->width - prf->accuracy);
	}
	else
	{
		prf->num += ft_putcharl(space, prf->width - prf->accuracy);
		prf->num += ft_putstrl(str, prf->accuracy);
	}
}

void	s_without_acc(char *str, int len, t_printf *prf)
{
	char	space;

	space = (prf->zero == 1) ? '0' : ' ';
	if (len < prf->width)
		prf->accuracy = prf->width - len;
	else
		prf->accuracy = 0;
	if (prf->minus == 1)
	{
		prf->num += ft_putstrl(str, len);
		prf->num += ft_putcharl(' ', prf->accuracy);
	}
	else
	{
		prf->num += ft_putcharl(space, prf->accuracy);
		prf->num += ft_putstrl(str, len);
	}
}

void	output_s(t_printf *prf)
{
	char	*str;
	int		len;

	if (!(str = va_arg(prf->arg, char *)))
		str = "(null)";
	len = ft_strlen(str);
	if (prf->accuracy >= 0)
		s_with_acc(str, len, prf);
	else
		s_without_acc(str, len, prf);
}
