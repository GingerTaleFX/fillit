/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroselin <kroselin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:19:21 by kroselin          #+#    #+#             */
/*   Updated: 2019/11/22 14:50:46 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef __uint128_t		t_uint128_t;
int						check_tetramino(t_uint128_t src);
t_uint128_t				move_tetro(t_uint128_t tmp, int y);
t_uint128_t				work_with_tetri(char *content);
int						is_valid(char *buf, int size, t_uint128_t *t);
int						river_check(char *buf);
int						correct_chars(char *buf);
t_uint128_t				*resize_tetras(t_uint128_t *tetra, int y, int counter);
int						count_lines(t_uint128_t *tetra);
int						ft_move(t_uint128_t *tetra, int y);
int						func1(t_uint128_t map, t_uint128_t *tetra, int y);
void					func2(t_uint128_t *tetra, int *y);
void					ft_print_map(t_uint128_t *tetra, int y);
int						parser(char *filename, t_uint128_t *t);
t_uint128_t				*small_tetra(t_uint128_t *tetra, int y);
t_uint128_t				make_left(int y);
t_uint128_t				make_bottom(int y);
t_uint128_t				make_right(int y);
void					tetros_counter(t_uint128_t *tetramins, int y);
int						ft_sqrt(int i);
void					ft_bzero(void *s, size_t n);

#endif
