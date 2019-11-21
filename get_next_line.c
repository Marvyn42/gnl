/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:55:35 by mamaquig          #+#    #+#             */
/*   Updated: 2019/11/21 03:47:32 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_strdup(const char *s1)
{
	int		s;
	char	*dest;

	s = ft_strlen(s1);
	if (!(dest = malloc(sizeof(char) * s + 1)))
		return (NULL);
	dest = ft_memcpy(dest, s1, s);
	dest[s] = '\0';
	return (dest);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((char *)s)[i] == c)
			return (((void *)s) + i);
		i++;
	}
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!len || !s || start >= ft_strlen(s))
		return (ft_strdup(""));
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	(void)ft_strlcpy(str, s + start, len + 1);
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	tot;

	if (!s1 || !s2)
		return (NULL);
	tot = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(dst = malloc(sizeof(char) * tot)))
		return (NULL);
	dst = ft_memcpy(dst, s1, ft_strlen(s1) + 1);
	(void)ft_strlcat(dst, s2, tot);
	return (dst);
}

int				get_next_line(int fd, char **line)
{
	char 		*test;
	char		*tmp;
	static char *str;
	int			nb;

	str = calloc(sizeof(char), BUFFER_SIZE);
	tmp = calloc(sizeof(char), BUFFER_SIZE);
	nb = 1;
	if (fd < 1)
		return (-1);
	while (!(ft_strchr(tmp, '\n')))
	{
		read(fd, tmp, BUFFER_SIZE);
		printf("tmp = %s\n", tmp);
		str = ft_strjoin(str, tmp);
		printf("str = %s\n\n", str);
	}
		test = ft_strchr(str, '\n');
	if (test == NULL)
	{
		test = ft_strchr(str, '\0');
		nb = 0;
	}
	if (!(*line = ft_substr(str, 0, ft_strlen(str) - ft_strlen(test))))
		return (-1);
	printf("line = %s\n", *line);
	return (printf("%d\n", nb));
}
