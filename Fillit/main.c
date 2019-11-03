/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroselin <kroselin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:22:38 by kroselin          #+#    #+#             */
/*   Updated: 2019/11/03 16:33:14 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int 	main(int ac, char **av)
{
	int			fd;
	int			i;
	uint64_t	*tetramins;

	av[1] = "test_1.txt";
	ac = 2;

	i = 1;
	if (ac == 2)
	{
		fd = open(av[i], O_RDONLY);
		if (fd < 0)
			ft_putstr("No file with such name.\n");
		if (!(tetramins = (uint64_t *)malloc(sizeof(uint64_t) * 26)))
			return (0);
		ft_bzero(tetramins, sizeof(tetramins) * 26);
		if (!(is_valid(fd, &tetramins)))
			ft_putstr ("It's not a square/tetramine.\n");
		else
			ft_putstr ("it's a square and right tetramin.\n");
	}

	i = -1;
	while (++i < 26 && tetramins[i])
		printf("(%llu): %s\n", tetramins[i], ft_print_bit(tetramins[i]));

	return (0);
}