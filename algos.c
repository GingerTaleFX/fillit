/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:04:02 by mdirect           #+#    #+#             */
/*   Updated: 2019/11/22 14:42:27 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_move(t_uint128_t *tetra, int y)
{
	t_uint128_t	right;
	t_uint128_t	left;
	t_uint128_t	bottom;

	right = make_right(y);
	left = make_left(y);
	bottom = make_bottom(y);
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

int			func1(t_uint128_t map, t_uint128_t *tetra, int y)
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

void		func2(t_uint128_t *tetra, int *y)
{
	t_uint128_t	map;
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
