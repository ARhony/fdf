/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 20:00:08 by aramon            #+#    #+#             */
/*   Updated: 2017/03/17 20:39:52 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			get_number_elem(char *line)
{
	int		i;
	int		nb_elem;

	i = 0;
	nb_elem = 0;
	while (line[i] != '\0')
	{
		if (line[i] != ' ' && (line[i + 1] == ' ' || line[i + 1] == '\0'))
			nb_elem++;
		i++;
	}
	return (nb_elem);
}

void		set_center(t_mlx *mlx)
{
	int			i;
	int			j;
	double		midx;
	double		midy;
	t_world		*env;

	i = 0;
	env = mlx->wld;
	midx = env->map[(env->nb_line - 1) / 2][(env->nb_elem - 1) / 2].x;
	midy = env->map[(env->nb_line - 1) / 2][(env->nb_elem - 1) / 2].y;
	while (i < mlx->wld->nb_line)
	{
		j = 0;
		while (j < mlx->wld->nb_elem)
		{
			env->map[i][j].x += env->cx - midx;
			env->map[i][j].y += env->cy - midy;
			j++;
		}
		i++;
	}
	return ;
}

void		get_center(t_mlx *mlx)
{
	int		midx;
	int		midy;

	midx = (mlx->wld->nb_elem - 1) / 2;
	midy = (mlx->wld->nb_line - 1) / 2;
	mlx->wld->cx = mlx->wld->map[midy][midx].x;
	mlx->wld->cy = mlx->wld->map[midy][midx].y;
	return ;
}
