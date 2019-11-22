/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 11:11:14 by mdirect           #+#    #+#             */
/*   Updated: 2019/11/22 11:11:14 by mdirect          ###   ########.fr       */
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
