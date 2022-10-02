/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarai </var/mail/yarai>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 20:56:21 by yarai             #+#    #+#             */
/*   Updated: 2022/10/02 12:58:55 by yarai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char		*get_next_line(int fd);
static char	*read_line(int fd, char	**save);
static char	*next_line(char	**save);
static char	*return_and_free(char	**all);

static char	*return_and_free(char	**all)
{
	free(*all);
	*all = NULL;
	return (NULL);
}

static char	*next_line(char	**save)
{
	char	*next_line;
	char	*tmp;
	size_t	i;

	i = 0;
	while ((*save)[i] && (*save)[i] != '\n')
		i++;
	if ((*save)[i] == '\n')
	{
		next_line = ft_strldup(*save, i + 1);
		tmp = ft_strldup(&(*save)[i + 1], ft_strlen(&(*save)[i + 1]));
	}
	else
	{
		next_line = ft_strldup(*save, i);
		tmp = NULL;
	}
	free(*save);
	*save = tmp;
	if (next_line[0] == '\0')
		return (return_and_free(&next_line));
	return (next_line);
}

static char	*read_line(int fd, char	**save)
{
	char	*buf;
	char	*tmpjoin;
	ssize_t	flag;

	buf = (char *)malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	flag = 1;
	while (!ft_strchr(*save, '\n') && flag != 0)
	{
		flag = read(fd, buf, BUFFER_SIZE);
		if (flag == -1)
		{
			free(buf);
			return (return_and_free(save));
		}
		buf[flag] = '\0';
		tmpjoin = ft_strjoin(*save, buf);
		free(*save);
		*save = tmpjoin;
	}
	free(buf);
	if (!save || !*save)
		return (return_and_free(save));
	return (next_line(save));
}

char	*get_next_line(int fd)
{
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > SSIZE_MAX)
		return (NULL);
	return (read_line(fd, &save));
}
