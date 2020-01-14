/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 14:55:35 by tlouekar          #+#    #+#             */
/*   Updated: 2020/01/09 09:48:47 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 21

# include "../libft/includes/libft.h"
# include <fcntl.h>

int				validate(char *raw);
int				solve(t_list *pieces);
t_list			*scan_save_tetramino(char *raw, t_list *pieces);
void			print_grid(t_list *pieces, char *grid);

#endif
