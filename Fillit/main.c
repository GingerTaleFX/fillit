/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroselin <kroselin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:22:38 by kroselin          #+#    #+#             */
/*   Updated: 2019/10/28 19:31:38 by kroselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int check_tetramino(char *src)
{
	const char *tetramins[21] = { "1110\n0100\n0000\n0000\n\0",
 						"1000\n1100\n1000\n0000\n\0",
 						"0100\n1110\n0000\n0000\n\0",
 						"0100\n1100\n0100\n0000\n\0",
 						"1100\n1100\n0000\n0000\n\0",
 						"1111\n0000\n0000\n0000\n\0",
 						"1000\n1000\n1000\n1000\n\0",
 						"1100\n1000\n1000\n0000\n\0",
 						"1110\n0010\n0000\n0000\n\0",
 						"1100\n0100\n0100\n0000\n\0",
 						"1000\n1110\n0000\n0000\n\0",
 						"0100\n0100\n1100\n0000\n\0",
 						"1000\n1000\n1100\n0000\n\0",
 						"0010\n1110\n0000\n0000\n\0",
 						"1110\n1000\n0000\n0000\n\0",
 						"0110\n1100\n0000\n0000\n\0",
 						"1000\n1100\n0100\n0000\n\0",
 						"1100\n0110\n0000\n0000\n\0",
 						"0100\n1100\n1000\n0000\n\0"};
	int	i;

	i = -1;
	while (++i < 19)
		if (ft_strcmp(tetramins[i], src) == 0)
			return (1);
	return (0);
}

char *move_tetro(char *src)
{
	char *dst;
	int i;
	int j;

	i = 0;
	j = 0;
	if (src[0] == '1')
		return (src);
	dst = ft_strnew(ft_strlen(src));
	while (src[i] != '1')
		i++;
	while (src[i] != '\0')
	{
		if (src[i] == '1' || src[i] == '0')
			dst[j++] = src[i];
		if ((j + 1) % 5 == 0)
			dst[j++] = '\n';
		i++;
	}
	while (j < i)
		dst[j++] = (!((j + 1) % 5)) ? '\n' : '0';
	dst[j] = '\0';
	printf("dst\n%s", dst);
	return (dst);
}

int work_with_tetri(char *content)
{
	char *tmp;
	int i;

	i = 0;
	tmp = ft_strnew(ft_strlen(content));
	while (content[i] != '\0')
	{
		if (content[i] == '.')
			tmp[i] = '0';
		else if (content[i] == '#')
			tmp[i] = '1';
		else
			tmp[i] = content[i];
		i++;
	}
	printf("tmp\n%s", tmp);
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

	av[1] = "testi_1.txt";
	ac = 2;
	i = 1;
	if (ac > 1)
	{
		fd = open(av[i],O_RDONLY);
		if (!(is_valid(fd)))
			ft_putstr ("It's not a square and not a tetramine");
		else
			ft_putstr ("it's a square and right tetramin");

	}
	return (0);
}