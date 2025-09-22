/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaidaou <nbaidaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:24:29 by nbaidaou          #+#    #+#             */
/*   Updated: 2025/09/06 11:52:57 by nbaidaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen1(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	find_newline(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strndup1(const char *s, size_t l)
{
	char	*c;
	size_t	j;

	c = (char *)malloc((l + 1) * sizeof(char));
	if (c == NULL)
	{
		return (NULL);
	}
	j = 0;
	while (j < l)
	{
		c[j] = s[j];
		j++;
	}
	c[l] = '\0';
	return (c);
}

size_t	ft_strlcpy1(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	src_len;

	if (!src || !dst)
		return (0);
	src_len = ft_strlen1(src);
	if (n == 0)
		return (src_len);
	i = 0;
	while (i < n - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (n > 0)
		dst[i] = '\0';
	return (src_len);
}

char	*ft_strjoin1(char *s1, char *s2)
{
	char	*r;
	size_t	l1;
	size_t	l2;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strndup1(s2, ft_strlen1(s2)));
	if (!s2)
		return (ft_strndup1(s1, ft_strlen1(s1)));
	l1 = ft_strlen1(s1);
	l2 = ft_strlen1(s2);
	r = malloc(l1 + l2 + 1);
	if (!r)
	{
		free(s1);
		return (NULL);
	}
	ft_strlcpy1(r, s1, l1 + 1);
	ft_strlcpy1(r + l1, s2, l2 + 1);
	free(s1);
	return (r);
}
