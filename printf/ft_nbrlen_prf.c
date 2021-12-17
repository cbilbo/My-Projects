/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_prf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 20:29:51 by cbilbo            #+#    #+#             */
/*   Updated: 2021/01/28 15:40:03 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_nbrlen_prf(long nbr, t_printf *prf)
{
	int len;

	len = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		len++;
	}
	if ((nbr / prf->base) != 0)
		len += ft_nbrlen_prf(nbr / prf->base, prf);
	len++;
	return (len);
}
