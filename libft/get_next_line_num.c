/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 19:25:50 by aramon            #+#    #+#             */
/*   Updated: 2017/03/17 02:00:17 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			count_line(int	n, int *line_number)
{
	*line_number = n;
	return (0);
}

int			get_next_line_num(const int fd, char **line, int *line_number)
{
	char			buf[BUFF_SIZE + 1];
	char			*full_buf;
	int				ret;
	static t_gnln	*fds;

	ret = 0;
	full_buf = ft_strnew(1);
	if (line == NULL || fd < 0 || read(fd, buf, 0) < 0)
		return (-1);
	if (fds == NULL)
		fds = (t_gnl*)malloc(sizeof(t_gnl) * 1100);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		full_buf = ft_strjoin(full_buf, buf);
	}
	if (!fds[fd].content)
		fds[fd].content = ft_strsplit_seg(full_buf, '\n');
	else if (!fds[fd].content[fds[fd].nline])
		return (count_line(fds[fd].nline, line_number));
	*line = ft_strnew(ft_strlen(fds[fd].content[fds[fd].nline]));
	*line = fds[fd].content[fds[fd].nline++];
	return (1);
}
