#include	"get_next_line.h"

static int					check_eol(char *line, size_t len)
{
	int						i;

	i = 0;
	while(i < len)
	{
		if(line[i] == '\n')
			return (i);
		++i;
	}
	return (-1);
}

static int					buff_seter(t_gnl_data *db, char **line, int pos)
{
	int						len; 
	int						i;

	i = 0;
	len = ft_strlen(db->buff);
	if(!(*line = ft_strnew(len - pos + 1)))
		return (INT_ERROR);
	ft_strcpy(*line, ft_strsub(db->buff, pos + 1, len));
	if(ft_strchc(db->buff, '\n') == 1)
		ft_bzero(db->buff, BUFF_SIZE);
	else
		while(i + pos + 1 < len)
		{
			db->buff[i] = db->buff[i + pos + 1];
			db->buff[i + pos + 1] = '\0';
			++i;
		}
	db->r_tot = len - pos - 1;
	db->r_ret = len - pos - 1;
	return (0);
}

static int					read_line(t_gnl_data *db, char **line)
{
	if(check_eol(db->buff, db->r_ret) != -1)
		buff_seter(db, line, check_eol(db->buff, db->r_ret));
	else
		db->r_tot = 0;
	while(!*line || (check_eol(*line,  db->r_tot) == -1 && db->r_ret > 0))
	{
		db->r_ret = read(db->fd, db->buff, BUFF_SIZE);		
		if (db->r_ret == INT_ERROR)
			return (INT_ERROR);
		db->buff[BUFF_SIZE] = '\0';
		db->r_tot += db->r_ret;
		if(*line)
			if(!(ft_strrealloccp(line, db->buff, db->r_tot + 1, db->r_ret)))
				return (INT_ERROR);
		if(!*line)
		{
			if(!(*line = ft_strnew(db->r_ret + 1)))
				return (INT_ERROR);
			ft_strcpy(*line, db->buff);
		}
	}
	if(check_eol(*line, db->r_tot) != -1)
		if(!(ft_strreallocsub(line, 0, check_eol(*line,  db->r_tot))))
			return (INT_ERROR);
	return (db->r_ret > 0);
}

int						get_next_line(int fd, char **line)
{
	int i; 
	static t_gnl_data	stock;
	if(stock.fd != fd)
		ft_bzero((void*)&stock, sizeof(stock));
	stock.fd = fd;
	stock.r_ret = (stock.r_ret > 0) ? stock.r_ret : 1;
	if(*line)
		ft_memdel((void**)line);

	i = read_line(&stock, line);
	return (i);
}
