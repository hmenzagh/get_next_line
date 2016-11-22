/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmenzagh <hmenzagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 21:16:36 by hmenzagh          #+#    #+#             */
/*   Updated: 2016/11/14 19:40:40 by hmenzagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

int				give_line(t_list *db, char **line)
{
	int			len_b;
	int			len_line;
	char		*nl_pos;
	int			status;

	status = CONTINUE;
	if ((len_b = ft_strlen(db->LBF)))
	{
		nl_pos = ft_strchr(db->LBF, '\n');
		status = (nl_pos) ? OVER : CONTINUE;
		len_b = (nl_pos) ? nl_pos - (char*)db->LBF : len_b;
		len_line = (*line) ? ft_strlen(*line) : 0;
		if (!(ft_realloc((void**)line, len_line, len_line + len_b + 1)))
			return (ERROR);
		ft_memcpy((void*)*line + len_line, db->LBF, len_b);
		ft_memcpy(db->LBF, db->LBF + len_b + 1, BUFF_SIZE - len_b);
		ft_bzero(db->LBF + BUFF_SIZE - len_b, len_b);
	}
	else
	{
		if ((status = read(db->LFD, (char*)db->LBF, BUFF_SIZE)) < 0)
			return (ERROR);
		status = (status == 0) ? OVER : CONTINUE;
	}
	return ((status == OVER && *line) ? 1 : status);
}

int				get_next_line(int fd, char **line)
{
	static t_list		*o_db;
	t_list				*w_db;
	int					res;

	w_db = o_db;
	if (!line)
		return (ERROR);
	*line = NULL;
	while (w_db && w_db->LFD != fd)
		w_db = w_db->next;
	if (!w_db && (w_db = ft_memalloc(sizeof(t_list))))
		ft_lstadd(&o_db, w_db);
	if (w_db && w_db->LBF == NULL)
	{
		w_db->LFD = fd;
		w_db->LBF = ft_memalloc(BUFF_SIZE + 1);
	}
	if (!w_db || !(w_db->content))
		return (ERROR);
	while ((res = give_line(w_db, line)) == CONTINUE)
		;
	if (res == OVER)
		ft_lstfreeone(&o_db, w_db);
	return ((res == OVER) ? 0 : res);
}
