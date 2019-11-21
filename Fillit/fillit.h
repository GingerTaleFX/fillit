/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroselin <kroselin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:19:21 by kroselin          #+#    #+#             */
/*   Updated: 2019/11/21 11:19:53 by mdirect          ###   ########.fr       */
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
typedef unsigned __int128 uint128_t;

int         check_tetramino(uint128_t src);
uint128_t    move_tetro(uint128_t tmp, int y);
uint128_t    work_with_tetri(char *content);
int			is_valid(char *buf, int size, uint128_t *t);
int			river_check(char *buf);
int			correct_chars(char *buf);
void		ft_print_bit(uint128_t n, int y);
uint128_t	*resize_tetras(uint128_t *tetra, int y, int counter);
uint128_t	count_lines(uint128_t *tetra);
int			ft_move(uint128_t *tetra, int y);
int 		func1(uint128_t map, uint128_t *tetra, int y);
void		func2(uint128_t *tetra, int *y);
void		ft_print_map(uint128_t *tetra, int y);
int			parser(char *filename, uint128_t *t);

#endif

