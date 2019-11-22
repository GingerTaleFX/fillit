/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroselin <kroselin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 11:37:15 by kroselin          #+#    #+#             */
/*   Updated: 2019/11/22 14:42:27 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			check_tetramino(t_uint128_t src)
{
	static t_uint128_t	s_tetramins[19] = {58368, 35968, 19968, 19520, 52224,\
								34952, 61440,\
								51328, 57856, 50240, 36352, 17600, \
								35008, 11776, 59392, \
								27648, 35904, 50688, 19584};
	int					i;

	i = -1;
	while (++i < 19)
		if (s_tetramins[i] == src)
			return (1);
	return (0);
}

/*
** move_tetro moves a tetro to left top corner.
*/

t_uint128_t	move_tetro(t_uint128_t tmp, int y)
{
	t_uint128_t	top;
	t_uint128_t	left;
	int			i;

	i = y * y;
	top = 0;
	left = 0;
	while (--i >= 0)
	{
		if (i >= y * (y - 1))
			top |= ((t_uint128_t)1 << i);
		if (!((i + 1) % y))
			left |= ((t_uint128_t)1 << i);
	}
	while ((left & tmp) == 0)
		tmp <<= 1;
	while ((top & tmp) == 0)
		tmp <<= y;
	return (tmp);
}

/*
** func count_lines defines, how many tetras are.
** we need this func for 1 and 2 tetras for making small maps.
*/

int			count_lines(t_uint128_t *tetra)
{
	int i;
	int line;
	int sq;

	i = 0;
	line = 0;
	sq = 0;
	while (tetra[i])
	{
		if (tetra[i] == 34952 || tetra[i] == 61440)
			line = 1;
		if (tetra[i] == 52224)
			sq = 1;
		i++;
	}
	if (i == 1 && sq == 1)
		return (2);
	if (i < 3 && line == 1)
		return (4);
	else if (i > 1)
		return (ft_sqrt(i * 4));
	return (0);
}

/*
** Make tetras bigger, if there are more then 4*
*/

t_uint128_t	*resize_tetras(t_uint128_t *tetra, int y, int counter)
{
	int			i;
	int			j;
	int			c;
	t_uint128_t	tmp;

	c = 0;
	while (*tetra)
	{
		i = (counter == 1) ? 3 : y - 2;
		while (++i < y)
		{
			j = 0;
			tmp = 0;
			while (*tetra)
			{
				tmp += (*tetra - ((*tetra >> i) << i)) << ((j++) * (i + 1) + 1);
				*tetra >>= i;
			}
			*tetra = tmp << (i + 1);
		}
		tetra++;
		c++;
	}
	return (tetra - c);
}

t_uint128_t	*small_tetra(t_uint128_t *tetra, int y)
{
	int			i;
	int			j;
	int			c;
	t_uint128_t	tmp;

	c = 0;
	while (tetra[c])
	{
		i = 5;
		while (--i > y)
		{
			while (ft_move(tetra + c, i))
				continue;
			j = 0;
			tmp = 0;
			while (tetra[c])
			{
				tmp += (tetra[c] - ((tetra[c] >> i) << i)) << ((j++) * (i - 1));
				tetra[c] = tetra[c] >> i;
			}
			tetra[c] = tmp;
		}
		c++;
	}
	return (tetra);
}
