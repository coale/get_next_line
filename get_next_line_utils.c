/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:28:56 by aconta            #+#    #+#             */
/*   Updated: 2022/12/10 09:40:27 by aconta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	c;

	i = 0;
	c = 0;
	while (dst[i] != '\0' && i < size)
		i += 1;
	while (src[c] != '\0' && (i + c) + 1 < size)
	{
		dst[i + c] = src[c];
		c++;
	}
	if (i < size)
		dst[i + c] = 0;
	return (ft_strlen(src) + i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	char	*p1;
	char	*p2;
	int		i;

	p1 = (char *)s1;
	p2 = (char *)s2;
	newstr = malloc(sizeof (char) * (ft_strlen(p1) + ft_strlen(p2) + 1));
	if (!newstr)
		return (0);
	i = 0;
	while (p1[i] != '\0')
	{
		newstr[i] = p1[i];
		i++;
	}
	newstr[i] = '\0';
	ft_strlcat(newstr, p2, (ft_strlen(p1) + ft_strlen(p2) + 1));
	return (newstr);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*substr;

	i = 0;
	if (start >= ft_strlen(s))
		j = 0;
	else if (ft_strlen(s) - start < len)
		j = ft_strlen(s) - start;
	else
		j = len;
	substr = (char *) malloc(sizeof(char) * (j + 1));
	if (!substr)
		return (NULL);
	while (i < j)
	{
		substr[i] = s[start];
		i++;
		start++;
	}
	substr[i] = '\0';
	return (substr);
}

int	find_index(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	if (s[i] == c)
		return (i);
	return (-1);
}
