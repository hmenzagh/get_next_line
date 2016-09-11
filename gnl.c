#include	"get_next_line.h"

void readc(char *line, int s)
{
	int i = 0; 
	while (i < s)
		ft_putchar(line[i++]);
}

static int		check_eol(char *s, int len)
{
	int			i; 

	i = 0; 
	while(i < len)
		if(s[i++] == '\n')
			return (--i);
	return (NO_EOL);
}

static int		set_next_line(t_gnl_data *db, char **line)
{
	int			n_buff;
	int			i; 

	i = 0;
	n_buff = check_eol(db->buff, db->len_buff);
	++n_buff;
	if(n_buff != NO_EOL)
	{
		while(i + n_buff < BUFFER_SIZE)
		{
			db->buff[i] = db->buff[i + n_buff];
			i++;
		}
		while(i < BUFFER_SIZE)
		{
			db->buff[i] = '\0';
			i++;
		}
	}
	db->len_buff = db->len_buff - n_buff;
	db->len_line = db->len_buff;
	if(!(*line = ft_memalloc(db->len_buff)))
		return(INT_ERROR);
	ft_memcpy((void*)*line, db->buff, db->len_buff);
	return (0);
}

static int		read_file(t_gnl_data *db, char **line)
{
	int			n_buff; 
	db->len_line = 0;
	if(db->len_buff || (db->len_buff && check_eol(db->buff, db->len_buff) == NO_EOL))
	    set_next_line(db, line);
	while (check_eol(db->buff, db->len_buff) == NO_EOL && db->len_buff != REOF)
	{
		db->len_buff = read(db->fd, db->buff, BUFFER_SIZE);
		if(db->len_buff == INT_ERROR)
			return(INT_ERROR);
		db->len_buff = (db->len_buff == 0) ? REOF : db->len_buff;
		db->len_line += db->len_buff;
		if(db->len_line - db->len_buff == 0 && db->len_buff != REOF)
		{
			if(!(*line = ft_memalloc(db->len_buff)))
				return(INT_ERROR);
			ft_memcpy((void*)*line, db->buff, db->len_buff);
		}
		else if(db->len_buff != REOF)
			ft_memrealloccp((void**)line, db->buff, db->len_line, db->len_buff);
	}
	n_buff = check_eol(*line, db->len_line);
	if(n_buff != NO_EOL)
		ft_memreallocsub((void**)line, 0, n_buff);
	if(!(ft_realloc((void**)line, n_buff, n_buff + 1)))
		return (0);
	*line[n_buff] = '\0';
	db->len_line = n_buff + 1;
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static t_gnl_data db;

	if(*line)
		ft_memdel((void**)line);
	if(db.fd != fd)
		ft_bzero(&db, sizeof(t_gnl_data));
	db.fd = fd;
	return (read_file(&db, line));
}