/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 07:51:33 by aramon            #+#    #+#             */
/*   Updated: 2016/11/19 23:16:40 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s_str1;
	const unsigned char	*s_str2;

	s_str1 = (const unsigned char*)s1;
	s_str2 = (const unsigned char*)s2;
	if (s1 == s2 || n == 0)
		return (0);
	while (n > 0)
	{
		if (*s_str1 != *s_str2)
			return (*s_str1 - *s_str2);
		s_str1++;
		s_str2++;
		n--;
	}
	return (0);
}
