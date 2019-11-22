/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 11:11:14 by mdirect           #+#    #+#             */
/*   Updated: 2019/11/22 12:54:23 by kroselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

uint128_t	make_left(int y)
{
	uint128_t	left;
	int			i;

	i = y * y;
	left = 0;
	while (--i >= 0)
		if (!((i + 1) % y))
			left |= ((uint128_t)1 << i);
	return (left);
}

uint128_t	make_bottom(int y)
{
	uint128_t	bottom;
	int			i;

	i = y * y;
	bottom = 0;
	while (--i >= 0)
		if (i < y)
			bottom |= ((uint128_t)1 << i);
	return (bottom);
}

uint128_t	make_right(int y)
{
	uint128_t	right;
	int			i;

	i = y * y;
	right = 0;
	while (--i >= 0)
		if (!(i % y))
			right |= ((uint128_t)1 << i);
	return (right);
}

int			ft_sqrt(int i)
{
	int k;
	int res;

	if (i >= 0)
	{
		k = 0;
		res = 0;
		while (res < i)
		{
			res = res + (2 * k + 1);
			k++;
		}
		return (k);
	}
	return (-1);
}

void		ft_bzero(void *s, size_t n)
{
	while (n)
	{
		*((unsigned char*)s) = '\0';
		s++;
		n--;
	}
}
