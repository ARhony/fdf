/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 16:09:01 by aramon            #+#    #+#             */
/*   Updated: 2017/03/22 18:51:56 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_mlx	*mlx;

	if (argc != 2)
	{
		ft_putendl("Usage : ./fdf map.fdf");
		return (0);
	}
	mlx = initmlx(argv[1]);
	mlx_hook(mlx->win, 2, 0, key_hook, mlx);
	mlx_loop(mlx->mlx);
}
