/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 03:40:29 by aramon            #+#    #+#             */
/*   Updated: 2016/11/16 19:01:57 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char		*s_src;
	char			*s_dst;

	s_src = src;
	s_dst = dst;
	while (n-- > 0)
		*s_dst++ = *s_src++;
	return (dst);
}
