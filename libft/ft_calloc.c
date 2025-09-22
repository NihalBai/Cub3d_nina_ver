/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaidaou <nbaidaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:38:15 by nbaidaou          #+#    #+#             */
/*   Updated: 2024/10/29 11:46:16 by nbaidaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*s;
	size_t	t;

	t = count * size;
	if (count && (t / count != size))
		return (NULL);
	s = malloc(t);
	if (!s)
		return (NULL);
	ft_bzero(s, t);
	return (s);
}
