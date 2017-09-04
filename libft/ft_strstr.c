/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 05:19:43 by aramon            #+#    #+#             */
/*   Updated: 2016/11/14 09:33:52 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *big, const char *little)
{
	int			i;
	int			j;
	int			l;

	i = 0;
	j = 0;
	l = ft_strlen((char*)little);
	if (l == 0)
		return ((char *)big);
	while (big[i] != '\0')
	{
		while (little[j] == big[i + j])
		{
			if (j == l - 1)
				return ((char*)big + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
