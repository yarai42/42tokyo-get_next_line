/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarai </var/mail/yarai>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 20:57:29 by yarai             #+#    #+#             */
/*   Updated: 2022/08/22 01:38:49 by yarai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strjoin(char const	*s1, char const	*s2);
char		*ft_strldup(const char	*s1, size_t	l);
size_t		ft_strlen(char const	*s);
char		*ft_strchr(const char	*s, int	c);

size_t	ft_strlen(char const	*s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (*s++)
		i++;
	return (i);
}

char	*ft_strchr(const char	*s, int	c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == 0)
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strldup(const char	*s1, size_t	l)
{
	char	*ans;
	size_t	i;

	i = 0;
	ans = (char *)malloc(sizeof(char) * (l + 1));
	if (ans == NULL)
		return (NULL);
	while (i < l)
	{
		ans[i] = s1[i];
		i++;
	}
	ans[i] = '\0';
	return (ans);
}

char	*ft_strjoin(char const	*s1, char const	*s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	char	*ans;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strldup(s2, s2_len));
	else if (!s2)
		return (ft_strldup(s1, s1_len));
	i = 0;
	ans = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (ans == NULL)
		return (NULL);
	while (*s1)
		ans[i++] = *s1++;
	while (*s2)
		ans[i++] = *s2++;
	ans[i] = '\0';
	return (ans);
}
