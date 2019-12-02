/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 13:10:30 by mdirect           #+#    #+#             */
/*   Updated: 2019/11/22 14:42:27 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_map(t_uint128_t *tetra, int y)
{
	int			i;
	int			j;
	char		letter;

	i = y * y - 1;
	while (i >= 0)
	{
		j = 0;
		while (tetra[j])
		{
			if ((tetra[j] & ((t_uint128_t)1 << i)))
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
	write(1, "\n", 1);
}
