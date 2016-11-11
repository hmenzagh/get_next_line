/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmenzagh <hmenzagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 21:16:36 by hmenzagh          #+#    #+#             */
/*   Updated: 2016/11/11 11:07:22 by hmenzagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

void				cleanup(t_list **ptr)
{
	t_list			*save;
	t_list			*prev;

	save = *ptr;
	if (save->content->read_return <= 0)
	{
		free(save->content);
		*ptr = save->next;
		free(save);
	}
	else
	{
		while (save && save->content->read_return <= 0)
		{
			prev = save;
			save = save->next;
		}
		if (save->content->read_return <= 0)
		{
			free(save->content);
			prev->next = save->next;
			free(save);
		}
	}
}

int					contat_read(t_bag *db, char **line)
{
	if((db->read_return = read(db->fd, db->buff, BUFF_SIZE)) > 0)
		db->buff[db->read_return] = '\0';
	else if (db->read_return == ERROR)
		return (ERROR);
	else
		return (OVER);

	return (0);
}

int					prep_give_line(t_bag *db, char **line)
{
	if (!line)
		return (ERROR);
	if (*line != NULL)
		free(*line);
	while (contact_read(db, line) == 0);
}

int					get_next_line(int const fd, char **line)
{
	static t_list	*ptr;
	t_list			*wptr;
	t_bag			*tmp;

	wptr = prt;
	if (wptr)
		while (wptr && wptr->content->fd != fd)
			wptr = wptr->next;
	if (wptr->content->fd != fd)
	{
		wptr = ptr;
		if (!(tmp = malloc(sizeof(t_bag))))
			return (ERROR);
		ft_lstadd(wptr, ft_lstnew(tmp, sizeof(t_bag)));
		ptr = wptr;
		wptr->content->fd = fd;
	}
	cleanup(&ptr);
	return (prep_give_line(wptr->content, line));
}
