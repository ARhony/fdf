/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 19:26:14 by aramon            #+#    #+#             */
/*   Updated: 2017/03/03 15:02:48 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include "libft/libft.h"

# define BUFF_SIZE 5

typedef struct		s_gnl
{
	char			**content;
	int				nline;
}					t_gnl;

int					get_next_line(const int fd, char **line);

#endif
