cmake_minimum_required(VERSION 3.14)
project(Fillit)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(libft)
include_directories(tests)
include_directories(tests/invalid)
include_directories(tests/valid)

add_executable(
        tests/invalid/testi_1.txt
        tests/invalid/testi_2.txt
        tests/invalid/testi_3.txt
        tests/invalid/testi_4.txt
        tests/invalid/testi_5.txt
        tests/invalid/testi_6.txt
        tests/invalid/testi_7.txt
        tests/invalid/testi_8.txt
        tests/invalid/testi_9.txt
        tests/valid/test_0.txt
        tests/valid/test_1.txt
        tests/valid/test_2.txt
        tests/valid/test_3.txt
        tests/valid/test_4.txt
        tests/valid/test_5.txt
        tests/valid/test_6.txt
        tests/valid/test_7.txt
        fillit.h
        main.c
        is_valid.c
        print.c
        tetras.c
        algos.c
        help_function.c)
