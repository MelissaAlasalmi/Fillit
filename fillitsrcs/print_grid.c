/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 13:13:45 by tlouekar          #+#    #+#             */
/*   Updated: 2020/01/09 07:28:29 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

void	ft_lstdelsimple(t_list *pieces)
{
	t_list	*list;
	t_list	*next;
	int		i;

	i = 0;
	list = pieces;
	while (list)
	{
		i++;
		next = list->next;
		free(list);
		list = NULL;
		list = next;
	}
	pieces = NULL;
}

void	print_grid(t_list *pieces, char *grid)
{
	int		i;

	i = 0;
	while (grid[i] != '\0')
	{
		while (grid[i] == '1')
			i++;
		if (grid[i] == '0')
			grid[i] = '.';
		if (grid[i] == '\n' && grid[i + 1] == '1')
			break ;
		ft_putchar(grid[i]);
		i++;
	}
	ft_lstdelsimple(pieces);
	free(grid);
}
