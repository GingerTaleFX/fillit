/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 19:46:28 by mdirect           #+#    #+#             */
/*   Updated: 2019/09/17 20:07:42 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lenint(int n)
{
	int i;

	i = (n > 0) ? 0 : 1;
	while (n)
	{
		i++;
		n = n / 10;
	}
	return (i);
}