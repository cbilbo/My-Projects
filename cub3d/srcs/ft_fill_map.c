/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 23:09:15 by cbilbo            #+#    #+#             */
/*   Updated: 2021/04/20 15:54:20 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_cub.h"

void	cut_tail(t_list *maplist)
{
	t_list	*mapline;
	int		i;
	char	*line;

	i = 0;
	mapline = maplist;
	if (mapline->next == NULL)
		return ;
	while (mapline->next->next != NULL)
		mapline = mapline->next;
	line = (char *)mapline->next->content;
	while (line[i] != '\0' && ft_isspace(line[i]))
		i++;
	if (line[i] == '\0')
	{
		ft_allocfree((void *)&mapline->next->content);
		ft_allocfree((void *)&mapline->next);
		cut_tail(maplist);
	}
	return ;
}

int	put_map(t_cub *cub, t_list *maplist)
{
	char	**res;
	t_list	*t;
	int		l;
	int		i;

	i = 0;
	t = maplist;
	l = ft_lstsize(maplist);
	res = (char **)ft_calloc(l + 1, sizeof(char *));
	if (!res)
		mem_error(1, cub);
	while (i < l)
	{
		res[i++] = ft_strdup((char *)t->content);
		t = t->next;
	}
	ft_lstclear(&maplist, free);
	cub->map = res;
	return (l);
}

void	check_borders(t_cub *cub, char **map, int l)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (map[y][x] != '\0')
	{
		if (map[y][x] != ' ' && map[y][x] != '1')
			bor_err(cub, ft_strchr("02NSWE", map[y][x]));
		x++;
	}
	x = 0;
	while (y < l - 1)
	{
		if (map[y][x] != ' ' && map[y][x] != '1')
			bor_err(cub, ft_strchr("02NSWE", map[y][x]));
		y++;
	}
	while (map[y][x] != '\0')
	{
		if (map[y][x] != ' ' && map[y][x] != '1')
			bor_err(cub, ft_strchr("02NSWE", map[y][x]));
		x++;
	}
}

void	check_map(t_cub *cub, int l)
{
	int		x;
	int		y;

	y = 0;
	check_borders(cub, cub->map, l);
	while (++y < l - 1)
	{
		x = 0;
		while (cub->map[y][++x] != '\0')
		{
			if (ft_strchr("NSWE", cub->map[y][x]) && cub->plr->p++)
			{
				define_dir(cub, cub->map[y][x]);
				cub->plr->y = y + 0.5;
				cub->plr->x = x + 0.5;
			}
			if (!(ft_strchr(" 012NSWE", cub->map[y][x])))
				map_errors('c', cub);
			if (check_surrounded(cub, cub->map, y, x))
				map_errors('w', cub);
		}
	}
	if (cub->plr->p != 2)
		map_errors('p', cub);
}

void	fill_map(t_cub *cub, int fd)
{
	char	*line;
	t_list	*maplist;
	int		i;

	maplist = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		i = 0;
		while (ft_isspace(line[i]) && !maplist)
			i++;
		if (maplist || line[i] != '\0')
			ft_lstadd_back(&maplist, ft_lstnew(ft_strdup(line)));
		ft_allocfree((void *)&line);
	}
	ft_lstadd_back(&maplist, ft_lstnew(ft_strdup(line)));
	ft_allocfree((void *)&line);
	if (!maplist->next)
		map_errors('i', cub);
	cut_tail(maplist);
	cub->par->maplen = put_map(cub, maplist);
	find_sprites(cub);
	check_map(cub, cub->par->maplen);
}
