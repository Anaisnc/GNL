#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
/*
int	main()
{
int		fd;
char	*line;
int		i = 1;

if (argc < 2)
{
	printf("Usage: %s <file1> [file2 ...]\\n", argv[0]);
	return (1);
}
while (i < argc)
{
	printf(" Testing file: %s\\n", argv[i]);
	fd = open(argv[i], O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		i++;
		continue ;
	}
	while ((line = get_next_line(fd)))
	{
		printf("  %s", line);
		free(line);
	}
	close(fd);
	printf("\\n End of file: %s\\n\\n", argv[i]);
	i++;
}
return (0);
}*/

// int main(int ac, char **av)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("text.txt", O_RDONLY);
// 	if (ac == 2)
// 	{
// 		if (av[1][0] == '1')
// 		{
// 			printf("%s", get_next_line(fd));
// 			return (0);
// 		}
// 		if (av[1][0] == '2')
// 		{
// 			while (get_next_line(fd))
// 			{
// 				line = get_next_line(fd);
// 				printf("%s", line);
// 			}
// 			return (0);
// 		}
// 	}
// 	return (0);
// }

int	main(void)
{
	int fd = 0;
	char *line;
	fd = open("text.txt", O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		printf("  %s", line);
		free(line);
	}
	close(fd);
}