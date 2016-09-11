#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# define BUFFER_SIZE	100
# define INT_ERROR		-1
# define NO_EOL			-1
# define REOF			-2

typedef struct			s_gnl_data
{
	int					fd;
	char				buff[BUFFER_SIZE];
	int					len_buff;
	int					len_line;
}						t_gnl_data;

int						get_next_line(int fd, char **line);

#endif
