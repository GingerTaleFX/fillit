/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroselin <kroselin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 11:37:15 by kroselin          #+#    #+#             */
/*   Updated: 2019/11/21 21:50:32 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int check_tetramino(uint128_t src)
{
	uint128_t tetramins[19] = {58368, 35968, 19968, 19520,
							  52224,
							  34952, 61440,
							  51328, 57856, 50240, 36352, 17600, 35008, 11776, 59392,
							  27648, 35904, 50688, 19584};
	int	i;

	i = -1;
	while (++i < 19)
		if(tetramins[i] == src)
			return (1);
	return (0);
}

uint128_t move_tetro(uint128_t tmp, int y)
{
	uint128_t	top;
	uint128_t	left;
	int			i;

	i = y * y;
	top = 0;
	left = 0;
	while (--i >= 0)
	{
		if (i >= y * (y - 1))
			top |= ((uint128_t)1 << i);
		if (!((i + 1) % y))
			left |= ((uint128_t)1 << i);
	}
	while ((left & tmp) == 0)
		tmp <<= 1;
	while ((top & tmp) == 0)
		tmp <<= y;
	return (tmp);
}

/*
 * func count_lines count, how many lines (y) must have a map
 * */

int count_lines(uint128_t *tetra)
{
	int i;
	int j;

	i = 0;
	while (tetra[i])
	{
		if (tetra[i] == 34952 || tetra[i] == 61440)
			j = 1;
		i++;
	}
	if (i == 1)
		return (1);
	else if (i == 2 && j == 1)
		return (4);
	else if (i == 2)
		return (3);
	else if (i >= 3 && i <= 4)
		return (4);
	else if (i >= 5 && i <= 6)
		return (5);
	else if (i >= 7 && i <= 9)
		return (6);
	else if (i >= 10 && i <= 12)
		return (7);
	else if (i >= 13 && i <= 16)
		return (8);
	else if (i >= 17 && i <= 20)
		return (9);
	else if (i >= 21 && i <= 25)
		return (10);
	else if (i == 26)
		return (11);
	return (0);
}

/*
 * Make tetras bigger, if there are more then 4*
 */
uint128_t *resize_tetras(uint128_t *tetra, int y, int counter)
{
	int			i;
	int			j;
	int 		c;
	uint128_t	tmp;

	c = 0;
	while (*tetra)
	{
		i = (counter == 1) ? 4 : y - 1;
		while(i < y)
		{
			j = 0;
			tmp = 0;
			while (*tetra) {
				tmp += (*tetra - ((*tetra >> i) << i)) << (j * (i + 1) + 1);
				*tetra >>= i;
				j++;
			}
			*tetra = tmp << (i + 1);
			i++;
		}
		tetra++;
		c++;
	}
	return (tetra - c);
}

uint128_t	*small_tetra(uint128_t *tetra, int y)
{
	int			i;
	int			j;
	int 		c;
	uint128_t	tmp;

	c = 0;
	while (*tetra)
	{
		i = 4;
		while(i > y)
		{
			while (ft_move(tetra, i))
				continue;
			j = 0;
			tmp = 0;
			while (*tetra)
			{
				tmp += (*tetra - ((*tetra >> i) << i)) << (j * (i - 1));
				*tetra = *tetra >> i;
				j++;
			}
			*tetra = tmp;
			i--;
		}
		tetra++;
		c++;
	}
	return (tetra - c);
}