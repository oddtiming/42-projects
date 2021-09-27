/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyahoui- <iyahoui-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 13:10:14 by iyahoui-          #+#    #+#             */
/*   Updated: 2021/09/27 13:22:23 by iyahoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	strlen_n(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\n' && s[i])
	{
		i++;
	}
	if (s[i] != '\n')
		return (0);
	else
		return (i + 1);
}

static size_t	get_line_len(char **remainder, int fd)
{
	size_t	read_status;
	char	*read_buf;
	char	*temp_ptr;

	while (!(*remainder) || !strlen_n(*remainder))
	{
		read_buf = malloc(BUFFER_SIZE + 1);
		read_status = read(fd, read_buf, BUFFER_SIZE);
		if (read_status < BUFFER_SIZE)
			read_buf[read_status] = 0;
		else
			read_buf[BUFFER_SIZE] = 0;
		temp_ptr = *remainder;
		*remainder = ft_strjoin(temp_ptr, read_buf);
		free(temp_ptr);
		free(read_buf);
		if (read_status < BUFFER_SIZE)
			return (0);
	}
	return (strlen_n(*remainder));
}

char	*get_next_line(int fd)
{
	char		*current_line;
	size_t		line_len;
	static char	*remainder = NULL;
	char		*temp_ptr;

	line_len = get_line_len(&remainder, fd);
	if (!line_len)
	{
		line_len = strlen_n(remainder);
		if (!line_len)
			line_len = ft_strlen(remainder);
		if (!line_len)
		{
			free(remainder);
			return (NULL);
		}
	}
	current_line = malloc(line_len + 1);
	ft_strncpy(current_line, remainder, line_len);
	temp_ptr = remainder;
	remainder = malloc(ft_strlen(temp_ptr) - line_len + 1);
	ft_strcpy(remainder, &temp_ptr[line_len]);
	free (temp_ptr);
	return (current_line);
}

/*	Could I use read once to set the first character presented as the fd
**	, then use its pointer to sequentially scan the addresses to find 
**	either \n or EOF? What if there is a NULL char in the text file ? 
**	How about ctrl-D on unix systems?
**	Therefore, could I modify the BUFFER_SIZE according to whichever 
**	is larger between it and line_len ?
*/
//NOTE: I should protect my fct from BUFFER_SIZE == 0;
