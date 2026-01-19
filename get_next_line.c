/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourt <ancourt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 19:35:52 by ancourt           #+#    #+#             */
/*   Updated: 2026/01/19 19:53:45 by ancourt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extract_line(char **stash)
{
	char	*nl;
	char	*line;
	char	*new_stash;
	size_t	len;

	nl = ft_strchr(*stash, SEPARATOR);
	len = (size_t)(nl - *stash + 1);
	line = (char *)malloc(len + 1);
	if (!line)
	{
		free(*stash);
		*stash = NULL;
		return (NULL);
	}
	line[len] = '\0';
	while (len--)
		line[len] = (*stash)[len];
	new_stash = ft_strdup(nl + 1);
	free(*stash);
	*stash = new_stash;
	if (!*stash)
		return (free(line), NULL);
	return (line);
}

static char	*read_fusion(int fd, char *stash)
{
	char	*buff;
	char	*tmp;
	ssize_t	r;

	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (free(stash), NULL);
	r = 1;
	while (r > 0 && !ft_strchr(stash, SEPARATOR))
	{
		r = read(fd, buff, BUFFER_SIZE);
		if (r <= 0)
			break ;
		buff[r] = '\0';
		tmp = ft_strjoin(stash, buff);
		free(stash);
		stash = tmp;
		if (!stash)
			break ;
	}
	free(buff);
	if (r < 0 || !stash)
		return (free(stash), NULL);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_fusion(fd, stash);
	if (!stash || !*stash)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	if (ft_strchr(stash, SEPARATOR))
		return (extract_line(&stash));
	line = ft_strdup(stash);
	free(stash);
	stash = NULL;
	return (line);
}
