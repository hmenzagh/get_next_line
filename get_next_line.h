#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <fcntl.h>
# define BUFF_SIZE 20
# define PRE_INC_SET -1
# define ERROR -1
# define OVER -42

typedef struct		s_bag
{
	int		fd;
	int		read_return;
	char	buff[BUFF_SIZE + 1];
}					t_bag;

int					get_next_line(int const fd, char **line);

#endif
