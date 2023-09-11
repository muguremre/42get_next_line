/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memre <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 04:51:44 by memre             #+#    #+#             */
/*   Updated: 2023/09/11 04:51:44 by memre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_fetch_line(char *all_line)
{
	int		i;
	char	*str;

	i = 0;
	if (!all_line[i])
		return (NULL);
	while (all_line[i] && all_line[i] != '\n')
		i++;
	i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (all_line[i] && all_line[i] != '\n')
	{
		str[i] = all_line[i];
		i++;
	}
	if (all_line[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*read_line(int fd, char *all_line)
{
	char	*buff;
	int		reader;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	reader = 1;
	while (!ft_strchr(all_line, '\n') && reader != 0)
	{
		reader = read(fd, buff, BUFFER_SIZE);
		if (reader == -1)
		{
			free(buff);
			buff = NULL;
			free(all_line);
			return (NULL);
		}
		buff[reader] = '\0';
		all_line = join_line(all_line, buff);
	}
	free(buff);
	return (all_line);
}

char	*new_all_line(char *all_line)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (all_line[i] && all_line[i] != '\n')
		i++;
	if (!all_line[i])
	{
		free(all_line);
		return (NULL);
	}
	if (all_line[i] == '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (ft_strlen(all_line) - i + 1));
	if (!str)
		return (NULL);
	j = 0;
	while (all_line[i])
		str[j++] = all_line[i++];
	str[j] = '\0';
	free(all_line);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*all_line[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	all_line[fd] = read_line(fd, all_line[fd]);
	if (!all_line[fd])
		return (NULL);
	line = ft_fetch_line(all_line[fd]);
	all_line[fd] = new_all_line(all_line[fd]);
	return (line);
}
