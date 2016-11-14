/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfreeone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmenzagh <hmenzagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 00:58:50 by hmenzagh          #+#    #+#             */
/*   Updated: 2016/11/14 01:14:59 by hmenzagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_lstfreeone(t_list **o_ptr, t_list *d_ptr)
{
	t_list		*w_ptr;

	w_ptr = *o_ptr;
	if (!o_ptr || !*o_ptr || !d_ptr)
		return (ERROR);
	while (w_ptr->next != d_ptr && w_ptr != d_ptr)
		w_ptr = w_ptr->next;
	if (d_ptr == w_ptr)
	{
		*o_ptr = w_ptr->next;
		free(w_ptr->content);
		free(w_ptr);
	}
	else
	{
		w_ptr->next = w_ptr->next->next;
		free(d_ptr->content);
		free(d_ptr);
	}
	return (1);
}
