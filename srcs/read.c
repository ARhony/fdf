/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 19:01:17 by aramon            #+#    #+#             */
/*   Updated: 2017/03/22 18:52:06 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <stdio.h>

int			*clean_line(char *line, int nb_elem)
{
	int		i;
	int		j;
	int		*tmp;
	char	**mat_tmp;

	i = 0;
	j = 0;
	tmp = (int*)malloc(sizeof(int) * nb_elem);
	mat_tmp = ft_strsplit(line, ' ');
	while (i < nb_elem)
	{
		tmp[i] = ft_atoi(mat_tmp[i]);
		i++;
	}
	return (tmp);
}

t_point		*read_file(char *str, int nb_elem)
{
	int				i;
	int				*tmp;
	t_point			*line;

	i = 0;
	tmp = clean_line(str, nb_elem);
	line = (t_point*)malloc(sizeof(t_point) * nb_elem);
	while (i < nb_elem)
	{
		line[i].z = tmp[i];
		i++;
	}
	return (line);
}

t_point		**open_file(char *file, t_world *wld)
{
	t_point		**map;
	t_point		*line;
	int			fd;
	char		*str;
	int			i;

	fd = open(file, O_RDONLY);
	wld->nb_line = get_nb_line(fd, &wld->nb_elem);
	map = (t_point**)malloc(sizeof(t_point*) * wld->nb_line);
	fd = open(file, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &str) > 0)
	{
		line = read_file(str, wld->nb_elem);
		map[i] = line;
		i++;
	}
	return (map);
}

int			get_nb_line(int fd, int *nb_elem)
{
	int		nb_line;
	char	*line;

	while (get_next_line_num(fd, &line, &nb_line) > 0)
		;
	*nb_elem = get_number_elem(line);
	free(line);
	close(fd);
	return (nb_line);
}
