/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourt <ancourt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 14:22:27 by ancourt           #+#    #+#             */
/*   Updated: 2026/01/09 20:20:43 by ancourt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extract_line(char **tmp)
{
	char	*line;
	char	*new_tmp;
	char	*new_line;
	size_t	len;

	new_line = ft_strchr(*tmp, SEPARATOR);
	len = new_line - *tmp + 1;
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	line[len] = '\0';
	while (len--)
		line[len] = (*tmp)[len];
	new_tmp = ft_strdup(new_line + 1);
	if (!new_tmp)
		return (NULL);
	free(*tmp);
	*tmp = new_tmp;
	return (line);
}

static char	*read_fusion(int fd, char *tmp)
{
	char	*buff;
	char	*save_tmp;
	ssize_t	read_bytes;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	read_bytes = read(fd, buff, BUFFER_SIZE);
	while (read_bytes > 0)
	{
		buff[read_bytes] = '\0';
		save_tmp = tmp;
		tmp = ft_strjoin(save_tmp, buff);
		//secu ?
		free(save_tmp);
		if (ft_strchr(tmp, SEPARATOR))
			break ;
		read_bytes = read(fd, buff, BUFFER_SIZE);
	}
	free(buff);
	if (read_bytes < 0)
	{
		free(tmp);
		return (NULL);
	}
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*tmp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = read_fusion(fd, tmp);
	if (!tmp || !*tmp)
	{
		free(tmp);
		tmp = NULL;
		return (NULL);
	}
	if (ft_strchr(tmp, SEPARATOR))
		return (extract_line(&tmp));
	line = ft_strdup(tmp);
	free(tmp);
	tmp = NULL;
	return (line);
}
