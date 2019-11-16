/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroselin <kroselin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:22:38 by kroselin          #+#    #+#             */
/*   Updated: 2019/11/16 21:21:25 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

int 	main(int ac, char **av)
{
	int			fd;
	int			i;
	int			y;
	uint64_t	*tetramins;
	uint64_t	map;

	y = 0;
	av[1] = "test_1.txt";
	ac = 2;

	if (ac != 2)
		return (write(1, "usage: ./fillit input_tetraminos\n", 33));
	if ((fd = open(av[1], O_RDONLY)) < 0)
		return (write(1, "No file with such name.\n", 24));
	if (!(tetramins = (uint64_t *)malloc(sizeof(uint64_t) * 26)))
		return (write(1, "error: malloc tetraminos\n", 25));
	ft_bzero(tetramins, sizeof(tetramins) * 26);
	if (!(is_valid(fd, &tetramins)))
		return (write(1, "It's not a square/tetramine.\n", 29));
	else
		ft_putstr ("it's a square and right tetramin.\n");
	if (close(fd) == -1)
		return (write(1, "error: close fd\n", 16));
	if (!(y = count_lines(tetramins)))
		ft_putstr ("Too many tetraminos\n");
	if (y > 4)
		tetramins = resize_tetras(tetramins, y, 1);
	func2(tetramins, &y);
//	map = place_in_map(tetramins, &y);

//	i = -1;
//	while (++i < 26 && tetramins[i])
//	{
//		printf("tetra[%d] = %llu\n", i, tetramins[i]);
//		ft_print_bit(tetramins[i], y);
//	}

	free(tetramins);
	return (0);
}