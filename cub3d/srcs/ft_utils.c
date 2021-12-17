/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 01:48:29 by cbilbo            #+#    #+#             */
/*   Updated: 2021/04/27 19:35:39 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_cub.h"

int	check_surrounded(t_cub *cub, char **map, int y, int x)
{
	int	i;

	i = 0;
	if (ft_strchr("2", map[y][x]))
	{
		while (cub->spr->x[i])
			i++;
		cub->spr->x[i] = x + 0.5;
		cub->spr->y[i] = y + 0.5;
	}
	if ((ft_strchr("02NSWE", map[y][x])) && (map[y - 1][x] == ' ' || \
		map[y - 1][x] == '\0' || map[y + 1][x] == ' ' || \
		map[y + 1][x] == '\0' || map[y][x - 1] == ' ' || \
		map[y][x - 1] == '\0' || map[y][x + 1] == ' ' || \
		map[y][x + 1] == '\0' || map[y - 1][x - 1] == ' ' || \
		map[y - 1][x - 1] == '\0' || map[y + 1][x - 1] == ' ' || \
		map[y + 1][x - 1] == '\0' || map[y - 1][x + 1] == ' ' || \
		map[y - 1][x + 1] == '\0' || map[y + 1][x + 1] == ' ' || \
		map[y + 1][x + 1] == '\0'))
		return (1);
	return (0);
}

char	*miss_unused(t_cub *cub, char *line, int *i, char *c)
{
	int	x;
	int	z;

	x = 0;
	z = 0;
	while (((*line == ' ' || *line == '\t') || (*line == ',' && ++z) \
	|| (*line == 'x' && ++x) || (*line == '0' && ft_isdigit(*(line + 1)))))
	{
		if ((*line + 1 == ',' || *line + 1 == 'x' || (*c == 'R' && *i == 2 && \
			(*line == ',' || *line == 'x')) || ((*c == 'F' || *c == 'C') \
			&& *i == 3 && (*line == ',' || *line == 'x'))) || x > 1 || z > 1 \
			|| (z > 0 && x > 0))
			args_errs(c, 'i', cub);
		line++;
	}
	if (*line == '+' && ft_isdigit(*(line + 1)))
	{
		if (i > 0 && ft_isdigit(*(line - 1)))
			args_errs(c, 'i', cub);
		line++;
	}
	if (*line != '\0')
		*i = *i + 1;
	return (line);
}

void	fill_color(int *color, int r, int g, int b)
{
	color[0] = r;
	color[1] = g;
	if (b != -2)
		color[2] = b;
}

void	fill_textures(t_cub *cub, t_map *map, char *a, char *arg)
{
	int	fd;
	int	l;

	fd = open(arg, O_RDONLY);
	l = ft_strlen(arg) - 1;
	if (fd == -1)
		args_errs(a, 'o', cub);
	if (!(ft_strcmp(a, "S")))
		map->path[4] = arg;
	else if (!(ft_strcmp(a, "SO")))
		map->path[2] = arg;
	else if (!(ft_strcmp(a, "NO")))
		map->path[0] = arg;
	else if (!(ft_strcmp(a, "WE")))
		map->path[3] = arg;
	else if (!(ft_strcmp(a, "EA")))
		map->path[1] = arg;
	if (arg[l - 3] != '.' || arg[l - 2] != 'x' || arg[l - 1] != 'p' \
		|| arg[l] != 'm')
		args_errs(a, 't', cub);
	close(fd);
}

void	put_txtrs(t_cub *cub, t_map *map, char *a, char *line)
{
	if (((map->flags & FLAG_S) && a[0] == 'S' && a[1] == '\0') \
		|| ((map->flags & FLAG_SO) && a[0] == 'S' && a[1] == 'O') \
		|| ((map->flags & FLAG_EA) && a[0] == 'E') || \
		((map->flags & FLAG_NO) && a[0] == 'N') || \
		((map->flags & FLAG_WE) && a[0] == 'W'))
		args_errs(a, 'd', cub);
	if (!(ft_strncmp(line, "S ", 2)) || !(ft_strncmp(line, "S\t", 2)))
		map->flags = map->flags | FLAG_S;
	else if (!(ft_strncmp(line, "SO", 2)))
		map->flags = map->flags | FLAG_SO;
	else if (!(ft_strncmp(line, "NO", 2)))
		map->flags = map->flags | FLAG_NO;
	else if (!(ft_strncmp(line, "WE", 2)))
		map->flags = map->flags | FLAG_WE;
	else if (!(ft_strncmp(line, "EA", 2)))
		map->flags = map->flags | FLAG_EA;
	else
		args_errs(0, 'u', cub);
}
