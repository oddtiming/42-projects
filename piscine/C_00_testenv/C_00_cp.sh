#!/bin/bash

cp ../projects/C_00_testenv/ex00/main.c ./ex00/main.c
cp ../projects/C_00_testenv/ex01/main.c ./ex01/main.c
cp ../projects/C_00_testenv/ex02/main.c ./ex02/main.c
cp ../projects/C_00_testenv/ex03/main.c ./ex03/main.c
cp ../projects/C_00_testenv/ex04/main.c ./ex04/main.c
cp ../projects/C_00_testenv/ex05/main.c ./ex05/main.c
cp ../projects/C_00_testenv/ex06/main.c ./ex06/main.c
cp ../projects/C_00_testenv/ex07/main.c ./ex07/main.c
cp ../projects/C_00_testenv/ex08/main.c ./ex08/main.c

norminette ./*/f*

gcc -Werror -Wall -Wextra ./ex00/main.c ./ex00/ft_putchar.c
./a.out | cat -e
echo ""
echo ""
gcc -Werror -Wall -Wextra ./ex01/main.c ./ex01/ft_print_alphabet.c
./a.out | cat -e
echo ""
echo ""
gcc -Werror -Wall -Wextra ./ex02/main.c ./ex02/ft_print_reverse_alphabet.c
./a.out | cat -e
echo ""
echo ""
gcc -Werror -Wall -Wextra ./ex03/main.c ./ex03/ft_print_numbers.c
./a.out | cat -e
echo ""
echo ""
gcc -Werror -Wall -Wextra ./ex04/main.c ./ex04/ft_is_negative.c
./a.out
echo ""
echo ""
gcc -Werror -Wall -Wextra ./ex05/main.c ./ex05/ft_print_comb.c
./a.out | cat -e
echo ""
echo "Total words: (should be 120)"
./a.out | wc -w
echo ""
gcc -Werror -Wall -Wextra ./ex06/main.c ./ex06/ft_print_comb2.c
./a.out
echo ""
echo "Total words: (should be 9900)"
./a.out | wc -w
echo ""
gcc -Werror -Wall -Wextra ./ex07/main.c ./ex07/ft_putnb.c
./a.out
echo ""
echo ""
gcc -Werror -Wall -Wextra ./ex08/main.c ./ex08/ft_putnb.c
./a.out
echo ""
