/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaidaou <nbaidaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:14:55 by nbaidaou          #+#    #+#             */
/*   Updated: 2025/09/06 11:44:59 by nbaidaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_buffers(int fd, char *temp)
{
	int		c;
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	c = 0;
	while (1)
	{
		c = read(fd, buf, BUFFER_SIZE);
		if (c <= 0)
			break ;
		buf[c] = '\0';
		temp = ft_strjoin1(temp, buf);
		if (!temp)
			return (free(buf), NULL);
		if (find_newline(temp) >= 0)
			break ;
	}
	free(buf);
	if ((c <= 0) && (!temp || *temp == '\0'))
		return (free(temp), NULL);
	return (temp);
}

char	*line(char **temp)
{
	char	*lin;
	char	*t;
	int		nl;

	if (!*temp || !**temp)
		return (NULL);
	nl = find_newline(*temp);
	if (nl >= 0 && (*temp)[nl + 1] != '\0')
	{
		lin = ft_strndup1(*temp, nl + 1);
		t = ft_strndup1(*temp + nl + 1, ft_strlen1(*temp) - (nl + 1));
		free(*temp);
		*temp = t;
	}
	else
	{
		lin = ft_strndup1(*temp, ft_strlen1(*temp));
		free(*temp);
		*temp = NULL;
	}
	return (lin);
}

char	*get_next_line(int fd)
{
	char		*r;
	static char	*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = read_buffers(fd, temp);
	if (!temp)
		return (NULL);
	r = line(&temp);
	return (r);
}

// int main() {
//     int fd = open("test2.txt", O_RDONLY);
//     if (fd < 0) {
//         perror("Error opening file");
//         return (1);
//     }

//     char *line;
//    while ( line = get_next_line(fd))
//    {
//         printf("%s", line);
//         free(line);
//    }
//     //free(line);
//     close(fd);
//     return (0);
// }

// int main() {
//     int fd = open("test2.txt", O_RDONLY);
//     // if (fd < 0) {
//     //     perror("Error opening file");
//     //     return (1);
//     // }

//     char *line;
//     //int i = 0;
//   if((line = get_next_line(fd)) > 0) {
//          printf("%s", line);
// 		free(line);
//     //     // i++;
//     }
//     close(fd);

//     return (0);
// }