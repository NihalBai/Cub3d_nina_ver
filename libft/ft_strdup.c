/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaidaou <nbaidaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:29:17 by nbaidaou          #+#    #+#             */
/*   Updated: 2024/10/29 21:22:17 by nbaidaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*c;
	int		i;
	int		j;

	i = 0;
	while (s[i] != '\0')
		i++;
	c = (char *)malloc((i + 1) * sizeof(char));
	if (c == NULL)
		return (NULL);
	j = 0;
	while (s[j] != '\0')
	{
		c[j] = s[j];
		j++;
	}
	c[j] = '\0';
	return (c);
}
