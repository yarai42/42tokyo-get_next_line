/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarai </var/mail/yarai>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 20:56:57 by yarai             #+#    #+#             */
/*   Updated: 2022/08/22 01:34:25 by yarai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "get_next_line.h"
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# define SSIZE_MAX 2147483647
# define BUFFER_SIZE 100
char	*get_next_line(int	fd);
char	*ft_strjoin(char const	*s1, char const	*s2);
char	*ft_strldup(const char	*s1, size_t	l);
char	*ft_strchr(const char	*s, int c);
size_t	ft_strlen(char const	*s);

#endif
