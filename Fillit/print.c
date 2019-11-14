/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 13:10:30 by mdirect           #+#    #+#             */
/*   Updated: 2019/11/14 11:43:23 by kroselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

void	ft_print_bit(uint64_t n, int x, int y)
{
	int i;
	int tmp;

	i = x;
	while ((n & (1 << i)) == 0)
		i--;
	tmp = i;
	while (i > 0)
	{
		if ((n & (1 << i)) == 0)
			write(1, ".", 1);
		else if ((n & (1 << i)) != 0)
		{
			ft_putchar('#');
		}
		if (i % y == 0)
			write(1, "\n", 1);
		i--;
	}
	i = x - tmp;
	while (i)
	{
		write(1, ".", 1);
		i--;
		if (i % y == 0)
			write(1, "\n", 1);
	}
	write(1, "\n", 1);
}