#include <string.h>
#include <stdio.h>
#include <stdlib.h>
char	*ft_strjoin(int size, char **strs, char *sep);

int	main(void)
{
	int	size = 5;
    char *strings[5] = {"This", "should", "form", "a", "sentence"};
    int i = 0;
	char *sep = "";
	
	for(i = 0; i < size; i++)
        printf("String #%d (length: %lu) = '%s'\n", i, strlen(strings[i]),strings[i]);
	printf("The separator is '%s'\n\n", sep);
	printf("For size = %d:\n", size);
	printf("Resulting string:\n'%s'\n(length: %lu)\n\n", ft_strjoin(size, strings,  sep), strlen(ft_strjoin(size, strings, sep)));

	char *strtest = "";
	size = 3;
	printf("For size = %d:\n", size);
	printf("Resulting string:\n'%s'\n(length: %lu)\n\n", ft_strjoin(size, strings,  sep), strlen(ft_strjoin(size, strings, sep)));
	size = 1;
	printf("For size = %d:\n", size);
	printf("Resulting string:\n'%s'\n(length: %lu)\n\n", ft_strjoin(size, strings,  sep), strlen(ft_strjoin(size, strings, sep)));
	size = 0;
	printf("For size = %d:\n", size);
	printf("Resulting string:\n'%s'\n(length: %lu)\n", ft_strjoin(size, strings,  sep), strlen(ft_strjoin(size, strings, sep)));
	size = 1;
	printf("For str = %s:\n", strtest);
	printf("Resulting string:\n'%s'\n(length: %lu)\n\n", ft_strjoin(size, &strtest,  sep), strlen(ft_strjoin(size, &strtest, sep)));

	char *text[10];	
	text[0] = "Testando";
	text[1] = "a";
	text[2] = "funcao";
	text[3] = "ft_strjoin";
	text[4] = "com";
	text[5] = "o";
	text[6] = "separador";
	text[7] = "\' - \'";
	text[8] = "e tamanho";
	text[9] = "10";

	printf("%s\n", ft_strjoin(10, text, " - "));

	char *tablo[6];
	tablo[0] = "coucou";
	tablo[1] = "bite";
	tablo[2] = "fesse";
	tablo[3] = "de";
	tablo[4] = "la";
	tablo[5] = "merde";
	printf("%s\n", ft_strjoin(6, tablo, "!"));
	return (0);
}
