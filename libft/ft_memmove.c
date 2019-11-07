/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroselin <kroselin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 09:56:21 by kroselin          #+#    #+#             */
/*   Updated: 2019/11/07 15:47:57 by kroselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*y;

	y = dst;
	if (!((unsigned char *)dst) && !((const unsigned char *)src))
		return (0);
	if (src < dst)
	{
		dst = dst + (len - 1);
		src = src + (len - 1);
		while (len--)
		{
			*((unsigned char *)dst) = *((const unsigned char *)src);
			dst-- && src--;
		}
	}
	if (src > dst)
	{
		while (len--)
		{
			*((unsigned char *)dst) = *((const unsigned char *)src);
			dst++ && src++;
		}
	}
	return (y);
}
