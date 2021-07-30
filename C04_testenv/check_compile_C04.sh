#!/bin/bash

clear

echo "#################################"
echo ''
echo "Usage is './check_compile FOLDER'"
echo ''
echo "#################################"
echo''
cp ../projects/C04_testenv/$1/main.c ./$1/main.c

echo 'Running the norminette...'
norminette $1/f*.c

gcc $1/ft*.c $1/main.c
gcc -Wall -Wextra -Werror $1/ft*.c $1/main.c

echo ''
echo '###############'
echo 'Testing' $1
echo '###############'
echo ''

./a.out
rm ./a.out

echo ''
