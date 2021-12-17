/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 18:55:44 by cbilbo            #+#    #+#             */
/*   Updated: 2021/04/27 19:31:46 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUB_H
# define FT_CUB_H
# include "../libs/libft/libft.h"
# include "../libs/minilibx_opengl/mlx.h"
# include <math.h>
# ifndef MOVE
#  define FORWARD 13
#  define BACK 1
#  define LEFT 0
#  define RIGHT 2
#  define ROTLEFT 123
#  define ROTRIGHT 124
#  define ESC 53
# endif
# define B0000_0000 0
# define B0000_0001 1
# define B0000_0010 2
# define B0000_0100 4
# define B0000_1000 8
# define B0001_0000 16
# define B0010_0000 32
# define B0100_0000 64
# define B1000_0000 128
# define B1111_1111 255
# define FLAG_NONE	B0000_0000
# define FLAG_R		B0000_0001
# define FLAG_NO	B0000_0010
# define FLAG_SO	B0000_0100
# define FLAG_WE	B0000_1000
# define FLAG_EA 	B0001_0000
# define FLAG_S 	B0010_0000
# define FLAG_F 	B0100_0000
# define FLAG_C 	B1000_0000
# define FLAG_ALL	B1111_1111

typedef struct s_game
{
	void			*mlx;
	void			*win;
	void			*img;
	void			*addr;
	double			cef;
	int				l_line;
	int				bpp;
	int				en;
}					t_game;

typedef struct s_plr
{
	int				p;
	double			x;
	double			y;
	double			dir;
	double			dirx;
	double			diry;
	double			start;
	double			end;
	double			spd;
}					t_plr;

typedef struct s_map
{
	int				x;
	int				y;
	char			**path;
	int				f[3];
	int				c[3];
	int				f_color;
	int				c_color;
	unsigned char	flags;
	int				maplen;
	int				save;
}					t_map;

typedef struct s_ray
{
	double			*pwd;
	double			x;
	double			y;
	double			plx;
	double			ply;
	double			rdx;
	double			rdy;
	double			sdx;
	double			sdy;
	double			ddx;
	double			ddy;
	double			len;
	int				mpx;
	int				mpy;
	int				stx;
	int				sty;
	int				side;
}					t_ray;

typedef struct s_draw
{
	int				wlen;
	int				start;
	int				end;
}					t_draw;

typedef struct s_txrs
{
	void			*img;
	int				txh;
	int				txw;
	void			*addr;
	int				l_line;
	int				bpp;
	int				en;
}					t_txrs;

typedef struct s_spr
{
	double			*x;
	double			*y;
	int				num;
	int				*ord;
	double			*dst;
	double			spx;
	double			spy;
	double			ind;
	double			tfx;
	double			tfy;
	int				ssx;
	int				sph;
	int				spw;
	int				dsy;
	int				dsx;
	int				dey;
	int				dex;
}					t_spr;

typedef struct s_cub
{
	char			**map;
	t_map			*par;
	t_game			*game;
	t_plr			*plr;
	t_ray			*ray;
	t_txrs			**txrs;
	t_spr			*spr;
	t_draw			*drw;
}					t_cub;

void				args_errs(char *c, char a, t_cub *cub);
int					primal_errors(int argc, char **argv, int *s);
t_cub				*start_cub(t_cub *c);
void				fill_param(t_cub *cub, int fd);
void				fill_color(int *color, int r, int g, int b);
void				check_color(t_cub *cub, t_map *map, char *line, char *a);
void				fill_res(t_cub *cub, t_map *map, char *line);
char				*miss_unused(t_cub *cub, char *line, int *i, char *c);
void				txturs(t_cub *cub, t_map *map, char *line);
void				fill_textures(t_cub *cub, t_map *map, char *a, char *arg);
void				put_txtrs(t_cub *cub, t_map *map, char *a, char *line);
void				mem_error(int i, t_cub *cub);
void				free_and_null(char **line);
void				fill_map(t_cub *cub, int fd);
void				map_errors(char c, t_cub *cub);
void				cut_tail(t_list *maplist);
int					put_map(t_cub *cub, t_list *maplist);
int					check_surrounded(t_cub *cub, char **map, int y, int x);
void				my_mlx_pixel_put(t_cub *cub, int x, int y, int color);
void				define_dir(t_cub *cub, char p);
void				my_mlx_pixel_put(t_cub *cub, int x, int y, int color);
void				draw_ray(t_cub *cub, t_ray *ray);
void				draw_screen(t_cub *cub);
int					key_hook(int key, t_cub *cub);
void				ft_cub(t_cub *cub);
void				fill_ray(t_cub *cub, int x, t_ray *ray);
int					ft_txrs(t_cub *cub, int x, int y);
void				txtr_init(t_cub *cub);
int					my_mlx_pixel_get(t_txrs *txtrs, int x, int y);
void				ray_len(t_cub *cub, t_ray *ray);
void				bor_err(t_cub *cub, char *s);
void				find_sprites(t_cub *cub);
void				ft_spr(t_cub *cub);
void				spr_sort(t_cub *cub);
void				spr_swap(t_cub *cub, int j);
int					exit_t(t_cub *cub);
void				ft_bmp(t_cub *cub);
void				define_cf(t_cub *cub, t_map *map);

#endif
