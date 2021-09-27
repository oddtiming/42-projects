#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buf;
	int		status;
	char	read_ptr[BUFFER_SIZE];
	size_t	line_len;

	line_len = 0;
	//printf("[GNL] before read\n");
	read(fd, read_ptr, 1);
	//printf("[GNL] after read\n");
	//printf("read_ptr = '%s'\n", read_ptr);
	int i = 0;
	while (read_ptr[i] != '\n' && read_ptr[i])
	{
		i++;
		line_len++;
	}
	printf("[GNL] line_len = %lu\n", line_len);
	buf = malloc(line_len + 2);
	status = read(fd, buf, line_len + 1);
	if (status == 0)
		return (NULL);
	buf[line_len + 1] = 0;
	printf("buf = '%s'\n", buf);
	return (buf);
}


/*	Could I use read once to set the first character presented as the fd, then use its pointer to sequentially
**	scan the addresses to find either \n or EOF? What if there is a NULL char in the text file ? How about ctrl-D on unix systems?
**	Therefore, could I modify the BUFFER_SIZE according to whichever is larger between it and line_len ?
*/
//NOTE: I should protect my fct from BUFFER_SIZE == 0;

