/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:04:02 by mdirect           #+#    #+#             */
/*   Updated: 2019/11/15 12:33:29 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

uint64_t	ft_move(uint64_t tetra, int y)
{
	uint64_t	right;
	uint64_t	left;
	uint64_t	bottom;
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
	if (!(bottom & tetra))
		if (right & tetra)
		{
			while ((left & tetra) == 0)
				tetra <<= 1;
			tetra >>= y;
		}
		else
			tetra >>= 1;
	return (tetra);
}

int 		func1(uint64_t map, uint64_t *tetra, int y)
{
	if (!(*tetra))
		return (1);
	while (*tetra % 2 == 0)
		if ((map & *tetra) == 0)
		{
			map |= *tetra;
//			ft_print_bit(map, (y * y), y);
			return(func1(map, tetra + 1, y));
		}
		else
		{
			printf("do:\n");
			ft_print_bit(*tetra, y*y, y);
			*tetra = ft_move(*tetra, y);
			printf("posle:\n");
			ft_print_bit(*tetra, y*y, y);
		}
	return (0);
}

void		func2(uint64_t *tetra, int *y)
{
	uint64_t map;
	int i;

	map = 0;
	while (!(func1(map, tetra, *y)))
	{
		map = 0;
		*y = *y + 1;
		i = -1;
		while (++i < 26 && tetra[i])
		{
//			printf("do:\n");
//			ft_print_bit(tetra[i], (*y) * (*y), *y);
			tetra[i] = move_tetro(tetra[i], *y);
//			printf("posle:\n");
//			ft_print_bit(tetra[i], (*y) * (*y), *y);
		}
//		i = -1;
//		while (++i < 26 && tetra[i])
//		{
//			printf("tetra[%d] = %llu\n", i, tetra[i]);
//			ft_print_bit(tetra[i], (*y) * (*y), *y);
//		}
		tetra = resize_tetras(tetra, *y, 2);
	}
	ft_print_map(tetra, *y);
}
