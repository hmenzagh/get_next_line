#include "get_next_line.h"

static	int		set_line(t_stock *db, char **line)
{
	int			len;
	int			len_line;
	int			i;
	int			over;

	i = 0;
	over = 0;
	len = (int)(ft_strchr((const char*)db->buff, '\n') - db->buff);
	len = (len < 0) ? db->read_return : len;
	len_line = (!*line) ? 0 : ft_strlen(*line);
	if(!(ft_realloc((void**)line, len_line, len + len_line + 1)))
		return (-1);
	ft_strncat(*line, (const char*)db->buff, len);
	while(i + len + 1 < db->read_return)
	{
		db->buff[i] = db->buff[i + len + 1];
		++i;
	}
	while(len != db->read_return && i < db->read_return)
		db->buff[i++] = 0;
	over = (len != db->read_return) ? 1 : 0;
	db->read_return = (len == db->read_return) ? 0 : db->read_return - len - 1;
	return (over);
}

static	int		read_line(t_stock *db, char **line)
{
	int			over;

	over = 0;
	while(!over)
	{
		if(db->read_return)
			if((over = set_line(db, line)) == -1)
				return(-1);
		if(!over && db->read_return == 0)
		{
			db->read_return = read(db->fd, db->buff, BUFFER_SIZE);
			if(db->read_return > 0)
				db->buff[db->read_return] = 0;
			else if(db->read_return == -1)
				return (-1);
			else
				return (0);
		}
	}
	return (1);
}

int						get_next_line(int fd, char **line)
{
	static t_stock		db;

	if(db.fd != fd)
		ft_bzero(&db, sizeof(t_stock));
	db.fd = fd;
	if(*line)
		ft_memdel((void**)line);
	return(read_line(&db, line));
}
