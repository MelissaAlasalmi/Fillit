/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 13:14:18 by tlouekar          #+#    #+#             */
/*   Updated: 2020/01/13 09:21:48 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "fillit.h"

int		find_place(int pos, char *grid, int *temp)
{
	int		offset;
	int		i;
	int		origpos;

	i = 0;
	origpos = 0;
	while (i < 4 && pos <= 182)
	{
		offset = ((temp[i] / 4) * 9);
		if ((grid[temp[i] + offset + pos] - 48) == 0)
		{
			if (i == 0)
				origpos = pos;
			i++;
		}
		else
		{
			i = 0;
			pos++;
		}
	}
	if (pos > 182)
		return (-1);
	return (origpos);
}

int		recursion(t_list *pieces, int pos, char tletter, char *grid)
{
	int			i;
	int			*temp;

	while (pieces != NULL)
	{
		temp = pieces->content;
		if ((pos = find_place(++pos, grid, temp)) < 0)
			return (0);
		i = -1;
		while (++i < 4)
			grid[temp[i] + ((temp[i] / 4) * 9) + pos] = tletter;
		if (recursion(pieces->next, -1, ++tletter, grid) == 0)
		{
			i = -1;
			while (++i < 4)
				grid[temp[i] + ((temp[i] / 4) * 9) + pos] = '0';
			tletter--;
		}
		else
		{
			free(temp);
			return (1);
		}
	}
	return (1);
}

int		fit_piece(char *grid, int gridsize, t_list *pieces)
{
	char		tletter;
	int			i;
	int			j;

	i = -1;
	j = 0;
	tletter = 'A';
	while (gridsize < 13)
	{
		if (recursion(pieces, -1, tletter, grid) == 1)
			return (1);
		else
		{
			while (j++ < gridsize)
			{
				while ((++i % 14) < gridsize)
					grid[i] = '0';
				i += 13 - gridsize;
			}
			gridsize++;
			i = 0;
			j = 0;
		}
	}
	return (1);
}

char	*stringspectacular(char *spectacular)
{
	int		i;
	int		j;
	int		k;
	char	*str1;
	char	*str2;

	str1 = ft_strdup("0011111111111\n0011111111111\n");
	str2 = ft_strdup("1111111111111\n");
	i = 10;
	k = 0;
	j = 0;
	while (str1[++k] != '\0')
		spectacular[k] = str1[k];
	k = 0;
	while (--i > 0)
	{
		while (str2[j] != '\0')
			spectacular[++k + 28] = str2[++j];
		j = 0;
	}
	free(str1);
	free(str2);
	return (spectacular);
}

int		solve(t_list *pieces)
{
	char	*grid;
	int		gridsize;
	char	*spectacular;

	spectacular = ft_strnew(183);
	grid = stringspectacular(spectacular);
	gridsize = 2;
	fit_piece(grid, gridsize, pieces);
	print_grid(pieces, grid);
	return (0);
}
