/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_prf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 21:21:05 by cbilbo            #+#    #+#             */
/*   Updated: 2021/01/28 17:48:00 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_output_func(t_printf *prf)
{
	prf->output[C] = &output_c;
	prf->output[S] = &output_s;
	prf->output[P] = &output_nbr;
	prf->output[D] = &output_nbr;
	prf->output[I] = &output_nbr;
	prf->output[U] = &output_nbr;
	prf->output[O] = &output_nbr;
	prf->output[LX] = &output_nbr;
	prf->output[UX] = &output_nbr;
	prf->output[PERC] = &output_c;
	prf->output[ERR] = &output_c;
}

void	start_prf(char *string, t_printf *prf)
{
	prf->str = (char*)string;
	prf->str_len = ft_strlen(string);
	prf->num = 0;
	prf->length = 0;
	fill_output_func(prf);
}
