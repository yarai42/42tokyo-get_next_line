/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarai </var/mail/yarai>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 20:56:21 by yarai             #+#    #+#             */
/*   Updated: 2022/08/21 22:42:35 by yarai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char		*get_next_line(int	fd);
static char	*read_line(int	fd, char	**save, ssize_t	flag);
static char *next_line(char	**save);
static char	*all_free(char	**all);

static char	*all_free(char	**all)
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
	size_t	j;

	if (!save || !*save)
		return (all_free(save));
	i = 0;
	while ((*save)[i] && (*save)[i] != '\n')
		i++;
	j = 0;
	while ((*save)[i + j])
		j++;
	next_line = (char *)malloc(sizeof(char) * (i + 1));
	if (next_line == NULL)
		return (NULL);
	if (!(*save)[i])
	{
		next_line = ft_strldup(*save, i);
		tmp = NULL;
	}
	else
	{
		next_line = ft_strldup(*save, i + 1);
		tmp = ft_strldup(&(*save)[i + 1], j - 1);
	}
	printf("save : %s, next_line : %s, tmp : %s\n", *save, next_line, tmp);
	printf("save : %p\n next_line : %p tmp : %p\n", *save, next_line, tmp);
	free(*save);
	*save = tmp;
	if (!*next_line)
		return (all_free(&next_line));
	return (next_line);
}

static char	*read_line(int	fd, char	**save, ssize_t	flag)
{
	char	*buf;
	char	*tmpjoin;

	buf = (char *)malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	while (!ft_strchr(*save, '\n') && flag != 0)
	{
		flag = read(fd, buf, BUFFER_SIZE);
		if (flag == -1)
			return (all_free(&buf));
		buf[flag] = '\0';
		tmpjoin = ft_strjoin(*save, buf);
		free(*save);
		*save = tmpjoin;
	}
	free(buf);
	return (next_line(save));
}

char	*get_next_line(int	fd)
{
	static char	*save;
	ssize_t		flag;

	printf("----- get_next_line start -----\n");
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > SSIZE_MAX)
		return (NULL);
	flag = 1;
	return (read_line(fd, &save, flag));
}
