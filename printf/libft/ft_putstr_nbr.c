/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 22:27:14 by cbilbo            #+#    #+#             */
/*   Updated: 2021/01/21 22:38:25 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putstr_nbr(char *s)
{
	int		i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
		i += ft_putchar_nbr(s[i]);
	return (i);
}
