/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 13:10:30 by mdirect           #+#    #+#             */
/*   Updated: 2019/11/15 14:07:26 by kroselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

void	ft_print_bit(uint64_t n, int x, int y)
{
	int i;

	i = x - 1;
	while (i >= 0)
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
	write(1, "\n", 1);
}

void	ft_print_map(uint64_t *tetra, int y)
{
	int		i;
	int		j;
	char	letter;

	i = y * y - 1;
	while (i >= 0)
	{
		j = 0;
		while (tetra[j])
		{
			if ((tetra[j] & (1 << i)))
			{
				letter = j + 65;
				write(1, &letter, 1);
				break ;
			}
			j++;
		}
		if (!tetra[j])
			write(1, ".", 1);
		if (i % y == 0 && i)
			write(1, "\n", 1);
		i--;
	}
}
