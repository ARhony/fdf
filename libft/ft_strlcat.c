/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 19:37:21 by aramon            #+#    #+#             */
/*   Updated: 2016/11/19 22:23:27 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t length)
{
	size_t			l_dst;

	l_dst = ft_strlen((char*)dst);
	if (length >= l_dst + 1)
	{
		ft_strncat(dst, src, length - l_dst - 1);
		return (l_dst + ft_strlen((char*)src));
	}
	else
		return (length + ft_strlen((char*)src));
}
