/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:55:58 by mamaquig          #+#    #+#             */
/*   Updated: 2019/11/25 16:25:33 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t           ft_strnlen(const char *s, size_t maxlen)
{
        const char *str;

        str = s;
        while (*str && maxlen != 0)
        {
                str++;
                maxlen--;
        }
        return (str - s);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == '\0' && c == '\0')
		return ((char *)s);
	return (0);
}

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t i;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i < n && (dst || src))
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return ((char *)dst);
}

size_t		ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t srcsize;
	size_t len;

	if (!dst || !src)
		return (0);
	srcsize = ft_strlen(src);
	if (dstsize == 0)
		len = 0;
	else if (srcsize >= dstsize)
		len = dstsize - 1;
	else
		len = srcsize;
	if (dstsize != 0)
	{
		ft_memcpy(dst, src, len);
		dst[len] = '\0';
	}
	return (srcsize);
}

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t srclen;
	size_t dstlen;

	dstlen = ft_strnlen(dst, dstsize);
	srclen = ft_strlen(src);
	if (dstlen == dstsize)
		return (dstsize + srclen);
	if (srclen < dstsize - dstlen)
		ft_memcpy(dst + dstlen, src, srclen + 1);
	else
	{
		ft_memcpy(dst + dstlen, src, (dstsize - dstlen) - 1);
		dst[dstsize - 1] = '\0';
	}
	return (dstlen + srclen);
}
