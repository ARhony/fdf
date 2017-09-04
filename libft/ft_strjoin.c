/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 11:12:29 by aramon            #+#    #+#             */
/*   Updated: 2016/11/28 05:01:19 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *i;
	char *j;

	if (s1 == NULL && s2 == NULL)
		return (ft_strnew(0));
	else if (s1 == NULL)
		return (ft_strdup(s2));
	else if (s2 == NULL)
		return (ft_strdup(s1));
	i = ft_strnew(ft_strlen((char*)s1) + ft_strlen((char*)s2));
	if (i == NULL)
		return (NULL);
	j = i;
	while (*s1 != '\0')
		*j++ = *s1++;
	while (*s2 != '\0')
		*j++ = *s2++;
	*j = '\0';
	return (i);
}
