/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:04:02 by mdirect           #+#    #+#             */
/*   Updated: 2019/11/22 11:08:51 by mdirect          ###   ########.fr       */
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

int			ft_move(uint128_t *tetra, int y)
{
	uint128_t	right;
	uint128_t	left;
	uint128_t	bottom;
	int			i;

	i = y * y;
	right = 0;
	left = make_left(y);
	bottom = make_bottom(y);
	while (--i >= 0)
		if (!(i % y))
			right |= ((uint128_t)1 << i);
	if ((bottom & *tetra) && (right & *tetra))
		return (0);
	if (right & *tetra)
	{
		while (!(left & *tetra))
			*tetra <<= 1;
		*tetra >>= y;
	}
	else
		*tetra >>= 1;
	return (1);
}

int			func1(uint128_t map, uint128_t *tetra, int y)
{
	if (!(*tetra))
		return (1);
	while (1)
	{
		if ((map & *tetra) == 0)
			if (func1(map | *tetra, tetra + 1, y) == 1)
				return (1);
		if (ft_move(tetra, y) == 0)
		{
			*tetra = move_tetro(*tetra, y);
			return (0);
		}
	}
}

void		func2(uint128_t *tetra, int *y)
{
	uint128_t	map;
	int			i;

	map = 0;
	while (!(func1(map, tetra, *y)))
	{
		map = 0;
		i = -1;
		while (++i < 26 && tetra[i])
			tetra[i] = move_tetro(tetra[i], *y);
		*y = *y + 1;
		tetra = resize_tetras(tetra, *y, 2);
	}
	ft_print_map(tetra, *y);
}
