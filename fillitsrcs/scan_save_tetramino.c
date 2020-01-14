/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_save_tetramino.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 13:13:54 by tlouekar          #+#    #+#             */
/*   Updated: 2020/01/08 16:02:45 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "fillit.h"

void	ft_foreach(int *tab, int length)
{
	int i;

	i = 0;
	while (length > i)
	{
		tab[i]--;
		i++;
	}
}

int		*left(int *tet)
{
	int j;

	j = 0;
	while (tet[j] % 5 != 0)
	{
		if (tet[0] == 0 || tet[1] == 5 || tet[2] == 5 || tet[2] == 10)
			break ;
		ft_foreach(tet, 4);
		j++;
	}
	return (tet);
}

int		*top(char *chunk, int *tet)
{
	int i;
	int j;
	int top;

	i = 0;
	j = 0;
	top = 0;
	while (chunk[i] != '\0')
	{
		if (chunk[i] == '#')
		{
			top = i / 5;
			break ;
		}
		i++;
	}
	i = 0;
	while (chunk[i] != '\0')
	{
		if (chunk[i] == '#')
			tet[j++] = i - top * 5;
		i++;
	}
	j = 0;
	return (left(tet));
}

t_list	*make_list(t_list *first, t_list **alst, t_list *new)
{
	t_list	*lst;

	lst = *alst;
	if (!first)
		first = *alst;
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
		lst->next = new;
	}
	else
		*alst = new;
	return (*alst);
}

t_list	*scan_save_tetramino(char *raw, t_list *pieces)
{
	char	*chunk;
	int		i;
	size_t	j;
	t_list	*first;
	int		*tet;

	i = 0;
	j = 0;
	first = NULL;
	while (raw[i] != '\0')
	{
		while (j < (ft_strlen(raw) / 20))
		{
			chunk = ft_strsub(raw, (j * 21), 21);
			tet = ft_memalloc(21);
			tet = top(chunk, tet);
			pieces = make_list(first, &pieces, ft_lstnew(tet, 16));
			free(tet);
			free(chunk);
			j++;
		}
		i++;
	}
	return (pieces);
}
