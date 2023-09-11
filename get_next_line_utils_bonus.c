/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memre <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 04:53:12 by memre             #+#    #+#             */
/*   Updated: 2023/09/11 04:53:12 by memre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (c == '\0')
		return ((char *)&str[ft_strlen(str)]);
	while (str[i] != '\0')
	{
		if (str[i] == (char) c)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

char	*join_line(char *all_line, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (all_line == NULL)
	{
		all_line = (char *)malloc(1 * sizeof(char));
		all_line[0] = '\0';
	}
	if (all_line == NULL || buff == NULL)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(all_line) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (all_line)
		while (all_line[++i] != '\0')
			str[i] = all_line[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(all_line) + ft_strlen(buff)] = '\0';
	free(all_line);
	return (str);
}
