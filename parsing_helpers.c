/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaidaou <nbaidaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:01:37 by nbaidaou          #+#    #+#             */
/*   Updated: 2025/10/24 11:53:49 by nbaidaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	safe_malloc(void **ptr, size_t size)
{
	*ptr = malloc(size);
	return (*ptr != NULL);
}

int	check_and_free(char *str)
{
	if (!str)
		return (0);
	free(str);
	return (1);
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	parse_color(char *str)
{
	char	**colors;
	int		r;
	int		g;
	int		b;

	colors = ft_split(str, ',');
	if (!colors)
		return (-1);
	r = ft_atoi(colors[0]);
	g = ft_atoi(colors[1]);
	b = ft_atoi(colors[2]);
	free_split(colors);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (0);
	return ((r << 16) | (g << 8) | b);
}

int	is_map_line(char *line)
{
	while (*line)
	{
		if (*line != ' ' && *line != '1' && *line != '0' && *line != 'N'
			&& *line != 'S' && *line != 'E' && *line != 'W' && *line != '\n'
			&& *line != '\t')
			return (0);
		line++;
	}
	return (1);
}
