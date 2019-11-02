/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 13:28:33 by mdirect           #+#    #+#             */
/*   Updated: 2019/11/02 14:11:37 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

void	ft_add_tetra(t_etra *t, uint64_t content, char letter)
{
	t->tetra = content;
	t->letter = letter;
	t->next = t + 1;
}