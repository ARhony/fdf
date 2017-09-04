/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 21:07:13 by aramon            #+#    #+#             */
/*   Updated: 2016/11/25 21:07:20 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *s, int c, size_t len)
{
	unsigned char	*s_src;
	size_t			i;

	s_src = (unsigned char*)s;
	i = 0;
	while (i < len)
	{
		if (s_src[i] == (unsigned char)c)
			return (s_src + i);
		i++;
	}
	return (0);
}
