/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 18:55:26 by cbilbo            #+#    #+#             */
/*   Updated: 2021/04/26 19:48:34 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_cub.h"

static void	f_exit(t_cub *cub)
{
	ft_allocfree((void *)&cub->spr->x);
	ft_allocfree((void *)&cub->spr->y);
	ft_allocfree((void *)&cub->spr->dst);
	ft_allocfree((void *)&cub->spr->ord);
	ft_allocfree((void *)&cub->ray->pwd);
	ft_allocfree((void *)&cub->map);
	ft_allocfree((void *)&cub->ray);
	ft_allocfree((void *)&cub->spr);
	ft_allocfree((void *)&cub->drw);
	ft_allocfree((void *)&cub->plr);
	ft_allocfree((void *)&cub->game);
	ft_allocfree((void *)&cub->par);
	ft_allocfree((void *)&cub);
}

int	exit_t(t_cub *cub)
{
	int		i;

	i = -1;
	while (++i < 5)
	{
		ft_allocfree((void *)&cub->par->path[i]);
		ft_allocfree((void *)&cub->txrs[i]);
	}
	if (cub->game->mlx != NULL)
	{
		mlx_destroy_image(cub->game->mlx, cub->game->img);
		mlx_destroy_window(cub->game->mlx, cub->game->win);
	}
	ft_allocfree((void *)&cub->txrs);
	ft_allocfree((void *)&cub->par->path);
	f_exit(cub);
	exit(0);
}

static void	resolution(t_cub *cub)
{
	int	h;
	int	w;

	mlx_get_screen_size(&w, &h);
	if (cub->par->x == 0 || cub->par->y == 0)
	{
		printf("Error\nInvalid 'R' argument\n");
		exit_t(cub);
	}
	if (cub->par->x > w || cub->par->x == -1)
		cub->par->x = w;
	if (cub->par->y > h || cub->par->y == -1)
		cub->par->y = h;
}

void	ft_cub(t_cub *cub)
{
	t_game	*game;

	game = cub->game;
	resolution(cub);
	game->mlx = mlx_init();
	game->img = mlx_new_image(game->mlx, cub->par->x, cub->par->y);
	game->addr = mlx_get_data_addr(game->img, &game->bpp, \
		&game->l_line, &game->en);
	game->win = mlx_new_window(game->mlx, cub->par->x, cub->par->y, "cub3D");
	game->cef = (double)cub->par->x / (double)cub->par->y;
	txtr_init(cub);
	define_cf(cub, cub->par);
	draw_screen(cub);
	mlx_hook(cub->game->win, 02, 1L << 0, &key_hook, cub);
	mlx_hook(cub->game->win, 17, 1L << 17, &exit_t, cub);
	mlx_loop(cub->game->mlx);
}

int	main(int argc, char **argv)
{
	t_cub	*cub;
	int		fd;
	int		s;

	cub = NULL;
	s = 1;
	fd = primal_errors(argc, argv, &s);
	cub = start_cub(cub);
	cub->par->save = s - 1;
	fill_param(cub, fd);
	ft_cub(cub);
	return (0);
}
