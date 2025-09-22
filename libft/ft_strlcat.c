/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaidaou <nbaidaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:34:58 by nbaidaou          #+#    #+#             */
/*   Updated: 2024/10/29 21:29:42 by nbaidaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	ld;
	size_t	ls;
	size_t	i;
	size_t	j;

	ld = ft_strlen(dst);
	ls = ft_strlen(src);
	if (n <= ld)
		return (n + ls);
	i = ld;
	j = 0;
	while (src[j] && i < n - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (ld + ls);
}
