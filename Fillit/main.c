/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroselin <kroselin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:22:38 by kroselin          #+#    #+#             */
/*   Updated: 2019/11/05 11:10:01 by kroselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int check_tetramino(uint64_t src)
{
	uint64_t tetramins[19] = {58368, 35968, 19968, 19520,
							  52224,
							  34952, 61440,
							  51328, 57856, 50240, 36352, 17600, 35008, 11776, 59392,
							  27648, 35904, 50688, 19584};
	int	i;

	i = -1;
	while (++i < 19)
		if(tetramins[i] == src)
			return (1);
	return (0);
}

uint64_t move_tetro(uint64_t tmp)
{
	while ((LEFT & tmp) == 0)
		tmp <<= 1;
	while ((TOP & tmp) == 0)
		tmp <<= 4;
	return (tmp);
}

int work_with_tetri(char *content)
{
	uint64_t tmp;
	int j;

	j = 15;
	tmp = 0;
	while (*content && j >= 0)
	{
		if (*content == '\n')
			content++;
		if (*content == '#')
			tmp = (tmp | 1 << j);
		j--;
		content++;
	}
//	printf("tmp\n%s", tmp);
	tmp = move_tetro(tmp);
	if (!(check_tetramino(tmp)))
		return (0);
	return (1);
}

int is_it_square(char **arr)
{
	int i;
	int j;
	int x;
	int y;

	x = 0;
	y = 0;
	i = 0;
	j = 0;
	while (arr[i] != '\0')
	{
		while (arr[i][j] != '\0')
		{
			if (arr[i][j] == '#')
				x++;
			if (arr[i][j] == '.')
				y++;
			j++;
		}
		j = 0;
		i++;
	}
	if (i != 4)
		return (0);
	if (x != 4 || y != 12)
		return (0);
	else
		return (1);
}

int is_valid(int fd)
{
	char	buf[BUFF_SIZE + 1];
	char	**arr;
	int		ret;

	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		arr = ft_strsplit(buf, '\n');
		if (!(is_it_square(arr)))
			return (0);
		if (!(work_with_tetri(buf)))
			return (0);
	}
	free(arr);
	return (1);
}

int main(int ac, char **av) {
	int fd;
	int i;

	av[1] = "test_6.txt";
	ac = 2;
	i = 1;
	if (ac == 2)
	{
		fd = open(av[i],O_RDONLY);
		if (fd < 0)
			ft_putstr("No file with such name.");
		if (!(is_valid(fd)))
			ft_putstr ("It's not a square/tetramine.");
		else
			ft_putstr ("it's a square and right tetramin.");

	}
	return (0);
}