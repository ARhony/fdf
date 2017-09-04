/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 10:53:55 by aramon            #+#    #+#             */
/*   Updated: 2016/11/28 05:00:02 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (s && *s)
	{
		sub = ft_strnew(len);
		if (sub == NULL)
			return (NULL);
		s = s + start;
		i = 0;
		while (i < len)
		{
			sub[i] = s[i];
			i++;
		}
		return (sub);
	}
	return (0);
}
