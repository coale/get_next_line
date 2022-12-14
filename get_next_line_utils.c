/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:28:56 by aconta            #+#    #+#             */
/*   Updated: 2022/12/14 08:35:00 by aconta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t  ft_strlen(const char *str)
{
        size_t  i;

        i = 0;
        while (str[i] != '\0')
        {
                i++;
        }
        return (i);
}

size_t  ft_strlcpy(char *dst, const char *src, size_t size)
{
        size_t  i;
        size_t  l;

        i = 0;
        l = ft_strlen(src);
        if (size != 0)
        {
                while (i < (size - 1) && src[i] != '\0')
                {
                        dst[i] = src[i];
                        i++;
                }
                dst[i] = '\0';
        }
        return (l);
}

size_t  ft_strlcat(char *dst, const char *src, size_t size)
{
        size_t  i;
        size_t  c;

        i = 0;
        c = 0;
        while (dst[i] != '\0' && i < size)
        {
                i += 1;
        }
        while (src[c] != '\0' && (i + c) + 1 < size)
        {
                dst[i + c] = src[c];
                c++;
        }
        if (i < size)
                dst[i + c] = 0;
        return (ft_strlen(src) + i);
}

char    *ft_strjoin(char *str, char *buff)
{
        size_t  i;
        size_t  j;
        char    *new_str;

        i = 1;
        if (!str)
        {
                str = (char *)malloc(1 * sizeof(*str));
                str[0] = '\0';
        }
        j = ft_strlen(str) + ft_strlen(buff);
        if (!str || !buff)
                return (NULL);
        new_str = malloc((j + 1) * sizeof(*new_str));
        if (new_str == NULL)
                return (NULL);
        if (str)
                while (*str != '\0' && i++)
                        *(new_str++) = *(str++);
        while (*buff != '\0')
                *(new_str++) = *(buff++);
        *new_str = '\0';
        str -= (i - 1);
        free(str);
        return (new_str - j);
}

char    *ft_strchr(const char *s, int c)
{
        if (!s)
                return (0);
        while (*s != (char)c)
        {
                if (*s == '\0')
                {
                        return (NULL);
                }
                s++;
        }
        return ((char *)s);
}
