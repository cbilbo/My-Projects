/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 18:21:49 by cbilbo            #+#    #+#             */
/*   Updated: 2021/01/28 18:47:37 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printall(t_printf *prf)
{
	while (prf->length < prf->str_len)
	{
		if (prf->str[prf->length] == '%')
			ft_parser(prf);
		else
			prf->num += write(1, &prf->str[prf->length++], 1);
	}
}

int		ft_printf(const char *string, ...)
{
	t_printf	prf;

	start_prf((char*)string, &prf);
	va_start(prf.arg, string);
	printall(&prf);
	va_end(prf.arg);
	return (prf.num);
}
