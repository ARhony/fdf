/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 19:40:01 by aramon            #+#    #+#             */
/*   Updated: 2017/04/01 23:20:53 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mat		*mat_translation(double tx, double ty, double tz)
{
	t_mat	*mat;

	if (!(mat = (t_mat*)malloc(sizeof(t_mat))))
		return (NULL);
	mat = init_mat();
	mat->a1 = 1;
	mat->a4 = tx;
	mat->b2 = 1;
	mat->b4 = ty;
	mat->c3 = 1;
	mat->c4 = tz;
	mat->d4 = 1;
	return (mat);
}

t_mat		*mat_scale(double s)
{
	t_mat	*mat;

	if (!(mat = (t_mat*)malloc(sizeof(t_mat))))
		return (NULL);
	mat = init_mat();
	mat->a1 = s;
	mat->b2 = s;
	mat->c3 = s;
	mat->d4 = 1;
	return (mat);
}

t_mat		*mat_rotation_x(double a)
{
	t_mat	*mat;

	if (!(mat = (t_mat*)malloc(sizeof(t_mat))))
		return (NULL);
	mat = init_mat();
	mat->a1 = 1;
	mat->b2 = cos(a);
	mat->b3 = sin(a);
	mat->c2 = -sin(a);
	mat->c3 = cos(a);
	return (mat);
}

t_mat		*mat_rotation_y(double a)
{
	t_mat	*mat;

	if (!(mat = (t_mat*)malloc(sizeof(t_mat))))
		return (NULL);
	mat = init_mat();
	mat->a1 = cos(a);
	mat->a3 = -sin(a);
	mat->b2 = 1;
	mat->c1 = sin(a);
	mat->c3 = cos(a);
	mat->d4 = 1;
	return (mat);
}

t_mat		*mat_rotation_z(double a)
{
	t_mat	*mat;

	if (!(mat = (t_mat*)malloc(sizeof(t_mat))))
		return (NULL);
	mat = init_mat();
	mat->a1 = cos(a);
	mat->a2 = sin(a);
	mat->b1 = -sin(a);
	mat->b2 = cos(a);
	mat->c3 = 1;
	mat->d4 = 1;
	return (mat);
}
