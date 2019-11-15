/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroselin <kroselin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 16:16:52 by kroselin          #+#    #+#             */
/*   Updated: 2019/11/15 14:46:42 by kroselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	if (!s1 || !s2)
		return (0);
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	if (*s1 == *s2)
	{
		while (*s1 == *s2)
		{
			if (*s1 == '\0' && *s2 == '\0')
				return (1);
			s1++;
			s2++;
		}
	}
	return (0);
}
