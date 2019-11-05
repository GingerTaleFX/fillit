/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroselin <kroselin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 12:00:35 by kroselin          #+#    #+#             */
/*   Updated: 2019/09/19 13:42:15 by kroselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cl(char const *s, char c)
{
	int j;

	j = 0;
	while (*s == c)
		s++;
	while (*s != c && *s)
	{
		j++;
		s++;
	}
	return (j);
}

static char	**ft_fill_mass(char const *s, char c, int chars, char **ar)
{
	char	*tar;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (*s && chars--)
	{
		if (!(tar = (char *)malloc(sizeof(*tar) * (ft_cl(s, c) + 1))))
		{
			free(tar);
			return (0);
		}
		while (*s == c && *s != '\0')
			s++;
		while (*s != c && *s)
			tar[j++] = *(s++);
		tar[j] = '\0';
		j = 0;
		ar[i++] = tar;
		s++;
	}
	ar[i] = 0;
	return (ar);
}

char		**ft_strsplit(char const *s, char c)
{
	char **ar;
	char chars;

	if (!s || !c)
		return (0);
	chars = ft_count_mass(s, c);
	if (!(ar = (char **)malloc(sizeof(ar) * (chars + 1))))
	{
		free(ar);
		return (0);
	}
	ar = ft_fill_mass(s, c, chars, ar);
	return (ar);
}
