/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:55:35 by mamaquig          #+#    #+#             */
/*   Updated: 2019/11/25 18:14:39 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!len || !s || start >= ft_strlen(s))
		return (ft_strdup(""));
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_memcpy(str, s + start, len);
	str[len] = '\0';
	return (str);
}

int		get_next_line(int fd, char **line)
{
	char		*test;
	char		*tmp;
	static char *str = NULL;
	int			nb;

	if (!str)
		str = ft_strdup("");
	//test = *str;
	tmp = calloc(sizeof(char), BUFFER_SIZE);
	if (fd < 1)
		return (-1);
	while (!(ft_strchr(str, '\n')) && (nb = read(fd, tmp, BUFFER_SIZE)) > 0)
	{
		tmp[nb] = '\0';
		str = ft_strjoin(str, tmp);
	}
	free(tmp);
	if (!(test = ft_strchr(str, '\n')))
	{
		test = ft_strchr(str, '\0');
		nb = 0;
	}
	else
		nb = 1;
	if (!(*line = ft_substr(str, 0, ft_strlen(str) - ft_strlen(test))))
		return (-1);
	str = ft_substr(test + 1, 0, ft_strlen(test + 1));
	printf("line = %s\n", *line);
	return (nb);
}
