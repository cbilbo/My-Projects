/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 01:45:49 by cbilbo            #+#    #+#             */
/*   Updated: 2021/04/20 16:45:15 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_cub.h"

void	fill_par(t_cub *cub)
{
	int	i;

	i = -1;
	cub->par->x = -1;
	cub->par->y = -1;
	cub->par->path = (char **)ft_calloc(5, sizeof(char *));
	while (++i < 5)
	{
		cub->txrs[i] = (t_txrs *)ft_calloc(1, sizeof(t_txrs));
		if (!cub->txrs[i])
			mem_error(1, cub);
	}
	if (!cub->par->path)
		mem_error(1, cub);
	cub->par->flags = FLAG_NONE;
	fill_color(cub->par->f, -1, -1, -1);
	fill_color(cub->par->c, -1, -1, -1);
}

t_cub	*start_cub(t_cub *c)
{
	t_cub	*cub;

	cub = c;
	cub = (t_cub *)ft_calloc(1, sizeof(t_cub));
	cub->par = (t_map *)ft_calloc(1, sizeof(t_map));
	cub->game = (t_game *)ft_calloc(1, sizeof(t_game));
	cub->plr = (t_plr *)ft_calloc(1, sizeof(t_plr));
	cub->drw = (t_draw *)ft_calloc(1, sizeof(t_draw));
	cub->spr = (t_spr *)ft_calloc(1, sizeof(t_spr));
	cub->ray = (t_ray *)ft_calloc(1, sizeof(t_ray));
	cub->txrs = (t_txrs **)ft_calloc(5, sizeof(t_txrs *));
	if (!cub || !cub->par || !cub->game || !cub->plr || !cub->drw || \
		!cub->spr || !cub->ray)
		mem_error(1, cub);
	fill_par(cub);
	cub->map = NULL;
	cub->ray->plx = 0;
	cub->ray->ply = 0.5;
	cub->plr->spd = 0.2;
	cub->plr->p = 1;
	cub->spr->num = 0;
	cub->game->img = NULL;
	cub->game->mlx = NULL;
	cub->game->win = NULL;
	return (cub);
}

void	fill_param(t_cub *cub, int fd)
{
	char	*line;
	char	*f;

	while (get_next_line(fd, &line) > 0 || *line != '\0')
	{
		f = line;
		while (*line == ' ' || *line == '\t')
			line++;
		if (*line == 'R')
			fill_res(cub, cub->par, line);
		else if (*line == 'F' || *line == 'C')
			check_color(cub, cub->par, line, ft_ter_s(*line == 'F', "F", "C"));
		else if (*line != '\0')
			txturs(cub, cub->par, line);
		ft_allocfree((void *)&f);
		if (cub->par->flags == 255)
			fill_map(cub, fd);
	}
	free(line);
	if (cub->par->flags != 255)
		args_errs("1", 'e', cub);
}
