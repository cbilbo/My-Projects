/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rays.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 21:02:22 by cbilbo            #+#    #+#             */
/*   Updated: 2021/04/16 17:24:00 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_cub.h"

void	ray_len(t_cub *cub, t_ray *ray)
{
	if (ray->side == 0 || ray->side == 2)
		ray->len = \
			(ray->mpx - cub->plr->x + (1 - ray->stx) / 2) / ray->rdx;
	else
		ray->len = \
			(ray->mpy - cub->plr->y + (1 - ray->sty) / 2) / ray->rdy;
}

void	fill_ray(t_cub *cub, int x, t_ray *ray)
{
	double	pl;

	pl = 2 * x / (double)cub->par->x - 1;
	ray->rdx = cub->plr->dirx + ray->plx * pl;
	ray->rdy = cub->plr->diry + ray->ply * pl;
	ray->mpx = (int)cub->plr->x;
	ray->mpy = (int)cub->plr->y;
	ray->ddx = fabs(1 / ray->rdx);
	ray->ddy = fabs(1 / ray->rdy);
	ray->stx = ft_ter_i(ray->rdx < 0, -1, 1);
	ray->sty = ft_ter_i(ray->rdy < 0, -1, 1);
	if (ray->rdx < 0)
		ray->sdx = (cub->plr->x - ray->mpx) * ray->ddx;
	else
		ray->sdx = (ray->mpx + 1.0 - cub->plr->x) * ray->ddx;
	if (ray->rdy < 0)
		ray->sdy = (cub->plr->y - ray->mpy) * ray->ddy;
	else
		ray->sdy = (ray->mpy + 1.0 - cub->plr->y) * ray->ddy;
}

void	draw_ray(t_cub *cub, t_ray *ray)
{
	while (cub->map[ray->mpy][ray->mpx] != '1')
	{
		if (ray->sdx < ray->sdy)
		{
			ray->sdx += ray->ddx;
			ray->mpx += ray->stx;
			ray->side = ft_ter_i(cub->ray->rdx < 0, 2, 0);
		}
		else
		{
			ray->sdy += ray->ddy;
			ray->mpy += ray->sty;
			ray->side = ft_ter_i(cub->ray->rdy < 0, 3, 1);
		}
	}
	ray_len(cub, ray);
}
