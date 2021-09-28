/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyahoui- <iyahoui-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:06:59 by iyahoui-          #+#    #+#             */
/*   Updated: 2021/09/28 16:38:41 by iyahoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

//Reads the static char *remain
static long	get_line_len(char **remain, int fd)
{
	long	read_status;
	char	*read_buf;

	while (!(*remain) || !strlen_c(*remain, '\n'))
	{
		read_buf = malloc(BUFFER_SIZE + 1);
		read_status = read(fd, read_buf, BUFFER_SIZE);
		if (read_status <= 0)
		{
			free (read_buf);
			return (read_status);
		}
		else if (read_status < BUFFER_SIZE)
			read_buf[read_status] = 0;
		else
			read_buf[BUFFER_SIZE] = 0;
		*remain = ft_strjoin_free(*remain, read_buf);
		free(read_buf);
	}
	return (strlen_c(*remain, '\n'));
}

//https://wilsonmar.github.io/maximum-limits/
//Max number of file descriptors on MacOS is 12288
char	*get_next_line(int fd)
{
	char		*current_line;
	long		line_len;
	static char	*remain[12288];

	line_len = get_line_len(&(remain[fd]), fd);
	if (line_len <= 0)
		line_len = strlen_c(remain[fd], 0);
	if (!line_len)
	{
		free (remain[fd]);
		return (NULL);
	}
	current_line = malloc(line_len + 1);
	ft_strncpy(current_line, remain[fd], line_len);
	ft_strncpy(remain[fd], &remain[fd][line_len], \
		strlen_c(remain[fd], 0) - line_len + 1);
	return (current_line);
}
