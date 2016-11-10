/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmenzagh <hmenzagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 21:16:36 by hmenzagh          #+#    #+#             */
/*   Updated: 2016/11/10 16:07:44 by hmenzagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

int					get_next_line(int const fd, char **line)
{
	static t_bag	db;
	int				i;
	
	i = 0;
	while (db.t[i][IFD] && i < MAX_FD - 1 && fd != db.t[i][IFD])
		++i;
	if (db.t[i][IFD] != fd)
	{
		while (db.t[i][IFD] && i < MAX_FD - 1 && db.t[i][RR] >= 0)
			++i;
		i = (db.t[i][RR] <= 0) ? i : 0;
		if (i == 0 && db.t[0][IFD])
		{
			while (db.t[i][LID] >= db.t[i + 1][LID] && i + 1 < MAX_FD)
				if (i > 0 && db.t[i][LID] < db.t[i - 1][LID])
					break;
				else
					++i;
			i = (i == MAX_FD - 1 && db.t[i][LID] == db.t[i - 1][LID]) ? 0 : i;
		}
		db.t[i][IFD] = fd;
		db.t[i][LID] += 1;
	}
	return (give_line(i, &db, fd, line));
}
