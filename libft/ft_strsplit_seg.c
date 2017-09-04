/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 16:15:58 by aramon            #+#    #+#             */
/*   Updated: 2017/01/15 05:28:47 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*createword(const char *s, char c, unsigned int *j)
{
	char			*word;
	unsigned int	i;
	unsigned int	start;

	if (s[*j] == c && s[*j] != '\0')
		(*j)++;
	start = *j;
	while (s[*j] != c && s[*j] != '\0')
		(*j)++;
	word = ft_strnew(*j - start);
	i = 0;
	while (start < *j)
	{
		word[i] = s[start];
		start++;
		i++;
	}
	word[i] = '\0';
	return (word);
}

char			**ft_strsplit_seg(char const *s, char c)
{
	char				**matrix;
	int					i;
	int					words;
	unsigned int		j;

	if (s == (NULL))
		return (NULL);
	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		if ((s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
				|| (s[i - 1] != c && s[i] == c && s[i + 1] == c))
			words++;
		i++;
	}
	matrix = (char**)malloc(sizeof(char*) * (words + 1));
	if (matrix == (NULL))
		return (NULL);
	i = 0;
	j = 0;
	while (i < words)
		matrix[i++] = createword(s, c, &j);
	matrix[i] = 0;
	return (matrix);
}
