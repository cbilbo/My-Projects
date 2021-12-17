/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:46:23 by cbilbo            #+#    #+#             */
/*   Updated: 2020/11/27 16:28:19 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *string)
{
	char	*result;
	size_t	i;

	i = 0;
	while (string[i] != '\0')
		i++;
	if (!(result = (char*)malloc((i + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (string[i] != '\0')
	{
		result[i] = string[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
