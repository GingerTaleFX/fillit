/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroselin <kroselin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 11:33:46 by kroselin          #+#    #+#             */
/*   Updated: 2019/11/14 15:40:15 by kroselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
 * Checks the number of tetra elements after first movving. If there are less then 4, the map will be bigger and the func of placing will repeat.
 * */

int	check_tetra_in_map(uint64_t tetra)
{
	int max;

	max = 0;
	while (tetra)
	{
		tetra = tetra & (tetra - 1);
		max++;
	}
	return (max);
}

/*
 * Here is a mass, i hope, we will make a normal func from it. So, we take tetro and tries to put it in the map. Then we check, how many peaces of actual tetramin we have (check_tetra_in_map)
 * we must have 4 peace, or make map bigger. If tetro doesn't take its place, we get from rem its params, move map for a size of Y (tmp <<= (x/y)). For example:
 * 1111 0000 0000 0000
 * << y (y = 4)
 * 1111 0000 0000 0000 0000
 *
 * and repeat_move - i don't know, how to make recursive, cause
 * "repeat" do the same part of move_in_map.
 *
 * The func works, it fills the map and do it correctly, make its bigger, when it's necessary. But! It doesn't search smallest way for tetros.
 * I hope, u will do it)*/

/*
 * заходим в функцию
 * map - в ней лежит 1-ая тетраминка и задает карту
 * tetra[i] - вторая тетраминка
 * 1. пробуем поместить
 * 2.проверяем, влезла ли
 * 2.1 если у нас получилось ее вставить, то мы берем следующую, делаем i++, повторяем процедуру
 * 2.2 если какая-то тетраминка не помещается и кончилась карта, то мы делаем шаг назад и двигаем предыдущую тетраминку
 * 3. если мы дошли до 1ой тетраминки (которая прилетела в карте) и она в правом нижнем углу, а остальные тетраминки не влезли,
 * значит нам нужно увеличить карту (возвращаем 0)
 * 4. в случае влезания возвращаем 1
 *
 * */
uint64_t move_in_map(uint64_t map, uint64_t *tetra, uint64_t x, int y)
{
	uint64_t	rem1;
	uint64_t	rem2;
//	int			i;

//	i = x;
	rem1 = map;
	rem2 = *tetra;

		while (*tetra)
		{
			if ((rem1 & *tetra) != 0)
				break ;
			else
			{
				rem1 |= *tetra;
				tetra++;
				x = y * y;
//				break ;
			}
		}
		if(!(*tetra))
			return (1);
		if ((rem1 & *tetra) != 0)
		{
			if ((*tetra) % 2 == 0)
			{
//				x--;
				if ((x + 1) % y == 0 && (*tetra <<(y *(y -1))) % 2
					(*tetra)>>= y;
				else
				{
					(*tetra) >>= 1;
					x--;
				}
			}
			return (move_in_map(rem1, tetra, x, y));
		}

//	while (x)
//	{
//		while ((map & tetra[i]) != 0)
//		{
//			tetra[i] >>= 1;
//			x--;
//		}
//		x--;
//	}
//	if (check_tetramino(tetra[i]) == 4)
//		map |= tetra[i];
//	if ((check_tetra_in_map(tetra[i])) != 4)
//		return (0);
	return (0);
}

/*
 * we get massive of tetraminos and the number of lines in our map.
 * then we find, how many peace should be in it - x.
 * x = (y * y) - y is necessary for test, but i change some things.
 * first tetro places in tmp, then we take second one and tries to put it in the map - move_in_map
 *
 * The letter doesn't work! I have'nt imagined yet, how to solve this problem without lists.
 * */

uint64_t place_in_map(uint64_t *tetra, int *y)
{
	int			i;
	uint64_t	x;
	uint64_t 	map;

	i = -1;
	x = (*y) * (*y);
	map = 0;
	while (tetra[++i])
	{
		if ((map & tetra[i]) != 0)
		{
			if (!(map = move_in_map(map, tetra + 1, x, *y)))
			{
				(*y) = (*y) + 1;
				tetra = resize_tetras(tetra, (*y), 1);
				map = place_in_map(tetra, y);
				x = (*y) * (*y);
			}
		}
		else
			map |= tetra[i];
	}
	return (map);
}