/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 04:51:01 by aramon            #+#    #+#             */
/*   Updated: 2016/11/26 16:01:25 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*s_dst;
	char		*s_src;

	s_dst = (char*)dst;
	s_src = (char*)src;
	while (n > 0 && *s_src != c)
	{
		n--;
		*s_dst++ = *s_src++;
	}
	if (n > 0)
	{
		*s_dst++ = *s_src++;
		return (s_dst);
	}
	else
		return (NULL);
}
