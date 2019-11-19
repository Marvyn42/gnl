/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:55:35 by mamaquig          #+#    #+#             */
/*   Updated: 2019/11/19 04:55:33 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		if (((unsigned char *)src)[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}

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
	int i = 0;
	int			byte_read;
	int test;
	char	*tmp;
	char	*buff2;

	buff2 = ft_strdup("");
	test = BUFFER_SIZE;
	if (fd < 1)
		return (-1);
	read(fd, buff2, test);
	while (!(tmp = ft_strchr(buff2, '\n')) || !(tmp = ft_strchr(buff2, '\0')))
	{
		printf("tour dans la boucle: %d\n", i);
		i++;
		test += test;
		printf("test = %d\n", test);
		printf("buff2 avant read: %s\n", buff2);
		byte_read = read(fd, buff2, 100);
		printf("buff2 apres read: %s\n\n", buff2);
	}
	tmp = ft_strchr(buff2, '\n');
	/*------------------------------------------------------------------------*/
	if (*tmp == '\0')
	{
		//if (!(line = malloc(sizeof(char) * ft_strlen(buff2))))
		//	return (-1);
		//printf("malloc fait\n");
		//ft_memcpy(line, buff2, ft_strlen(buff2));
		//printf("line apres memccpy et malloc: %s\n", *line);
		printf("buff2 avant substr: %s\n", buff2);
		if (!(*line = ft_substr(buff2, 0, ft_strlen(buff2))))
			return (-1);
		printf("line apres substr: %s\n", *line);
		return (puts("0"));
	}
	else
	{
		*tmp = '\0';
		if (!(*line = ft_substr(buff2, 0, ft_strlen(buff2))))
			return (-1);
		printf("line apres substr: %s\n", *line);
		return (puts("1"));
	}
	/*------------------------------------------------------------------------*/
}
