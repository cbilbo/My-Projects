/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:51:46 by cbilbo            #+#    #+#             */
/*   Updated: 2021/04/20 15:55:29 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_cub.h"

static char	*bmp_header(t_cub *cub, int *size)
{
	char	*header;

	*size = cub->par->x * cub->par->y * 4;
	header = (char *)ft_calloc(54, sizeof(char));
	if (!header)
		mem_error(1, cub);
	header[0] = (unsigned char)('B');
	header[1] = (unsigned char)('M');
	header[2] = (unsigned char)(54 + *size);
	header[3] = (unsigned char)((54 + *size) >> 8);
	header[4] = (unsigned char)((54 + *size) >> 16);
	header[5] = (unsigned char)((54 + *size) >> 24);
	header[10] = (unsigned char)(54);
	header[14] = (unsigned char)(40);
	header[18] = (unsigned char)(cub->par->x);
	header[19] = (unsigned char)(cub->par->x >> 8);
	header[20] = (unsigned char)(cub->par->x >> 16);
	header[21] = (unsigned char)(cub->par->x >> 24);
	header[22] = (unsigned char)(-cub->par->y);
	header[23] = (unsigned char)(-cub->par->y >> 8);
	header[24] = (unsigned char)(-cub->par->y >> 16);
	header[25] = (unsigned char)(-cub->par->y >> 24);
	header[26] = (unsigned char)(1);
	header[28] = (unsigned char)(32);
	return (header);
}

void	ft_bmp(t_cub *cub)
{
	int		fd;
	int		size;
	char	*header;

	size = 0;
	header = bmp_header(cub, &size);
	fd = open("screenshot.bmp", O_CREAT | O_RDWR, S_IRWXU);
	write(fd, header, 54);
	write(fd, (char *)cub->game->addr, size);
	ft_allocfree((void *)&header);
	exit_t(cub);
}
