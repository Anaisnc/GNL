/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourt <ancourt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 14:22:27 by ancourt           #+#    #+#             */
/*   Updated: 2026/01/12 15:55:59 by ancourt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

/*Rôle : découper *tmp en 2.
trouve \n : new_line = ft_strchr(*tmp, '\n')
calcule longueur à extraire : len = new_line - *tmp + 1
alloue line et copie *tmp[0..len-1] (ligne avec \n)
crée new_tmp = ft_strdup(new_line + 1) (reste après \n)
libère ancien *tmp, remplace par new_tmp
retourne line
*/
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
/*Rôle : remplir/compléter tmp en lisant le fd.
alloue buff
lit read(fd, buff, BUFFER_SIZE) en boucle tant que read_bytes > 0
termine buff avec \0
concatène : tmp = ft_strjoin(tmp, buff)
s’arrête dès que tmp contient \n
libère buff
si read_bytes < 0 : libère tmp et retourne NULL
retourne tmp
*/
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
		//secu
		free(save_tmp);
		//save_tmp = NULL = fonction free et null assignation
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
/*
static char *tmp; conserve le reste entre appels
vérifie fd et BUFFER_SIZE
tmp = read_fusion(fd, tmp)
si tmp est NULL ou vide : libère et retourne NULL
si tmp contient \n : retourne extract_line(&tmp)
sinon : duplique tmp (dernière ligne), libère tmp, met tmp = NULL, retourne la ligne*/
char	*get_next_line(int fd)
{
	static char	*tmp = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = read_fusion(fd, tmp);
	if (!tmp || !*tmp)
	{
		free(tmp);
		return (NULL);
	}
	if (ft_strchr(tmp, SEPARATOR))
		return (extract_line(&tmp));
	line = ft_strdup(tmp);
	free(tmp);
	tmp = NULL;
	return (line);
}
