/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroselin <kroselin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:22:38 by kroselin          #+#    #+#             */
/*   Updated: 2019/11/06 16:06:18 by kroselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

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

uint64_t move_in_map(uint64_t tmp, uint64_t tetra, uint64_t x, int y)
{
	while ((tmp & (1 << x))== 0 && x)
		x /= y;
	if (x == 0 && (tetra & 1) == 0)
		tetra >>= 1;
	else if (x != 0)
		tetra >>= y;
	else
		return (0);
	return (tmp | tetra);
}

uint64_t place_in_map(uint64_t *tetra, int y)
{
	int			i;
	uint64_t	x;
	uint64_t 	tmp;


	i = -1;
	x = (y * y) - y;
	tmp = tetra[0];
	while (tetra[++i])
	{
		if ((tmp & tetra[i]) != 0)
		{
			if (!(tmp = move_in_map(tmp, tetra[i + 1], x, y)))
			{
				y+= 1;
				place_in_map(tetra, y);
			}

		}
		ft_print_bit(tmp);
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

	if (!(y = count_lines(tetramins)))
		ft_putstr ("Too many tetraminos\n");
	map = place_in_map(tetramins, y);
	i = -1;
	while (++i < 26 && tetramins[i])
		ft_print_bit(tetramins[i]);
	ft_print_bit(map);

	free(tetramins);
	return (0);
}