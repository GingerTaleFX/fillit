/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroselin <kroselin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 16:40:20 by kroselin          #+#    #+#             */
/*   Updated: 2019/11/15 14:46:42 by kroselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (!s1 || !s2)
		return (0);
	if ((*s1 == '\0' && *s2 == '\0') || (*s2 == '\0' && n == 0) ||
			n == 0)
		return (1);
	if (*s1 == *s2)
	{
		while (n && *s1 == *s2 && *s1 && *s2)
		{
			s1++;
			s2++;
			n--;
		}
		if (*s1 == *s2)
			return (1);
		if (*(s1 - 1) == *(s2 - 1) && n == 0)
			return (1);
	}
	return (0);
}
