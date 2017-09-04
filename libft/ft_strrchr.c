/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 03:51:04 by aramon            #+#    #+#             */
/*   Updated: 2016/11/12 04:27:10 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int				i;
	const char		*result;

	i = 0;
	while (s[i] != '\0')
		i++;
	while (i > -1)
	{
		if (s[i] == (char)c)
		{
			result = &s[i];
			return ((char*)result);
		}
		i--;
	}
	return (NULL);
}
