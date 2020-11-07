cmake_minimum_required(VERSION 3.17)
project(globbing C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(globbing
        compile_pattern.c
        ft_isalpha.c
        ft_isdigit.c
        ft_strchr.c
        ft_strlen.c
        ft_strsub.c
        globbing.c
        globbing.h
        utils.c get_compiled_size.c init_gtoken.c if_star_or_question.c if_backslash.c if_is_valid_bracket.c init_to_zero.c init_result_compiled.c check_not_range.c check_range.c check_not.c check_bracket.c is_question.c is_star.c is_charset_or_not_charset.c is_regular.c init_len.c is_px_less_size.c)
