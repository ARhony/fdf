/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 00:37:40 by aramon            #+#    #+#             */
/*   Updated: 2016/11/22 20:33:37 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*target;
	size_t		i;
	size_t		j;
	size_t		k;

	i = 0;
	j = 0;
	if (*little == '\0')
		return ((char*)big);
	while (*big && j < len)
	{
		target = big;
		i = 0;
		k = j;
		while (target[i] == little[i] && k < len)
		{
			if (little[i + 1] == '\0')
				return ((char*)big);
			i++;
			k++;
		}
		big++;
		j++;
	}
	return (0);
}
