/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmenzagh <hmenzagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 11:54:46 by hmenzagh          #+#    #+#             */
/*   Updated: 2016/11/22 11:57:01 by hmenzagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
