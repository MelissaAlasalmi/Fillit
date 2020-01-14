/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 13:13:26 by tlouekar          #+#    #+#             */
/*   Updated: 2020/01/10 11:59:04 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "fillit.h"

char		*buildraw(int fd)
{
	char		buf[21];
	int			bt;
	char		*temp;
	char		*raw;
	int			i;

	bt = 0;
	i = 0;
	raw = ft_strnew(0);
	while ((bt = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[bt] = '\0';
		temp = ft_strjoin(raw, buf);
		free(raw);
		raw = temp;
	}
	return (raw);
}

int			main(int argc, char **argv)
{
	char	*raw;
	int		fd;
	int		i;
	t_list	*pieces;

	fd = 0;
	i = 0;
	pieces = NULL;
	if (argc != 2)
	{
		ft_putstr("usage: fillit <filename>\n");
		return (0);
	}
	else if ((fd = open(argv[1], O_RDONLY)) != 3)
		ft_putstr("error\n");
	else if ((raw = buildraw(fd)) == NULL)
		ft_putstr("error\n");
	else if (validate(raw) == 0)
		ft_putstr("error\n");
	else
		solve(scan_save_tetramino(raw, pieces));
	return (0);
}
