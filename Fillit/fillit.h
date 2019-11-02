/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroselin <kroselin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:19:21 by kroselin          #+#    #+#             */
/*   Updated: 2019/11/02 14:23:02 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
#define FILLIT_H

#include <stdio.h>
#include "libft/libft.h"
#include <sys/types.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/stat.h>
#include <fcntl.h>
#define BUFF_SIZE 21
#define LEFT (uint64_t)34952 /* 1000 1000 1000 1000 */
#define TOP (uint64_t)61440 /* 1111 0000 0000 0000 */

typedef struct		s_etra
{
	char 			letter;
	uint64_t		tetra;
	struct s_etra	*next;
}					t_etra;

char		**ft_strsplit(char const *s, char c);
int			ft_count_mass(char const *s, char c);
int         check_tetramino(uint64_t src);
uint64_t    move_tetro(uint64_t tmp);
int         work_with_tetri(char *content, t_etra *tetrases, char c);
int         is_it_square(char **arr);
int         is_valid(int fd, t_etra *tetrases);
void		ft_strrev(char *s);
char		*ft_print_bit(int n);
void		ft_add_tetra(t_etra *t, uint64_t content, char letter);

#endif

