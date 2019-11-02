/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroselin <kroselin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:22:38 by kroselin          #+#    #+#             */
/*   Updated: 2019/10/31 12:53:26 by kroselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int main(int ac, char **av) {
	int fd;
	int i;

//	av[1] = "test_6.txt";
//	ac = 2;
	i = 1;
	if (ac == 2)
	{
<<<<<<< HEAD
		fd = open(av[i],O_RDONLY);
=======
		fd = open(av[i], O_RDONLY);
>>>>>>> master
		if (fd < 0)
			ft_putstr("No file with such name.\n");
		if (!(is_valid(fd)))
			ft_putstr ("It's not a square/tetramine.\n");
		else
			ft_putstr ("it's a square and right tetramin.\n");

	}
	return (0);
}