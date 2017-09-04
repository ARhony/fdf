/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 10:21:29 by aramon            #+#    #+#             */
/*   Updated: 2016/11/28 04:57:39 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*j;
	unsigned int	i;

	if (s && *s && f && *f)
	{
		j = ft_strnew(ft_strlen((char*)s));
		if (j == NULL)
			return (NULL);
		i = 0;
		while (s[i] != '\0')
		{
			j[i] = f(i, s[i]);
			i++;
		}
		return (j);
	}
	return (0);
}
