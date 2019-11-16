/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroselin <kroselin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:22:38 by kroselin          #+#    #+#             */
/*   Updated: 2019/11/16 22:50:52 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
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

uint64_t move_tetro(uint64_t tmp, int y)
{
	uint64_t	top;
	uint64_t	left;
	int			i;

	i = y * y;
	top = 0;
	left = 0;
	while (--i >= 0)
	{
		if (i >= y * (y - 1))
			top |= (1 << i);
		if (!((i + 1) % y))
			left |= (1 << i);
	}
	while ((left & tmp) == 0)
		tmp <<= 1;
	while ((top & tmp) == 0)
		tmp <<= y;
	return (tmp);
}

uint64_t work_with_tetri(char *content)
{
	uint64_t	tmp;
	int			j;

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
	tmp = move_tetro(tmp, 4);
	if (!(check_tetramino(tmp)))
		return (0);
	return (tmp);
}

int correct_chars(char *buf)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < 19)
	{
		if (buf && buf[i] != '\n' && buf[i] != '.' && buf[i] != '#')
			return (0);
		if (buf[i] == '\n' && !(((i + 1) % 5)== 0))
			return (0);
		if (buf[i] == '#')
			count++;
		i++;
	}
	return (count);
}

int river_check(char *buf)
{
	int i;
	int count;

	 i = 0;
	 count = 0;
	 while (i < 19)
	 {
	 	if (buf[i] == '#')
		{
			if (i + 1 <= 18 && buf[i + 1] == '#')
				count++;
			if (i - 1 >= 0 && buf[i - 1] == '#')
				count++;
			if (i + 5 <= 18 && buf[i + 5] == '#')
				count++;
			if (i - 5 >= 0 && buf[i - 5] == '#')
				count++;
		}
	 	i++;
	 }
	return (count);
}

int is_valid(int fd, uint64_t *t)
{
	char	buff[545]; /*26 тетраминок * 21 символ = 546, но начинаем с 0, поэтому 545*/
	int		ret;
	int		i;

	ret = read(fd, buff, 545);
	if (ret > 544 || ret < 19)
		return (0);
	buff[ret] = '\0';
	i = 0;
	while (i <= ret)
	{
		if (correct_chars(buff + i) != 4)
			return (0);
		if (river_check(buff + i) != 4 && river_check(buff + i) != 8)
			return (0);
		*t = work_with_tetri(buff + i);
		t++;
		i+= 21;
	}
	free(buff); /*уточнить, а можно ли так делать. По идее надо, т.к. тетраминок может юыть меньше, чем на 545 байт. И возвращаются они не в будфере, а в виже чисел*/
	return (1);
}