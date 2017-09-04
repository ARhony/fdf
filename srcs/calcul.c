/* ************************************************************************** */
/*                                                                      	  */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 19:40:01 by aramon            #+#    #+#             */
/*   Updated: 2017/04/01 23:20:53 by aramon           ###   ########.fr       */
/*                                                             				  */
/* ************************************************************************** */

#include "fdf.h"

t_point		cal_point(t_mat *m, t_point v)
{
	double		tmpx;
	double		tmpy;
	double		tmpz;

	tmpx = v.x * m->a1 + v.y * m->a2 + v.z * m->a3 + m->a4;
	tmpy = v.x * m->b1 + v.y * m->b2 + v.z * m->b3 + m->b4;
	tmpz = v.x * m->c1 + v.y * m->c2 + v.z * m->c3 + m->c4;
	v.x = tmpx;
	v.y = tmpy;
	v.z = tmpz;
	return (v);
}

void		cal_map(t_mlx *mlx, t_mat *mat)
{
	int		i;
	int		j;

	i = 0;
	while (i < mlx->wld->nb_line)
	{
		j = 0;
		while (j < mlx->wld->nb_elem)
		{
			mlx->wld->map[i][j] = cal_point(mat, mlx->wld->map[i][j]);
			j++;
		}
		i++;
	}
}

void		cal_translation(t_mlx *mlx, double tx, double ty, double tz)
{
	t_mat	*m_tra;

	m_tra = mat_translation(tx, ty, tz);
	mlx->wld->cx += (tx != 0 ? tx : 0);
	mlx->wld->cy += (ty != 0 ? ty : 0);
	cal_map(mlx, m_tra);
	free(m_tra);
}

void		cal_rotation(t_mlx *mlx, double ang, char axis)
{
	t_mat	*m_rot;

	if (axis == 'x')
		m_rot = mat_rotation_x(ang);
	else if (axis == 'y')
		m_rot = mat_rotation_y(ang);
	else
		m_rot = mat_rotation_z(ang);
	cal_map(mlx, m_rot);
	free(m_rot);
}

void		cal_scale(t_mlx *mlx, double s)
{
	t_mat	*m_sca;

	m_sca = mat_scale(s);
	cal_map(mlx, m_sca);
	free(m_sca);
}
