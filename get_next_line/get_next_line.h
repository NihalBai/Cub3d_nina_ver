/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaidaou <nbaidaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:24:39 by nbaidaou          #+#    #+#             */
/*   Updated: 2025/09/06 11:52:57 by nbaidaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

char	*get_next_line(int fd);
char	*ft_strjoin1(char *s1, char *s2);
size_t	ft_strlcpy1(char *dst, const char *src, size_t n);
char	*ft_strndup1(const char *s, size_t l);
int		find_newline(char *s);
size_t	ft_strlen1(const char *s);

#endif // GET_NEXT_LINE_H