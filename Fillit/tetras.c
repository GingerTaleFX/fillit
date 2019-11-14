/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroselin <kroselin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 11:37:15 by kroselin          #+#    #+#             */
/*   Updated: 2019/11/14 18:49:40 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
 * func count_lines count, how many lines (y) must have a map
 * */

uint64_t count_lines(uint64_t *tetra)
{
	int i;

	i = 0;
	while (tetra[i])
		i++;
	if (i >= 2 && i <= 4)
		return (4);
	else if (i >= 5 && i <= 7)
		return (5);
	else if (i >= 8 && i <= 9)
		return (6);
	else if (i >= 10 && i <= 11)
		return (7);
	else if (i >= 12 && i <= 16)
		return (8);
	else if (i >= 17 && i <= 20)
		return (9);
	else if (i >= 21 && i <= 25)
		return (10);
	else if (i == 26)
		return (11);
	else
		return (0);
}

/*
 * Make tetras bigger, if there are more then 4*
 */
uint64_t *resize_tetras(uint64_t *tetra, int y, int counter)
{
	int			i;
	int			j;
	int 		c;
	uint64_t	tmp;

	c = 0;
//	printf("tetras[%d] = %llu\n", c, *tetra);
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
//		printf("tetras[%d] = %llu\n", c, *tetra);
		tetra++;
		c++;
//		printf("tetras[%d] = %d\n", c, *tetra);
	}

	return (tetra - c);
}