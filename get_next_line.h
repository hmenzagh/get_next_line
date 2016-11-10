#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <fcntl.h>
# define BUFF_SIZE 20
# define MAX_FD 3
# define IFD 0
# define PRE_INC_SET -1
# define RR 1
# define LID 2

typedef struct		s_bag
{
	int		t[MAX_FD][3];
	char	buff[MAX_FD][BUFF_SIZE + 1];
}					t_bag;

int					get_next_line(int const fd, char **line);

#endif
