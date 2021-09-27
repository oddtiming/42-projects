#include "get_next_line.h"

/*
static char	*ft_substr(char const *s, size_t len)
{
	size_t	s_len;
	char	*substr;

	s_len = 0;
	if (!s)
		return (NULL);
	substr = malloc(len + 1);
	if (!substr)
		return (NULL);
	substr[len] = 0;
	while (len--)
		substr[len] = s[len];
	return (substr);
}
*/

//This will give the amount of characters until a new line is hit. 0 if there is no new line
static size_t	get_line_len(char *buffer)
{
	size_t	line_len;

	line_len = 1;
	if (!buffer)
		return (0);
	while (*buffer != '\n' && *buffer)
	{
		line_len++;
		buffer++;
	}
	if (*buffer != '\n')
		return (0);
	return (line_len);
}
/*
static size_t strlen_n(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\n' && s[i])
	{
		i++;
	}
	if (s[i] == '\n')
		i++;
	return (i);
}
*/
char	*get_next_line(int fd)
{
	char		*current_line;
	size_t		line_len;
	int			read_status;
	//Declare + init works, but not sure if legal.
	static char	*remainder = NULL;
	char		*temp_ptr;

	//To delete:
	static int	iteration = 0;

	line_len = get_line_len(remainder);
	if (line_len == 0)
	{
		temp_ptr = malloc(BUFFER_SIZE + 1);
		read_status = read(fd, temp_ptr, BUFFER_SIZE);
		temp_ptr[BUFFER_SIZE] = 0;
		current_line = remainder;
		remainder = malloc (BUFFER_SIZE + 1);
		remainder = strcat(remainder, temp_ptr);
		line_len = get_line_len(remainder);
		free (current_line);
	}
	printf("For iteration #%d\nLine_len = %lu\n", iteration++, line_len);
	printf("Remainder [End of IF statement GNL]= '%s'\n", remainder);
	current_line = malloc(line_len + 1);
	strncpy(current_line, remainder, line_len);
	temp_ptr = remainder;
	remainder = malloc(BUFFER_SIZE - line_len + 1);
	printf("Current_line [END of GNL]= '%s'\n", remainder);
	strncpy(remainder, temp_ptr + line_len, BUFFER_SIZE - line_len);
	printf("Remainder [After strncpy]= '%s'\n", remainder);
	free (temp_ptr);
	return (current_line);
}


/*
char	*get_next_line(int fd)
{
	//static char	*remainder;
	int			status;
	char		*read_buf;
	char		*current_line;
	size_t		line_len;

	//printf("[GNL] before read\n");
	read_buf = malloc(BUFFER_SIZE + 2);
	status = read (fd, read_buf, BUFFER_SIZE);
	line_len = get_line_len(read_buf);
	current_line = malloc(line_len + 2);
	strncpy(current_line, read_buf, line_len + 1);
	//printf("[GNL] after read\n");
	//printf("read_buf = '%s'\n", read_buf);
	
	int i = 0;
	while (read_buf[i] != '\n' && read_buf[i])
	{
		i++;
		line_len++;
	}
	//printf("[GNL] line_len = %lu\n", line_len);
	buf = malloc(line_len + 2);
	status = read(fd, buf, line_len + 1);
	if (status == 0)
		return (NULL);
	buf[line_len + 1] = 0;
	//printf("buf = '%s'\n", buf);
	
	return (current_line);
}
*/

/*	Could I use read once to set the first character presented as the fd, then use its pointer to sequentially
**	scan the addresses to find either \n or EOF? What if there is a NULL char in the text file ? How about ctrl-D on unix systems?
**	Therefore, could I modify the BUFFER_SIZE according to whichever is larger between it and line_len ?
*/
//NOTE: I should protect my fct from BUFFER_SIZE == 0;

