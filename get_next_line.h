#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <fcntl.h>
# define BUFF_SIZE 128
# define OVER -42
# define CONTINUE -4242
# define LFD content_size
# define LBF content

int		get_next_line(int const fd, char **line);

#endif
