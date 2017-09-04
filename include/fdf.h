/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 14:50:42 by aramon            #+#    #+#             */
/*   Updated: 2017/03/22 18:52:01 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FDF_H
# define FDF_H
# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <math.h>
# include <stdio.h>

# define WIDTH 1920 / 2
# define HEIGHT 1200 / 2
# define LIM 1
# define KROTXU 12
# define KROTXD 0
# define KROTYU 13
# define KROTYD 1
# define KROTZU 14
# define KROTZD 2
# define KMU 126
# define KMD 125
# define KML 123
# define KMR 124
# define KSU 15
# define KSD 3
# define D M_PI / 180.0
# define ROTXU 4 * D
# define ROTXD -(4 * D)
# define ROTYU 4 * D
# define ROTYD -(4 * D)
# define ROTZU 4 * D
# define ROTZD -(4 * D)
# define MU -10
# define MD 10
# define ML -10
# define MR 10
# define SU 1.1
# define SD 0.9
# define KPERS 49
# define FOCAL_DISTANCE 200

typedef struct	s_point
{
	double		x;
	double		y;
	double		z;
	double		w;
}				t_point;

typedef	struct	s_world
{
	t_point		**map;
	int			nb_line;
	int			nb_elem;
	double		cx;
	double		cy;
	double		offx;
	double		offy;
	int			proj;
}				t_world;

typedef	struct	s_mlx
{
	void		*mlx;
	void		*win;
	t_world		*wld;
	void		*img;
	char		*pixel_img;
	int			bpp;
	int			size;
	int			ed;
}				t_mlx;

typedef	struct	s_mat
{
	double		a1;
	double		a2;
	double		a3;
	double		a4;
	double		b1;
	double		b2;
	double		b3;
	double		b4;
	double		c1;
	double		c2;
	double		c3;
	double		c4;
	double		d1;
	double		d2;
	double		d3;
	double		d4;
}				t_mat;

t_point			*read_file(char *str, int nb_elem);
t_point			**open_file(char *file, t_world *wld);
int				get_nb_line(int fd, int *nb_elem);
int				*clean_line(char *line, int nb_elem);

int				get_number_elem(char *line);
void			get_center(t_mlx *mlx);
void			set_center(t_mlx *mlx);
int				get_color(double z);
t_mat			*mat_projection(double f);

t_mlx			*initmlx(char *file);
t_world			*initwld(char *file);
void			initcoord(t_mlx *mlx);
t_mat			*init_mat();

int				key_hook(int keycode, t_mlx *mlx);
void			key_hook_rotation(int keycode, t_mlx *mlx);
void			key_hook_scale(int keycode, t_mlx *mlx);
void			key_hook_translation(int keycode, t_mlx *mlx);
void			key_hook_projection(t_mlx *mlx);

void			draw(t_mlx *mlx);
void			draw_map(t_mlx *mlx);
void			draw_point(t_mlx *mlx, double x, double y, int color);
void			drawlinex(t_mlx *mlx, int i, int j);
void			drawliney(t_mlx *mlx, int i, int j);

t_point			cal_point(t_mat *m, t_point v);
void			cal_map(t_mlx *mlx, t_mat *mat);
void			cal_translation(t_mlx *mlx, double tx, double ty, double tz);
void			cal_rotation(t_mlx *mlx, double ang, char axis);
void			cal_scale(t_mlx *mlx, double s);
void			cal_projection(t_mlx *mlx);

t_mat			*mat_translation(double tx, double ty, double tz);
t_mat			*mat_scale(double s);
t_mat			*mat_rotation_x(double a);
t_mat			*mat_rotation_y(double a);
t_mat			*mat_rotation_z(double a);
#endif
