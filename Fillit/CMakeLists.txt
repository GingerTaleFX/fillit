cmake_minimum_required(VERSION 3.14)
project(Fillit C)

set(CMAKE_C_STANDARD 99)

add_executable(Fillit main.c
        tests/valid/test_1.txt
        tests/valid/test_2.txt
        tests/valid/test_3.txt
        tests/valid/test_4.txt
        tests/valid/test_5.txt
        tests/valid/test_6.txt
        tests/valid/test_7.txt
        tests/invalid/testi_1.txt
        tests/invalid/testi_2.txt
        tests/invalid/testi_3.txt
        tests/invalid/testi_4.txt
        tests/invalid/testi_5.txt
        tests/invalid/testi_6.txt
        tests/invalid/testi_7.txt
        tests/invalid/testi_8.txt
        tests/invalid/testi_9.txt
        libft/libft.h
        libft/ft_strsplit.c
        libft/ft_count_mass.c
        libft/ft_putchar.c
        libft/ft_putstr.c
        libft/ft_strnew.c
        libft/ft_memalloc.c
        libft/ft_bzero.c
        fillit.h)