#include "get_next_line.h"

char	*get_next_line (int fd)
{
	char	*buff;
	static char	*tmp;
	char	*save_tmp;
	char	*line;
	
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	while ()
	{
		buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		//remplir avec les 5 caracteres
		tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		ft_memcpy(tmp, buff, buff_len);
	}
	return (line);
}