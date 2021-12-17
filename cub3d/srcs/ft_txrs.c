/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_txrs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 16:33:51 by cbilbo            #+#    #+#             */
/*   Updated: 2021/04/20 20:01:28 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_cub.h"

void	spr_swap(t_cub *cub, int j)
{
	ft_swap(&cub->spr->ord[j], &cub->spr->ord[j + 1]);
	ft_swap_d(&cub->spr->dst[j], &cub->spr->dst[j + 1]);
}

int	my_mlx_pixel_get(t_txrs *img, int x, int y)
{
	char	*dst;

	dst = img->addr + (y * img->l_line + x * (img->bpp / 8));
	return (*(unsigned int *)dst);
}

static void	check_txrs(t_cub *cub, int i)
{
	if (i == 0)
		args_errs("NO", 'i', cub);
	if (i == 1)
		args_errs("EA", 'i', cub);
	if (i == 2)
		args_errs("SO", 'i', cub);
	if (i == 3)
		args_errs("WE", 'i', cub);
	if (i == 4)
		args_errs("S", 'i', cub);
}

void	txtr_init(t_cub *cub)
{
	int	i;

	i = -1;
	while (++i < 5)
	{
		cub->txrs[i]->img = mlx_xpm_file_to_image(cub->game->mlx, \
			cub->par->path[i], &cub->txrs[i]->txw, &cub->txrs[i]->txh);
		if (!cub->txrs[i]->img)
			check_txrs(cub, i);
		cub->txrs[i]->addr = mlx_get_data_addr(cub->txrs[i]->img, \
			&cub->txrs[i]->bpp, &cub->txrs[i]->l_line, &cub->txrs[i]->en);
	}
	cub->ray->pwd = (double *)ft_calloc(cub->par->x, sizeof(double));
	cub->spr->dst = (double *)ft_calloc(cub->spr->num, sizeof(double));
	cub->spr->ord = (int *)ft_calloc(cub->spr->num, sizeof(int));
	if (!cub->ray->pwd || !cub->spr->dst || !cub->spr->ord)
		mem_error(1, cub);
}

int	ft_txrs(t_cub *cub, int x, int y)
{
	int		w;
	double	hitw;
	double	step;
	double	tpos;
	int		h;

	if (cub->ray->side == 0 || cub->ray->side == 2)
		hitw = cub->plr->y + cub->ray->len * cub->ray->rdy;
	if (cub->ray->side == 1 || cub->ray->side == 3)
		hitw = cub->plr->x + cub->ray->len * cub->ray->rdx;
	w = cub->txrs[cub->ray->side]->txw * fabs(hitw - floor(hitw));
	step = 1.0 * cub->txrs[cub->ray->side]->txh / cub->drw->wlen;
	tpos = (cub->drw->start - cub->par->y / 2 + cub->drw->wlen / 2) * step;
	while (y < cub->drw->end)
	{
		h = (int)tpos;
		tpos += step;
		my_mlx_pixel_put(cub, x, y++, \
			my_mlx_pixel_get(cub->txrs[cub->ray->side], w, h));
	}
	return (y);
}
