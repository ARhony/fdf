/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 17:57:04 by aramon            #+#    #+#             */
/*   Updated: 2016/11/25 19:13:37 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int i;
	int nbr;
	int negative;

	i = 0;
	nbr = 0;
	negative = 1;
	while (str[i] == '\t' || str[i] == ' ' || str[i] == '\v' ||
str[i] == '\n' || str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '-')
		negative = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		nbr *= 10;
		nbr += (int)str[i] - '0';
		i++;
	}
	return (negative * nbr);
}
