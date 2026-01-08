/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourt <ancourt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:45:48 by ancourt           #+#    #+#             */
/*   Updated: 2026/01/08 15:57:10 by ancourt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
#endif

char	*ft_newline(char *s)
{
	int	c;
	int	i;
	
	c = '\n';
	i = 0;
	while (s[i] != (unsigned char)c)
		i++;
		return (&s[i - i]);
	while (s[i] != (unsigned char)c)
		i++;
	if ((unsigned char)c == s[i])
		return (&s[i + 1]);
	if ((unsigned char)c == '\0')
		return (&s[i]);
	else
		return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	dup = malloc(sizeof(char) * (i + 1));
	if (!dup)
		return (0);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int	main(void)
{
	char	buf[BUFFER_SIZE + 1];
	int	fd;
	int	nb_read;
	int	count;

	fd = open("/home/ancourt/Documents/Projects/GNL/text.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	nb_read = -1;
	count = 0;
	while (nb_read != 0)
	{
		nb_read = read(fd, buf, BUFFER_SIZE);
		if (nb_read == -1)
			return (1);
		buf[nb_read] = '\0';
		printf("%s", buf);
		count++;
	}
	close(fd);
	return (0);
}
