/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 16:15:58 by aramon            #+#    #+#             */
/*   Updated: 2016/11/23 22:40:34 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*createword(const char *s, char c, unsigned int *j)
{
	char			*word;
	unsigned int	i;
	unsigned int	start;

	while (s[*j] == c && s[*j] != '\0')
		(*j)++;
	start = *j;
	while (s[*j] != c && s[*j] != c)
		(*j)++;
	word = ft_strnew(*j - start);
	if (word == NULL)
		return (NULL);
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

char			**ft_strsplit(char const *s, char c)
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
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
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
