/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroselin <kroselin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:22:38 by kroselin          #+#    #+#             */
/*   Updated: 2019/11/11 14:49:57 by kroselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
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

uint64_t *resize_tetras(uint64_t *tetra, int y, int counter)
{
	int			i;
	int			j;
	int 		c;
	uint64_t	tmp;

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
//				printf("tmp[%d] = %d\n",j, tmp);
				j++;
			}
			*tetra = tmp << (i + 1);
			i++;
		}
//		printf("tetra = %d\n", *tetra);
		tetra++;
		c++;
	}

	return (tetra - c);
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

uint64_t move_in_map(uint64_t tmp, uint64_t tetra, uint64_t x, int y)
{
	int	l;
	uint64_t rem;

	rem = tetra;
	l = y * y;
	while (l)
	{
		while ((tmp & tetra) != 0)
		{
			tetra >>= 1;
			l--;
//			if (l % y == 0)
//				tetra >>= y - 1;
		}
		l--;
	}

	if ((check_tetra_in_map(tetra)) != 4)
	{
		tetra = rem;
		tmp <<= (x/y);
		tetra <<= (x/y);
		tetra = move_in_map(tmp, tetra, x, y);
	}

//	while ((tmp & (1 << x)) == 0 && x)
//		x /= y;
//	if (x == 0 && (tetra & 1) == 0)
//		tetra >>= 1;
//	else if (x != 0)
//		tetra >>= y;
//	else
//		return (0);
	return (tmp | tetra);
}

/*
 * we get massive of tetraminos and the number of lines in our map.
 * then we find, how many peace should be in it - x.
 * x = (y * y) - y is necessary for test, but i change some things.
 * first tetro places in tmp, then we take second one and tries to put it in the map - move_in_map
 *
 * The letter doesn't work! I have'nt imagined yet, how to solve this problem without lists.
 * */

uint64_t place_in_map(uint64_t *tetra, int y)
{
	int			i;
	uint64_t	x;
	uint64_t 	tmp;
	char		letter;

	letter = 'A';
	i = -1;
	x = y * y;
	tmp = 0;
	while (tetra[++i])
	{
		if ((tmp & tetra[i]) != 0)
		{
			if (!(tmp = move_in_map(tmp, tetra[i], x, y)))
			{
				y+= 1;
				place_in_map(tetra, y);
			}
		}
		else
			tmp |= tetra[i];
		ft_print_bit(tmp, x, y);
//		letter++;
	}
	return (tmp);
}

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

//	i = 0;
//	while (tetramins[i])
//		i++;
	if (!(y = count_lines(tetramins)))
		ft_putstr ("Too many tetraminos\n");
	if (y > 4)
		tetramins = resize_tetras(tetramins, y, 1);
	map = place_in_map(tetramins, y);
	i = -1;
	while (++i < 26 && tetramins[i])
//		printf("tet[%c] = %llu\n", i, tetramins[i]);
		ft_print_bit(tetramins[i],(y * y), y);
//	ft_print_bit(map);

	free(tetramins);
	return (0);
}