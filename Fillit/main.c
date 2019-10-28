/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroselin <kroselin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:22:38 by kroselin          #+#    #+#             */
/*   Updated: 2019/10/28 15:05:49 by kroselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

s_tetro	*new_tetro(int x, int y)
{
	s_tetro	*n_tetro;

	n_tetro = (s_tetro *)malloc(sizeof(s_tetro));
	n_tetro->x = x;
	n_tetro->y = y;
	n_tetro->next = NULL;
	return(n_tetro);
}
s_tetro *save_tetri(char *str)
{
	s_tetro	*new;
	s_tetro *tmp;
	int i;
	int j;

	j = 0;
	i = 0;
	tmp = new_tetro(j, i);
	new - tmp;
	while (str[i] != '\0')
	{
		while (str[j] != '\n')
		{
			if (str[j] == '#')
			{
				if (tmp == NULL)
					tmp = new_tetro(j, i);
				tmp = tmp->next;
			}
			j++;
		}
		i++;
	}
	return (new);
}

// ####
// ....
// ....
// ....
int check_tetro(s_tetro *tetro)
{
	s_tetro *tmp;

	tmp = tetro;
		if (tmp->x == 0 && tmp->y == 0)
		{
			tmp = tmp->next;
			if (tmp->x == 1 && tmp->y == 0)
			{
				tmp = tmp->next;
				if (tmp->x == 2 && tmp->y == 0)
				{
					tmp = tmp->next;
					if (tmp->x == 3 && tmp->y == 0)
					{
						tmp = tmp->next;
						if (tmp->x == 4 && tmp->y == 0)
							return (1);
					}
				}
			}
		}
	return (0);
}

int work_with_tetri(char *content)
{
	s_tetro	*new;

	new = save_tetri(content);
	if((check_tetro(new)))
		return (1);
	else
		return (0);
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

	av[1] = "test_1.txt";
	ac = 2;
	i = 1;
	if (ac > 1)
	{
		fd = open(av[i],O_RDONLY);
		if (!(is_valid(fd)))
			ft_putstr ("It's not a square");
		else
			ft_putstr ("it's a square");

	}
	return (0);
}