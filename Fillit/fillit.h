/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroselin <kroselin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:19:21 by kroselin          #+#    #+#             */
/*   Updated: 2019/11/19 11:18:02 by kroselin         ###   ########.fr       */
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
#define LEFT (uint64_t)34952 /* 1000 1000 1000 1000 */
#define TOP (uint64_t)61440 /*  1111 0000 0000 0000 */

int         check_tetramino(uint64_t src);
uint64_t    move_tetro(uint64_t tmp, int y);
uint64_t    work_with_tetri(char *content);
int			is_valid(char *buf, int size, uint64_t *t);
int			river_check(char *buf);
int			correct_chars(char *buf);
void		ft_print_bit(uint64_t n, int x, int y);
uint64_t	place_in_map(uint64_t *tetra, int *y);
int			check_tetra_in_map(uint64_t tetra);
uint64_t	move_in_map(uint64_t map, uint64_t *tetra, uint64_t x, int y);
uint64_t	*resize_tetras(uint64_t *tetra, int y, int counter);
uint64_t	count_lines(uint64_t *tetra);
uint64_t	ft_move(uint64_t tetra, int y);
int 		func1(uint64_t map, uint64_t *tetra, int y);
void		func2(uint64_t *tetra, int *y);
void		ft_print_map(uint64_t *tetra, int y);
int			parser(char *filename, uint64_t *t);

#endif

