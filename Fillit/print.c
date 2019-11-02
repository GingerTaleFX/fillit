/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdirect <mdirect@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 13:10:30 by mdirect           #+#    #+#             */
/*   Updated: 2019/10/31 14:27:59 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

void		ft_strrev(char *s)
{
	size_t	i;
	size_t	n;
	char	c;

	if (!s)
		return ;
	n = ft_strlen(s) - 1;
	i = 0;
	while (i < n)
	{
		c = s[i];
		s[i] = s[n];
		s[n] = c;
		i++;
		n--;
	}
}

char		*ft_print_bit(int n)
{
	int		nb;
	int		len;
	char	*str;
	int		i;s

	nb = n;
	len = 1;
	while (nb / 2)
	{
		len++;
		nb = nb / 2;
	}
	str = ft_strnew(len);
	i = 0;
	while (i < len)
	{
		str[i++] = (n % 2) ? '1' : '0';
		n = n / 2;
	}
	ft_strrev(str);
	return (str);
}
