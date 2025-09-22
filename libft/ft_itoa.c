/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaidaou <nbaidaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:37:55 by nbaidaou          #+#    #+#             */
/*   Updated: 2024/10/29 18:31:34 by nbaidaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count(int n)
{
	size_t	c;

	c = 0;
	if (n <= 0)
	{
		c = 1;
		n = -n;
	}
	while (n != 0)
	{
		n = n / 10;
		c++;
	}
	return (c);
}

char	*ft_itoa(int n)
{
	char	*r;
	size_t	c;
	long	nb;

	nb = n;
	c = count(nb);
	r = malloc(c + 1);
	if (!r)
		return (NULL);
	r[c] = '\0';
	if (nb < 0)
	{
		r[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		r[0] = '0';
	while (nb > 0)
	{
		r[--c] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (r);
}
