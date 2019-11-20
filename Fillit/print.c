/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 13:10:30 by mdirect           #+#    #+#             */
/*   Updated: 2019/11/20 13:15:07 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_bit(uint128_t n, int y)
{
	int i;

	i = y * y - 1;
	while (i != UINT64_MAX)
	{
		if (n & ((uint128_t)1 << i))
			write(1, "#", 1);
		else
			write(1, ".", 1);
		if (i % y == 0)
			write(1, "\n", 1);
		i--;
	}
	write(1, "\n", 1);
}

void	ft_print_map(uint128_t *tetra, int y)
{
	int			i;
	int			j;
	char		letter;

	i = y * y - 1;
	while (i != UINT64_MAX)
	{
		j = 0;
		while (tetra[j])
		{
			if ((tetra[j] & ((uint128_t)1 << i)))
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
