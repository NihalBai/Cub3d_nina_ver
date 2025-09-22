/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaidaou <nbaidaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:12:03 by nbaidaou          #+#    #+#             */
/*   Updated: 2024/10/30 09:51:29 by nbaidaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	handle_overflow(int sign)
{
	if (sign == 1)
		return (-1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	r;
	long	n;

	i = 0;
	sign = 1;
	r = 0;
	n = 0;
	while (str[i] == ' ' || str[i] == '\t'
		|| str[i] == '\r' || str[i] == '\v'
		|| str[i] == '\n' || str[i] == '\f')
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		r = n * 10 + (str[i++] - '0');
		if (r < n)
			return (handle_overflow(sign));
		n = r;
	}
	return (r * sign);
}
