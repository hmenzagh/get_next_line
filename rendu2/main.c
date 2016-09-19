#include "get_next_line.h"

int		main(void)
{
	char *line;
	int fd;
	line = NULL;

	fd = open("test.lol", O_RDONLY);
	while(get_next_line(fd, &line))
	{
		ft_putstr(line);
		ft_putchar('\n');
	}
	return (0);
}
