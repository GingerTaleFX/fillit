/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:04:02 by mdirect           #+#    #+#             */
/*   Updated: 2019/11/14 18:55:06 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

uint64_t	ft_move(uint64_t tetra, int y)
{
	if (check_tetra_in_map(tetra) != 4) /* переделать чек на чек правой границы ???*/
	{
		while ((LEFT & tetra) == 0)
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
			func1(map, tetra + 1, y);
		}
		else
			*tetra = ft_move(*tetra, y);
	return (0);
}

void		func2(uint64_t *tetra, int *y)
{
	uint64_t map;
	int i;

	map = 0;
	i = func1(map, tetra, *y);
	while (!i)
	{
		map = 0;
		*y = *y + 1;
		tetra = resize_tetras(tetra, *y, 2);
		i = func1(map, tetra, *y);
	}
}
