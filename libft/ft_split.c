/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaidaou <nbaidaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:20:44 by nbaidaou          #+#    #+#             */
/*   Updated: 2024/10/29 21:20:52 by nbaidaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_words(const char *str, char delimiter)
{
	size_t	word_count;
	size_t	i;

	i = 0;
	word_count = 0;
	while (str[i])
	{
		if (str[i] != delimiter)
		{
			word_count++;
			while (str[i] && str[i] != delimiter)
				i++;
		}
		else
			i++;
	}
	return (word_count);
}

char	*create_word(const char *str, size_t start, size_t end)
{
	size_t	word_length;
	size_t	j;
	char	*new_word;

	word_length = end - start;
	j = 0;
	new_word = (char *)malloc(word_length + 1);
	if (new_word == NULL)
		return (NULL);
	while (j < word_length)
	{
		new_word[j] = str[start + j];
		j++;
	}
	new_word[word_length] = '\0';
	return (new_word);
}

void	free_memory(char **array)
{
	size_t	k;

	k = 0;
	while (array[k])
	{
		free(array[k]);
		k++;
	}
	free(array);
}

char	**populate_and_free(char **array, const char *str, \
		char delimiter, size_t wc)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (str[i] && j < wc)
	{
		if (str[i] != delimiter)
		{
			start = i;
			while (str[i] && str[i] != delimiter)
				i++;
			array[j] = create_word(str, start, i);
			if (array[j] == NULL)
			{
				free_memory(array);
				return (NULL);
			}
			j++;
		}
		else
			i++;
	}
	return (array[j] = NULL, array);
}

char	**ft_split(char const *str, char delimiter)
{
	size_t	word_count;
	char	**array;

	if (str == NULL)
		return (NULL);
	word_count = count_words(str, delimiter);
	array = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (array == NULL)
		return (NULL);
	if (populate_and_free(array, str, delimiter, word_count) == NULL)
		return (NULL);
	return (array);
}
