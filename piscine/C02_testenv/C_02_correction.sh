#!/bin/bash

cp ../projects/C02_testenv/ex00/main.c ./ex00/main.c
cp ../projects/C02_testenv/ex01/main.c ./ex01/main.c
cp ../projects/C02_testenv/ex02/main.c ./ex02/main.c
cp ../projects/C02_testenv/ex03/main.c ./ex03/main.c
cp ../projects/C02_testenv/ex04/main.c ./ex04/main.c
cp ../projects/C02_testenv/ex05/main.c ./ex05/main.c
cp ../projects/C02_testenv/ex06/main.c ./ex06/main.c
cp ../projects/C02_testenv/ex07/main.c ./ex07/main.c
cp ../projects/C02_testenv/ex08/main.c ./ex08/main.c
cp ../projects/C02_testenv/ex09/main.c ./ex09/main.c
cp ../projects/C02_testenv/ex10/main.c ./ex10/main.c
cp ../projects/C02_testenv/ex11/main.c ./ex11/main.c
cp ../projects/C02_testenv/ex12/main.c ./ex12/main.c

norminette ./*/f*
 $1

gcc -Werror -Wall -Wextra ./ex00/main.c ./ex00/ft_strcpy.c
echo "Exercise 00:"
./a.out | cat -e
echo ""
echo ""
gcc -Werror -Wall -Wextra ./ex01/main.c ./ex01/ft_strncpy.c
echo "Exercise 01:"
./a.out | cat -e
echo ""
echo ""
gcc -Werror -Wall -Wextra ./ex02/main.c ./ex02/ft_str_is_alpha.c
echo "Exercise 02:"
./a.out | cat -e
echo ""
echo ""
gcc -Werror -Wall -Wextra ./ex03/main.c ./ex03/ft_str_is_numeric.c
echo "Exercise 03:"
./a.out | cat -e
echo ""
echo ""
gcc -Werror -Wall -Wextra ./ex04/main.c ./ex04/ft_str_is_lowercase.c
echo "Exercise 04:"
./a.out
echo ""
echo ""
gcc -Werror -Wall -Wextra ./ex05/main.c ./ex05/ft_str_is_uppercase.c
echo "Exercise 05:"
./a.out | cat -e
echo ""
echo ""
gcc -Werror -Wall -Wextra ./ex06/main.c ./ex06/ft_str_is_printable.c
echo "Exercise 06:"
./a.out
echo ""
echo ""
gcc -Werror -Wall -Wextra ./ex07/main.c ./ex07/ft_strupcase.c
echo "Exercise 07:"
./a.out
echo ""
echo ""
gcc -Werror -Wall -Wextra ./ex08/main.c ./ex08/ft_strlowcase.c
echo "Exercise 08:"
./a.out
echo ""
echo ""
gcc -Werror -Wall -Wextra ./ex09/main.c ./ex09/ft_strcapitalize.c
echo "Exercise 09:"
./a.out
echo ""
echo ""
gcc -Werror -Wall -Wextra ./ex10/main.c ./ex10/ft_strlcpy.c
echo "Exercise 10:"
./a.out
echo ""
echo ""
gcc -Werror -Wall -Wextra ./ex11/main.c ./ex11/ft_putstr_non_printable.c
echo "Exercise 11:"
./a.out
echo ""
echo ""
gcc -Werror -Wall -Wextra ./ex12/main.c ./ex12/ft_print_memory.c
echo "Exercise 12:"
./a.out
echo ""
echo ""
