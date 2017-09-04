/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 16:18:52 by aramon            #+#    #+#             */
/*   Updated: 2017/03/16 16:22:47 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw(t_mlx *mlx)
{
	mlx->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	mlx->pixel_img =
		mlx_get_data_addr(mlx->img, &(mlx->bpp), &(mlx->size), &(mlx->ed));
	draw_map(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	mlx_destroy_image(mlx->mlx, mlx->img);
}

void		draw_map(t_mlx *mlx)
{
	int			i;
	int			j;
	t_point		**map;

	i = 0;
	map = mlx->wld->map;
	mlx_clear_window(mlx->mlx, mlx->win);
	while (i < mlx->wld->nb_line)
	{
		j = 0;
		while (j < mlx->wld->nb_elem)
		{
			if (j != 0)
				drawlinex(mlx, i, j);
			if (i != 0)
				drawliney(mlx, i, j);
			j++;
		}
		i++;
	}
	return ;
}

void		draw_point(t_mlx *mlx, double x, double y, int color)
{
	int		i;

	i = ((int)x * 4) + ((int)y * mlx->size);
	mlx->pixel_img[i] = color;
	mlx->pixel_img[++i] = color >> 8;
	mlx->pixel_img[++i] = color >> 16;
}

void		drawlinex(t_mlx *mlx, int i, int j)
{
	int			neg;
	double		xc;
	double		xt;
	double		yc;
	t_point		**m;

	yc = 0;
	neg = 1;
	m = mlx->wld->map;
	xc = (m[i][j - 1].x <= m[i][j].x ? m[i][j - 1].x : m[i][j].x);
	xt = (m[i][j - 1].x <= m[i][j].x ? m[i][j].x : m[i][j - 1].x);
	neg = (m[i][j - 1].x < m[i][j].x ? 1 : -1);
	if (xt < 0 || xt > WIDTH)
		return ;
	while (xc < xt)
	{
		yc = (xc <= xt ? m[i][j - 1].y + ((m[i][j].y - m[i][j - 1].y) *
			(xc - m[i][j - 1].x)) / (m[i][j].x - m[i][j - 1].x)
			: m[i][j].y + ((m[i][j - 1].y - m[i][j].y) * (xc - m[i][j].x))
			/ (m[i][j - 1].x - m[i][j].x));
		if (xc > LIM && yc > LIM && xc < WIDTH - LIM && yc < HEIGHT - LIM)
			draw_point(mlx, xc, yc, 0x00FFFFFF);
		xc += 0.1;
	}
	return ;
}

void		drawliney(t_mlx *mlx, int i, int j)
{
	int			neg;
	double		yc;
	double		yt;
	double		xc;
	t_point		**m;

	xc = 0;
	neg = 1;
	m = mlx->wld->map;
	yc = (m[i - 1][j].y <= m[i][j].y ? m[i - 1][j].y : m[i][j].y);
	yt = (m[i - 1][j].y <= m[i][j].y ? m[i][j].y : m[i - 1][j].y);
	neg = (m[i - 1][j].y < m[i][j].y ? 1 : -1);
	if (yt < 0 || yt > HEIGHT)
		return ;
	while (yc < yt)
	{
		xc = (yc <= yt ? m[i - 1][j].x + ((m[i][j].x - m[i - 1][j].x) *
			(yc - m[i - 1][j].y)) / (m[i][j].y - m[i - 1][j].y)
			: m[i][j].x + ((m[i - 1][j].x - m[i][j].x) * (yc - m[i][j].y))
			/ (m[i - 1][j].y - m[i][j].y));
		if (xc > LIM && yc > LIM && xc < WIDTH - LIM && yc < HEIGHT - LIM)
			draw_point(mlx, xc, yc, 0x00FFFFFF);
		yc += 0.1;
	}
	return ;
}
