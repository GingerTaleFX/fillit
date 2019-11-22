/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroselin <kroselin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:22:38 by kroselin          #+#    #+#             */
/*   Updated: 2019/11/21 21:43:43 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

int 	main(int ac, char **av)
{
	int			fd;
	int			i, j;
	int			y;
	uint128_t	*tetramins;
	uint128_t	map;

	y = 0;
	av[1] = "test_1.txt";
	ac = 2;

	if (ac != 2)
		return (write(1, "usage: ./fillit input_tetraminos\n", 33));
	if (!(tetramins = (uint128_t *)malloc(sizeof(uint128_t) * 26)))
		return (write(1, "error: malloc tetraminos\n", 25));
	ft_bzero(tetramins, sizeof(*tetramins) * 26 * 16);
	if (!(parser(av[1], tetramins)))
		return (write(1, "It's not a square/tetramine.\n", 29));
	else
		ft_putstr ("it's a square and right tetramin.\n");
	if ((y = count_lines(tetramins)) > 26)
		ft_putstr ("Too many tetraminos\n");

	if (y == 1)
	{
		if (tetramins[0] == 52224)
		{
			tetramins[0] = 15;
			ft_print_map(tetramins, 2);
		}

		else if (tetramins[0] == 34952 || tetramins[0] == 61440)
			ft_print_map(tetramins, 4);
		else
		{
			tetramins = small_tetra(tetramins, 4);
			ft_print_map(tetramins, 3);
		}

	}
	else if ( y > 4)
	{
		tetramins = resize_tetras(tetramins, y, 1);
		func2(tetramins, &y);
	}
	else
	{
		tetramins = small_tetra(tetramins, y);
		i = -1;
		while (++i < 26 && tetramins[i])
			tetramins[i] = move_tetro(tetramins[i], y);
		func2(tetramins, &y);
	}


//	i = -1;
//	while (++i < 26 && tetramins[i])
//	{
//		printf("tetra[%d] = %llu\n", i, tetramins[i]);
//		ft_print_bit(tetramins[i], y);
//	}
//	free(tetramins);
	return (0);
}