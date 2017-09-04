/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 01:19:25 by aramon            #+#    #+#             */
/*   Updated: 2016/11/28 02:25:16 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *b, int c, size_t length)
{
	unsigned char		*str;
	int					i;

	str = b;
	i = 0;
	while (length > 0)
	{
		str[i] = (unsigned char)c;
		i++;
		length--;
	}
	return ((void*)str);
}
