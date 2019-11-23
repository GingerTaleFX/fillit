/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroselin <kroselin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:22:38 by kroselin          #+#    #+#             */
/*   Updated: 2019/11/23 17:48:05 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	tetros_counter(t_uint128_t *tetramins, int y)
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
	t_uint128_t	*tetramins;

	y = 0;
	if (ac != 2)
		return (write(1, "usage: ./fillit input_tetraminos\n", 33));
	if (!(tetramins = (t_uint128_t *)malloc(sizeof(t_uint128_t) * 26)))
		return (write(1, "error\n", 6));
	ft_bzero(tetramins, sizeof(*tetramins) * 26 * 16);
	if (!(parser(av[1], tetramins)))
		return (write(1, "error\n", 6));
	if ((y = count_lines(tetramins)) > 26)
		return (write(1, "error\n", 6));
	tetros_counter(tetramins, y);
	free(tetramins);
	return (0);
}
