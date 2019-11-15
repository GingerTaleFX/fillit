/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroselin <kroselin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 14:37:23 by kroselin          #+#    #+#             */
/*   Updated: 2019/11/15 14:46:42 by kroselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	const char	*rem;

	rem = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			rem = &s[i];
		i++;
	}
	if (c == '\0')
		return (&(((char *)s)[i]));
	return ((char *)rem);
}
