#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
#endif

char	*get_next_line (int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin();
char	*ft_strchr();
size_t	*ft_strlen();
void	*ft_memcpy(void *dest, const void *src, size_t n)

#endif