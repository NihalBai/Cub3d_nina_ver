/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_norm_helpers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaidaou <nbaidaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 11:37:31 by nbaidaou          #+#    #+#             */
/*   Updated: 2025/10/24 11:38:15 by nbaidaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	*pad_line(char *line, int width)
{
	int		len;
	char	*padded;

	len = ft_strlen(line);
	padded = malloc(width + 1);
	if (!padded)
		return (NULL);
	ft_memcpy(padded, line, len);
	ft_memset(padded + len, '1', width - len);
	padded[width] = '\0';
	return (padded);
}

int	pad_existing_rows(char **grid, int height, int new_width)
{
	int		i;
	char	*p;

	i = 0;
	while (i < height)
	{
		if ((int)ft_strlen(grid[i]) < new_width)
		{
			p = pad_line(grid[i], new_width);
			if (!p)
				return (0);
			free(grid[i]);
			grid[i] = p;
		}
		i++;
	}
	return (1);
}

int	copy_old_grid(char **new_grid, char **old_grid, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		new_grid[i] = old_grid[i];
		i++;
	}
	return (1);
}

char	*trim_and_pad_new_line(char *line, int width)
{
	char	*trimmed;
	char	*padded;
	int		len;

	trimmed = ft_strtrim(line, "\n");
	if (!trimmed)
		return (NULL);
	len = ft_strlen(trimmed);
	if (len < width)
	{
		padded = pad_line(trimmed, width);
		free(trimmed);
		if (!padded)
			return (NULL);
		return (padded);
	}
	return (trimmed);
}

int	ft_max(int i, int j)
{
	if (i > j)
		return (i);
	return (j);
}
