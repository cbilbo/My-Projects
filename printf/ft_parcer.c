/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 21:33:55 by cbilbo            #+#    #+#             */
/*   Updated: 2021/01/28 15:31:33 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parser(t_printf *prf)
{
	fill_prf(prf);
	flag_prf(prf);
	width_prf(prf);
	accuracy_prf(prf);
	type_prf(prf);
	prf->output[prf->type](prf);
	prf->length++;
}
