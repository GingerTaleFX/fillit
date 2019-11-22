/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroselin <kroselin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:22:38 by kroselin          #+#    #+#             */
/*   Updated: 2019/11/22 13:52:40 by kroselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	tetros_counter(uint128_t *tetramins, int y)
{
	int i;

	if (y > 4)
		tetramins = resize_tetras(tetramins, y, 1);
	else if (y < 4)
	{
		tetramins = small_tetra(tetramins, y);
		i = -1;
		while (++i < 26 && tetramins[i])
			tetramins[i] = move_tetro(tetramins[i], y);
	}
	func2(tetramins, &y);
}

int		main(int ac, char **av)
{
	int			y;
	uint128_t	*tetramins;

//	av[1] = "test_2.txt";
//	ac = 2;
	y = 0;
	if (ac != 2)
		return (write(1, "usage: ./fillit input_tetraminos\n", 33));
	if (!(tetramins = (uint128_t *)malloc(sizeof(uint128_t) * 26)))
		return (write(1, "error: malloc tetraminos\n", 25));
	ft_bzero(tetramins, sizeof(*tetramins) * 26 * 16);
	if (!(parser(av[1], tetramins)))
		return (write(1, "It's not a square/tetramine.\n", 29));
	else
		write(1, "it's a square and right tetramin.\n", 34);
	if ((y = count_lines(tetramins)) > 26)
		return (write(1, "Too many tetramins\n", 20));
	tetros_counter(tetramins, y);
	return (0);
}
