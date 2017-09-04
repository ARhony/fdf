/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 01:06:54 by aramon            #+#    #+#             */
/*   Updated: 2016/11/28 01:15:22 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strncmp(const char *s1, const char *s2, int length)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i] == s2[j] && s1[i] && s2[i] && length != 0)
	{
		s1++;
		s2++;
		length--;
	}
	if (length == 0)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}
