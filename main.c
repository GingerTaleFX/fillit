/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroselin <kroselin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:22:38 by kroselin          #+#    #+#             */
/*   Updated: 2019/11/05 13:50:28 by kroselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

//void create_map(int64_t	**tetramins, int counter)
//{
//	int size;
//	int i;
//	int j;
//	char letter;
//
//	letter = 'A';
//	i = 0;
//	j = 0;
//	size = counter;
//	while (tetramins[i])
//	{
//		while (tetramins[i][j])
//		{
//			if (tetramins[i][j] == "#")
//				ft_putchar(letter);
//			j++;
//		}
//		j = 0;
//		letter++;
//		i++;
//	}
//}

int 	main(int ac, char **av)
{
	int			fd;
	int			i;
	uint64_t	*tetramins;
//	char 		**tetris_mas;

//	av[1] = "test_1.txt";
//	ac = 2;

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

	i = -1;
	while (++i < 26 && tetramins[i])
	{

		printf("(%llu): %s\n", tetramins[i], ft_print_bit(tetramins[i]));

	}
//	tetris_mas = (char **)malloc((sizeof(*tetris_mas)) * i);
//	*tetris_mas = (char *)malloc((sizeof(tetris_mas)) * 21);
//	i = -1;
//	while (++i < 26 && tetramins[i])
//	{
//		*tetris_mas = ft_print_bit(tetramins[i]);
//		tetris_mas++;
//	}
//	create_map(&tetris_mas, i);
//	printf("how many tetrs:%d\n", i);

	free(tetramins);
	return (0);
}