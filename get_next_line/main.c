#include "get_next_line.h"
#include <string.h>

int	main(void)
{
	int		fd;
	int		status;
	char	*ptr;
	int		line_count;
	static int	is_EOF;

	is_EOF = 1;
	fd = open("./test_files/test2.txt", O_RDONLY);
	printf("Fd = %d\nbuff_size = %d\n", fd, BUFFER_SIZE);
	line_count = 0;
	int i = 0;
//	while ((ptr = get_next_line(fd)) && i < 20)
	while ((ptr = get_next_line(fd)))
	{
		printf("Line ==> %s\n", ptr);
		//printf("line_count == %d\nptr ==> '%s'\n", line_count++, ptr);
		free (ptr);
//		i++;
	}
	status = close(fd);
	return (status);
}
