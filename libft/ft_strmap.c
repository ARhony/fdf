/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 05:40:39 by aramon            #+#    #+#             */
/*   Updated: 2016/11/28 04:56:26 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*j;
	unsigned int	i;

	i = 0;
	if (s && *s && f && *f)
	{
		j = ft_strnew(ft_strlen((char*)s));
		if (j == NULL)
			return (NULL);
		while (s[i] != '\0')
		{
			j[i] = f(s[i]);
			i++;
		}
		return (j);
	}
	return (0);
}
