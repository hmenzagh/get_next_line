#include	"get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int			main(int ac, char **av)
{
	char *line;
	line = NULL;
	int fd = open("test.lol", O_RDONLY);
	get_next_line(fd, &line);
	ft_putstr(line);
	ft_putchar('\n');
	get_next_line(fd, &line);
	ft_putstr(line);
	ft_putchar('\n');
	get_next_line(fd, &line);
	ft_putstr(line);
	ft_putchar('\n');
	get_next_line(fd, &line);
	ft_putstr(line);
	ft_putchar('\n');
	get_next_line(fd, &line);
	ft_putstr(line);
	ft_putchar('\n');	
	get_next_line(fd, &line);
	ft_putstr(line);
	ft_putchar('\n');	
	get_next_line(fd, &line);
	ft_putstr(line);
	ft_putchar('\n');
	get_next_line(fd, &line);
	ft_putstr(line);
	ft_putchar('\n');
	free(line);
	return (0);
}