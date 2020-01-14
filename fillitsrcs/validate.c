/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 13:14:39 by tlouekar          #+#    #+#             */
/*   Updated: 2020/01/01 14:14:42 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

int		asciicheck(char *raw)
{
	int		i;
	int		temp;
	int		nlcounter;

	i = 0;
	temp = 0;
	nlcounter = 0;
	if (!ft_strchr(raw, '#') && !ft_strchr(raw, '.'))
		return (0);
	while (raw[i] != '\0')
	{
		temp = temp + raw[i];
		i++;
		if (raw[i] == '\n')
			nlcounter = 0;
		nlcounter++;
		if (nlcounter > 5 || i > 546)
			return (0);
	}
	i = 0;
	if ((temp + 10) % 742 == 0)
		return (1);
	return (0);
}

int		validate_tetrimino(int start, char *raw)
{
	int		i;
	int		ncount;

	i = 0;
	ncount = 0;
	while (i < 21)
	{
		if ((raw[start + i] == '#') && ((start + i + 1) % 21 != 0))
		{
			if ((raw[start + i + 5] == '#') && ((start + i + 1) % 21 < 17))
				ncount += 2;
			if (raw[start + i + 1] == '#')
				ncount += 2;
		}
		i++;
	}
	if (ncount == 6 || ncount == 8)
		return (1);
	return (0);
}

int		validate_nbrs(char *raw)
{
	int		i;
	int		j;
	int		sharps;

	i = 0;
	j = 0;
	sharps = 0;
	while (raw[i] != '\0')
	{
		while ((j < 21) && (raw[i + j] != '\0'))
		{
			if (raw[i + j] == '#')
				sharps++;
			j++;
		}
		if (sharps != 4)
			return (0);
		else if (validate_tetrimino(i, raw) == 0)
			return (0);
		sharps = 0;
		i += j;
		j = 0;
	}
	return (1);
}

int		validate(char *raw)
{
	if (validate_nbrs(raw) == 0)
		return (0);
	if (asciicheck(raw) == 0)
		return (0);
	return (1);
}
