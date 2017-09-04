/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 12:09:01 by aramon            #+#    #+#             */
/*   Updated: 2017/03/16 16:18:12 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_hook(int keycode, t_mlx *mlx)
{
	t_world		*env;

	env = mlx->wld;
	get_center(mlx);
	if (keycode == 53)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}
	key_hook_rotation(keycode, mlx);
	key_hook_scale(keycode, mlx);
	key_hook_translation(keycode, mlx);
	set_center(mlx);
	draw(mlx);
	return (0);
}

void	key_hook_rotation(int keycode, t_mlx *mlx)
{
	if (keycode == KROTXU)
		cal_rotation(mlx, ROTXU, 'x');
	else if (keycode == KROTXD)
		cal_rotation(mlx, ROTXD, 'x');
	else if (keycode == KROTYU)
		cal_rotation(mlx, ROTYU, 'y');
	else if (keycode == KROTYD)
		cal_rotation(mlx, ROTYD, 'y');
	else if (keycode == KROTZU)
		cal_rotation(mlx, ROTZU, 'z');
	else if (keycode == KROTZD)
		cal_rotation(mlx, ROTZD, 'z');
}

void	key_hook_translation(int keycode, t_mlx *mlx)
{
	if (keycode == KMU)
		cal_translation(mlx, 0, MU, 0);
	else if (keycode == KMD)
		cal_translation(mlx, 0, MD, 0);
	else if (keycode == KMR)
		cal_translation(mlx, MR, 0, 0);
	else if (keycode == KML)
		cal_translation(mlx, ML, 0, 0);
}

void	key_hook_scale(int keycode, t_mlx *mlx)
{
	if (keycode == KSU)
		cal_scale(mlx, SU);
	else if (keycode == KSD)
		cal_scale(mlx, SD);
}
