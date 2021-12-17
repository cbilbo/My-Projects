/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 21:02:53 by cbilbo            #+#    #+#             */
/*   Updated: 2021/04/27 18:44:36 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_cub.h"

void	mem_error(int i, t_cub *cub)
{
	if (i == 1)
		printf("Error\nMemory error\n");
	exit_t(cub);
}

void	map_errors(char c, t_cub *cub)
{
	if (c == 'i')
		write(1, "Error\nInvalid map\n", 19);
	else if (c == 'w')
		write(1, "Error\nNot closed map\n", 22);
	else if (c == 'c')
		write(1, "Error\nUnknown character in map\n", 32);
	else if (c == 'p')
		write(1, "Error\nWrong number of players\n", 31);
	exit_t(cub);
}

int	primal_errors(int argc, char **argv, int *s)
{
	int		i;
	int		l;
	int		fd;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (argc != 2 && argc != 3)
		i = write(1, "Error\nWrong number of arguments\n", 33);
	else
	{
		l = ft_strlen(argv[1]);
		if (l < 4 || fd == -1)
			i = write(1, "Error\nInvalid map\n", 19);
		else if (argv[1][l - 1] != 'b' || argv[1][l - 2] != 'u' \
			|| argv[1][l - 3] != 'c' || argv[1][l - 4] != '.')
			i = write(1, "Error\nWrong extension of map\n", 30);
		if (i == 0 && argc == 3 && (*s)++ && ft_strcmp(argv[2], "--save"))
			i = write(1, \
				"Error\nTo save screen type \"--save\" after map\n", 46);
		if (i == 0)
			return (fd);
	}
	close(fd);
	exit(0);
	return (fd);
}

void	args_errs(char *c, char a, t_cub *cub)
{
	if (c && (c[0] == '1' || c[0] == '0'))
		printf("Error\nNot enough arguments\n");
	else if (a == 'd')
		printf("Error\nToo much '%s' args in map\n", c);
	else if (a == 'i')
		printf("Error\nInvalid '%s' argument\n", c);
	else if (a == 'u')
		printf("Error\nUnknown argument\n");
	else if (a == 't')
		printf("Error\nInvalid '%s' texture file\n", c);
	else if (a == 'o')
		printf("Error\n'%s' texture file don't open\n", c);
	else if (a == 's')
		printf("Error\nTo save screen type \"--save\" after map\n");
	exit_t(cub);
}

void	bor_err(t_cub *cub, char *s)
{
	if (s)
		map_errors('w', cub);
	map_errors('c', cub);
}
