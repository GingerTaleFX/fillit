/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:04:02 by mdirect           #+#    #+#             */
/*   Updated: 2019/11/20 14:08:22 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

uint128_t	ft_move(uint128_t *tetra, int y)
{
	uint128_t	right;
	uint128_t	left;
	uint128_t	bottom;
	int			i;

	i = y * y;
	right = 0;
	left = 0;
	bottom = 0;
	while (--i >= 0)
	{
		if (!(i % y))
			right |= (1 << i);
		if (!((i + 1) % y))
			left |= (1 << i);
		if (i < y)
			bottom |= (1 << i);
	}
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

int 		func1(uint128_t map, uint128_t *tetra, int y)
{
	if (!(*tetra))
		return (1);
//	ft_print_bit(map, y);
	while (1)
	{

//		ft_print_bit(*tetra, y);
		if ((map & *tetra) == 0)
			if (func1(map | *tetra, tetra + 1, y) == 1)
				return (1);

		if (ft_move(tetra, y) == 0)
		{
//			ft_print_bit(*tetra, y);
			*tetra = move_tetro(*tetra, y);
//			if (*tetra == 50240)
//				ft_print_bit(*tetra, y);
			return (0);
		}
	}
	return (0);
}

void		func2(uint128_t *tetra, int *y)
{
	uint128_t map;
	int i;

	map = 0;
	while (!(func1(map, tetra, *y)))
	{
		map = 0;

//		i = -1;
//		while (++i < 26 && tetra[i])
//		{
//			printf("tetra[%d] = %llu\n", i, tetra[i]);
//			ft_print_bit(tetra[i], *y);
//		}

		i = -1;
		while (++i < 26 && tetra[i])
			tetra[i] = move_tetro(tetra[i], *y);
		*y = *y + 1;
		tetra = resize_tetras(tetra, *y, 2);

//		i = -1;
//		while (++i < 26 && tetra[i])
//		{
//			printf("tetra[%d] = %llu\n", i, tetra[i]);
//			ft_print_bit(tetra[i], *y);
//		}
	}
	ft_print_map(tetra, *y);
}
