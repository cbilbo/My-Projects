/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 01:47:18 by cbilbo            #+#    #+#             */
/*   Updated: 2021/04/27 18:34:21 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_cub.h"

void	fill_res(t_cub *cub, t_map *map, char *line)
{
	int		i;

	i = 0;
	line++;
	if (map->flags & FLAG_R)
		args_errs("R", 'd', cub);
	while (*line != '\0')
	{
		line = miss_unused(cub, line, &i, "R");
		if ((i != 1 && i != 2) || (map->x > 0 && i == 1))
			args_errs("R", 'i', cub);
		if (i == 1)
			map->x = ft_atoi(line);
		if (i == 2 && map->y < 0)
			map->y = ft_atoi(line);
		while (*line != ' ' && *line != '\t' && *line != '\0' && *line != ',' \
			&& *line != 'x' && *line != 'X' && ft_isdigit(*line))
			line++;
	}
	map->flags = map->flags | FLAG_R;
	if (map->x < -1 || map->y < -1 || map->y == 0 || map->x == 0)
		args_errs("R", 'i', cub);
}

static void	f_color(t_cub *cub, t_map *map, char *line, char *a)
{
	int		i[3];
	int		j;
	int		l;

	j = -1;
	fill_color(i, -1, -1, -1);
	while (*line != '\0')
	{
		line = miss_unused(cub, line, &j, a);
		if (j < 0 || j > 2 || (i[j] > 0 && (j == 0 || j == 1)))
			args_errs(a, 'i', cub);
		i[j] = ft_ter_i(*line == '\0', i[j], ft_atoi(line));
		if (i[j] < 0 || i[j] > 255)
			args_errs(a, 'i', cub);
		l = ft_nbrlen(i[j]);
		if (i[j] == 0)
			l += ft_ter_i(*line == '-', 1, 0);
		line = line + ft_ter_i(*line == '\0', 0, l);
	}
	if (a[0] == 'F')
		fill_color(map->f, i[0], i[1], i[2]);
	else
		fill_color(map->c, i[0], i[1], i[2]);
	if (j < 2 && *line == '\0')
		args_errs(a, 'i', cub);
}

void	check_color(t_cub *cub, t_map *map, char *line, char *a)
{
	if (map->flags & ft_ter_i(a[0] == 'F', FLAG_F, FLAG_C))
		args_errs(a, 'd', cub);
	f_color(cub, map, ++line, a);
	map->flags = map->flags | ft_ter_i(a[0] == 'F', FLAG_F, FLAG_C);
}

void	txturs(t_cub *cub, t_map *map, char *line)
{
	char	a[3];
	char	*args;
	int		i;

	i = -1;
	while (i != 2 && line[++i] != ' ' && line[i] != '\t')
		a[i] = line[i];
	a[i] = '\0';
	if (!(ft_strchr("NSWE", a[0])) || (line[i] != ' ' && line[i] != '\t'))
		args_errs(line, 'u', cub);
	put_txtrs(cub, map, a, line);
	while (*line != ' ' && *line != '\t')
		line++;
	args = ft_strtrim(line, " \t\"\'");
	fill_textures(cub, map, a, args);
}
