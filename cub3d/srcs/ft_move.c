/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 20:12:48 by cbilbo            #+#    #+#             */
/*   Updated: 2021/04/19 17:59:13 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_cub.h"

static void	ft_is_wall(t_cub *cub, int i)
{
	if (cub->map[(int)cub->plr->y][(int)cub->plr->x] == '1')
	{
		if (i == 1)
		{
			cub->plr->y += cub->plr->diry * cub->plr->spd;
			cub->plr->x += cub->plr->dirx * cub->plr->spd;
		}
		else if (i == 0)
		{
			cub->plr->y -= cub->plr->diry * cub->plr->spd;
			cub->plr->x -= cub->plr->dirx * cub->plr->spd;
		}
		else if (i == 2)
		{
			cub->plr->y += cub->plr->dirx * cub->plr->spd;
			cub->plr->x -= cub->plr->diry * cub->plr->spd;
		}
		else
		{
			cub->plr->y -= cub->plr->dirx * cub->plr->spd;
			cub->plr->x += cub->plr->diry * cub->plr->spd;
		}
	}
}

static void	rotcam(t_cub *cub, int i)
{
	double		rs;
	double		odx;
	double		opx;

	if (i == ROTRIGHT)
		rs = 0.05;
	else if (i == ROTLEFT)
		rs = -0.05;
	else
		return ;
	odx = cub->plr->dirx;
	cub->plr->dirx = cub->plr->dirx * cos(rs) - cub->plr->diry * sin(rs);
	cub->plr->diry = odx * sin(rs) + cub->plr->diry * cos(rs);
	opx = cub->ray->plx;
	cub->ray->plx = cub->ray->plx * cos(rs) - cub->ray->ply * sin(rs);
	cub->ray->ply = opx * sin(rs) + cub->ray->ply * cos(rs);
}

static void	move_side(t_cub *cub, int key)
{
	if (key == LEFT)
	{
		cub->plr->y -= cub->plr->dirx * cub->plr->spd;
		cub->plr->x += cub->plr->diry * cub->plr->spd;
		ft_is_wall(cub, 2);
	}
	if (key == RIGHT)
	{
		cub->plr->y += cub->plr->dirx * cub->plr->spd;
		cub->plr->x -= cub->plr->diry * cub->plr->spd;
		ft_is_wall(cub, 3);
	}
}

static void	move_straight(t_cub *cub, int key)
{
	if (key == FORWARD)
	{
		cub->plr->y += cub->plr->diry * cub->plr->spd;
		cub->plr->x += cub->plr->dirx * cub->plr->spd;
		ft_is_wall(cub, 0);
	}
	if (key == BACK)
	{
		cub->plr->y -= cub->plr->diry * cub->plr->spd;
		cub->plr->x -= cub->plr->dirx * cub->plr->spd;
		ft_is_wall(cub, 1);
	}
}

int	key_hook(int key, t_cub *cub)
{
	move_straight(cub, key);
	move_side(cub, key);
	rotcam(cub, key);
	if (key == ESC)
		exit_t(cub);
	draw_screen(cub);
	return (0);
}
