/* ************************************************************************** */
/*                                                                      	  */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 19:40:01 by aramon            #+#    #+#             */
/*   Updated: 2017/03/16 16:20:53 by aramon           ###   ########.fr       */
/*                                                             				  */
/* ************************************************************************** */

#include "fdf.h"

t_mlx		*initmlx(char *file)
{
	t_mlx		*mlx;

	mlx = (t_mlx*)malloc(sizeof(t_mlx));
	mlx->wld = initwld(file);
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "fdf");
	initcoord(mlx);
	draw(mlx);
	return (mlx);
}

t_world		*initwld(char *file)
{
	t_world		*wldtmp;

	wldtmp = (t_world*)malloc(sizeof(t_world));
	wldtmp->map = open_file(file, wldtmp);
	wldtmp->offx = WIDTH / 2;
	wldtmp->offy = HEIGHT / 2;
	return (wldtmp);
}

void		initcoord(t_mlx *mlx)
{
	int			i;
	int			j;
	t_point		**map;

	i = 0;
	map = mlx->wld->map;
	while (i < mlx->wld->nb_line)
	{
		j = 0;
		while (j < mlx->wld->nb_elem)
		{
			map[i][j].x = j + mlx->wld->offx;
			map[i][j].y = i + mlx->wld->offy;
			map[i][j].w = 1;
			j++;
		}
		i++;
	}
	return ;
}

t_mat		*init_mat(void)
{
	t_mat		*mat;

	if (!(mat = (t_mat*)malloc(sizeof(t_mat))))
		return (NULL);
	mat->a1 = 0;
	mat->a2 = 0;
	mat->a3 = 0;
	mat->a4 = 0;
	mat->b1 = 0;
	mat->b2 = 0;
	mat->b3 = 0;
	mat->b4 = 0;
	mat->c1 = 0;
	mat->c2 = 0;
	mat->c3 = 0;
	mat->c4 = 0;
	mat->d1 = 0;
	mat->d2 = 0;
	mat->d3 = 0;
	mat->d4 = 0;
	return (mat);
}
