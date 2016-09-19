#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "includes/libft.h"
# include <fcntl.h>
# define BUFFER_SIZE	10

typedef	struct				s_stock
{
	int			fd;
	int			read_return;
	char		buff[BUFFER_SIZE + 1];
}							t_stock;

int						get_next_line(int fd, char **line);

#endif
