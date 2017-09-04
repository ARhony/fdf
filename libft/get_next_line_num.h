/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 19:26:14 by aramon            #+#    #+#             */
/*   Updated: 2017/03/17 02:01:34 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_NUM_H
# define GET_NEXT_LINE_NUM_H
# include <fcntl.h>
# include "libft/libft.h"

# define BUFF_SIZE 5

typedef struct		s_gnln
{
	char			**content;
	int				nline;
}					t_gnln;

int					get_next_line_num(const int fd, char **line, int *line_number);
int					count_line(int n, int *line_number);

#endif
