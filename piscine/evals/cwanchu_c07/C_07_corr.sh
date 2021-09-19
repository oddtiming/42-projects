#!bin/bash/
echo "*** starting norminette ***"
echo "\nex00===================="
cd ex00
norminette -R CheckForbiddenSourceHeader
cd ..
echo "\nex01===================="
cd ex01
norminette -R CheckForbiddenSourceHeader
cd ..
echo "\nex02===================="
cd ex02
norminette -R CheckForbiddenSourceHeader
cd ..
echo "\nex03===================="
cd ex03
norminette -R CheckForbiddenSourceHeader
cd ..
echo "\nex04===================="
cd ex04
norminette -R CheckForbiddenSourceHeader
cd ..
echo "\nex05===================="
cd ex05
norminette -R CheckForbiddenSourceHeader
cd ..
echo "\n==========DONE=========="

echo "\n*** copying main ... ***"

cp main00.c ex00
cp main01.c ex01
cp main02.c ex02
cp main03.c ex03
cp main04.c ex04
cp main05.c ex05

echo "\n*** main copied***"

echo "\n*** starting tests..."

echo "\nex00===================="
cd ex00
gcc -Wall -Wextra -Werror main00.c && ./a.out
cd ..
echo "\nex01===================="
cd ex01
gcc -Wall -Wextra -Werror main01.c && ./a.out
cd ..
echo "\nex02===================="
cd ex02
gcc -Wall -Wextra -Werror main02.c && ./a.out
cd ..
echo "\nex03===================="
cd ex03
gcc -Wall -Wextra -Werror main03.c && ./a.out
cd ..
echo "\nex04===================="
cd ex04
gcc -Wall -Wextra -Werror main04.c && ./a.out
cd ..
echo "\nex05===================="
cd ex05
gcc -Wall -Wextra -Werror main05.c && ./a.out
cd ..

echo "\n=======Done with tests========="

echo " \n*** Removing main and a.out ***"

echo "ex00===================="
cd ex00
rm main00.c a.out
cd ..
echo "ex01===================="
cd ex01
rm main01.c a.out
cd ..
echo "ex02===================="
cd ex02
rm main02.c a.out
cd ..
echo "ex03===================="
cd ex03
rm main03.c a.out
cd ..
echo "ex04===================="
cd ex04
rm main04.c a.out
cd ..
echo "ex05===================="
cd ex05
rm main05.c a.out
cd ..
echo "\n=========DONE==========="
