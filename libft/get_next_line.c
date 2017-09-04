/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 19:25:50 by aramon            #+#    #+#             */
/*   Updated: 2017/03/16 22:05:21 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	char			*full_buf;
	int				ret;
	static t_gnl	*fds;

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
		return (0);
	*line = ft_strnew(ft_strlen(fds[fd].content[fds[fd].nline]));
	*line = fds[fd].content[fds[fd].nline++];
	return (1);
}
