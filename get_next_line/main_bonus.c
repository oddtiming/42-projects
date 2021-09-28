#include "get_next_line_bonus.h"
#include <string.h>
#include <stdio.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

int	main(void)
{
	int		fd1, fd2, fd3;
	int		status;
	char	*ptr;
	char	*file1 = "./test_files/test_nl.txt";
	char	*file2 = "./test_files/test_short_nonl.txt";
	char	*file3 = "./test_files/test_long_nonl.txt";


	fd1 = open(file1, O_RDONLY);
	fd2 = open(file2, O_RDONLY);
	fd3 = open(file3, O_RDONLY);

	puts("---------STARTING TESTS NL---------\n\n");
	printf("File 1 = %s\n", file1);
	printf("Fd = %d\nbuff_size = %d\n", fd1, BUFFER_SIZE);
	while ((ptr = get_next_line(fd1)))
	{
		printf("Line ==> %s\n", ptr);
		free (ptr);
	}

	puts("---------STARTING TESTS SHORT NO NL---------\n\n");
	printf("File 2 = %s\n", file2);
	printf("Fd = %d\nbuff_size = %d\n", fd2, BUFFER_SIZE);
	while ((ptr = get_next_line(fd2)))
	{
		printf("Line ==> %s\n", ptr);
		free (ptr);
	}


	puts("---------STARTING TESTS LONG NO NL---------\n\n");
	printf("File 1 = %s\n", file3);
	printf("Fd = %d\nbuff_size = %d\n", fd3, BUFFER_SIZE);
	while ((ptr = get_next_line(fd3)))
	{
		printf("Line ==> %s\n", ptr);
		free (ptr);
	}

	status = close(fd1);
	status = close(fd2);
	status = close(fd3);
}
