/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 21:13:25 by cbilbo            #+#    #+#             */
/*   Updated: 2021/04/20 20:02:49 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_cub.h"

void	spr_sort(t_cub *cub)
{
	int	i;
	int	j;

	i = -1;
	while (++i < cub->spr->num)
	{
		cub->spr->ord[i] = i;
		cub->spr->dst[i] = ((cub->plr->x - cub->spr->x[i]) * (cub->plr->x \
			- cub->spr->x[i]) + (cub->plr->y - cub->spr->y[i]) * (cub->plr->y \
			- cub->spr->y[i]));
	}
	i = -1;
	while (++i < cub->spr->num)
	{
		j = -1;
		while (++j < cub->spr->num - 1)
		{
			if (cub->spr->dst[j] < cub->spr->dst[j + 1])
				spr_swap(cub, j);
		}
	}
}

void	find_sprites(t_cub *cub)
{
	int	x;
	int	y;

	y = 0;
	while (++y < cub->par->maplen - 1)
	{
		x = 0;
		while (cub->map[y][++x] != '\0')
		{
			if (cub->map[y][x] == '2')
				cub->spr->num++;
		}
	}
	cub->spr->x = (double *)ft_calloc(cub->spr->num, sizeof(double));
	cub->spr->y = (double *)ft_calloc(cub->spr->num, sizeof(double));
	if (!cub->spr->x || !cub->spr->y)
		mem_error(1, cub);
}

void	spr_calc(t_cub *cub, int i)
{
	cub->spr->spx = cub->spr->x[cub->spr->ord[i]] - cub->plr->x;
	cub->spr->spy = cub->spr->y[cub->spr->ord[i]] - cub->plr->y;
	cub->spr->ind = 1.0 / (cub->ray->plx *cub->plr->diry - \
		cub->plr->dirx *cub->ray->ply);
	cub->spr->tfx = cub->spr->ind *(cub->plr->diry *cub->spr->spx - \
		cub->plr->dirx *cub->spr->spy);
	cub->spr->tfy = cub->spr->ind *(-cub->ray->ply *cub->spr->spx + \
		cub->ray->plx *cub->spr->spy);
	cub->spr->ssx = (int)((cub->par->x /2) *(1 + cub->spr->tfx /cub->spr->tfy));
	cub->spr->sph = abs((int)(cub->par->y / (cub->spr->tfy))) * cub->game->cef;
	cub->spr->spw = abs((int)(cub->par->y / (cub->spr->tfy))) * cub->game->cef;
	cub->spr->dsy = -cub->spr->sph / 2 + cub->par->y / 2;
	if (cub->spr->dsy < 0)
		cub->spr->dsy = 0;
	cub->spr->dsx = -cub->spr->spw / 2 + cub->spr->ssx;
	if (cub->spr->dsx < 0)
		cub->spr->dsx = 0;
	cub->spr->dey = cub->spr->sph / 2 + cub->par->y / 2;
	if (cub->spr->dey >= cub->par->y)
		cub->spr->dey = cub->par->y - 1;
	cub->spr->dex = cub->spr->spw / 2 + cub->spr->ssx;
	if (cub->spr->dex >= cub->par->x)
		cub->spr->dex = cub->par->x - 1;
}

void	draw_spr(t_cub *cub, int spx, int str, int col)
{
	int	d;
	int	spy;
	int	color;

	d = (col) * 256 - cub->par->y *128 + cub->spr->sph *128;
	spy = ((d * cub->txrs[4]->txh) / cub->spr->sph) / 256;
	color = my_mlx_pixel_get(cub->txrs[4], spx, spy);
	if (color != 0x980088)
		my_mlx_pixel_put(cub, str, col, color);
}

void	ft_spr(t_cub *cub)
{
	int	i;
	int	str;
	int	col;
	int	spx;

	i = -1;
	spr_sort(cub);
	while (++i < cub->spr->num)
	{
		spr_calc(cub, i);
		str = cub->spr->dsx - 1;
		while (++str < cub->spr->dex)
		{
			spx = (int)(256 *(str -(-cub->spr->spw / 2 + cub->spr->ssx)) \
				*cub->txrs[4]->txw / cub->spr->spw) / 256;
			col = cub->spr->dsy - 1;
			if (cub->spr->tfy > 0 && str > 0 && str < cub->par->x && \
				cub->spr->tfy < cub->ray->pwd[str])
			{
				while (++col < cub->spr->dey)
					draw_spr(cub, spx, str, col);
			}
		}
	}
}
