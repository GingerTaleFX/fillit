/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroselin <kroselin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:22:38 by kroselin          #+#    #+#             */
/*   Updated: 2019/11/02 14:21:33 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int main(int ac, char **av) {
	int		fd;
	int		i;
	t_etra	*tetrases;

	av[1] = "test_1.txt";
	ac = 2;
	i = 1;
	if (ac == 2)
	{
		fd = open(av[i], O_RDONLY);
		if (fd < 0)
			ft_putstr("No file with such name.\n");
		if (!(tetrases = (t_etra *)malloc(sizeof(t_etra) * 27))) /* max 26 tetraminok */
			return (0);		/* error: create struct */
		ft_bzero(tetrases, sizeof(tetrases) * 27);
		if (!(is_valid(fd, tetrases)))
			ft_putstr ("It's not a square/tetramine.\n");
		else
			ft_putstr ("it's a square and right tetramin.\n");
		while (tetrases)
		{
			printf("%s\n", ft_print_bit(tetrases->tetra));
			tetrases = tetrases->next;
		}
	}
	return (0);
}