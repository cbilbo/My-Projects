/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 20:04:03 by cbilbo            #+#    #+#             */
/*   Updated: 2021/04/19 19:20:22 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_cub.h"

void	define_cf(t_cub *cub, t_map *map)
{
	cub->par->f_color = 0 << 24 | map->f[0] << 16 | map->f[1] << 8 | map->f[2];
	cub->par->c_color = 0 << 24 | map->c[0] << 16 | map->c[1] << 8 | map->c[2];
}

void	define_dir(t_cub *cub, char p)
{
	if (p == 'N')
		cub->plr->dir = 3 * M_PI_2;
	else if (p == 'E')
		cub->plr->dir = 0;
	else if (p == 'S')
		cub->plr->dir = M_PI_2;
	else if (p == 'W')
		cub->plr->dir = M_PI;
	if (p == 'W' || p == 'E')
	{
		cub->ray->plx = 0;
		cub->ray->ply = ft_ter_d(p == 'E', 0.5, -0.5);
	}
	if (p == 'N' || p == 'S')
	{
		cub->ray->ply = 0;
		cub->ray->plx = ft_ter_d(p == 'N', 0.5, -0.5);
	}
	cub->plr->dirx = cos(cub->plr->dir);
	cub->plr->diry = sin(cub->plr->dir);
}

void	my_mlx_pixel_put(t_cub *cub, int x, int y, int color)
{
	char	*dst;

	dst = cub->game->addr + (y * cub->game->l_line + \
		x * (cub->game->bpp / 8));
	*(unsigned int *)dst = color;
}

void	put_wall(t_cub *cub, int x)
{
	int		y;

	y = 0;
	cub->drw->wlen = (int)(cub->par->y / cub->ray->len) *cub->game->cef;
	cub->drw->start = -cub->drw->wlen / 2 + cub->par->y / 2;
	if (cub->drw->start < 0)
		cub->drw->start = 0;
	cub->drw->end = cub->drw->wlen / 2 + cub->par->y / 2;
	if (cub->drw->end >= cub->par->y)
		cub->drw->end = cub->par->y - 1;
	while (y < cub->drw->start)
		my_mlx_pixel_put(cub, x, y++, cub->par->f_color);
	y = ft_txrs(cub, x, y);
	while (y < cub->par->y)
		my_mlx_pixel_put(cub, x, y++, cub->par->c_color);
}

void	draw_screen(t_cub *cub)
{
	int		x;
	t_ray	*ray;

	ray = cub->ray;
	x = -1;
	while (++x < cub->par->x)
	{
		fill_ray(cub, x, ray);
		draw_ray(cub, ray);
		cub->ray->pwd[x] = cub->ray->len;
		put_wall(cub, x);
	}
	ft_spr(cub);
	if (cub->par->save == 1)
		ft_bmp(cub);
	mlx_put_image_to_window(cub->game->mlx, cub->game->win, \
		cub->game->img, 0, 0);
}
