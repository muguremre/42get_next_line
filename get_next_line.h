/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memre <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 01:46:43 by memre             #+#    #+#             */
/*   Updated: 2023/09/11 05:47:53 by memre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 31
# endif

char	*ft_strchr(char *str, int c);
char	*join_line(char *all_line, char *buff);
char	*read_line(int fd, char *all_line);
char	*new_all_line(char *all_line);
size_t	ft_strlen(char *str);
char	*ft_fetch_line(char *all_line);
char	*get_next_line(int fd);

#endif
