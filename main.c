/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmenzagh <hmenzagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 23:55:25 by hmenzagh          #+#    #+#             */
/*   Updated: 2016/11/10 12:54:28 by hmenzagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

int			main(int ac, char **av)
{
	int		fd[MAX_FD];
	int		i;
	char	*line;
	int		count = 10000;

	i = -1;
	(void)line;
	(void)av;
	if (ac >= 2)
	{
		while (++i < ac - 1)
		{
			//fd[i] = open(av[i + 1], O_RDONLY);
			//ft_putnbr(fd[i - 1]);
			fd[i] = i + 1;
			while (get_next_line(fd[i], &line) && --count)
			{
				ft_putstr(line);
				ft_putchar('\n');
			}
			ft_putstr("\n [~~~~~ NEW_FD ~~~~~]");
		}
	}
	else
		ft_putstr("T'es un debile !\n");

	return (0);
}