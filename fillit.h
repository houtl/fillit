/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 14:17:37 by thou              #+#    #+#             */
/*   Updated: 2017/01/05 15:36:33 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>

# define BUF_SIZE 4096

typedef struct			s_tetrimino
{
	int					tetrimino[4][2];
	char				letter;
	int					x;
	int					y;
	struct s_tetrimino	*next;
}						t_tetrimino;

void					ft_free_tab(char **tab, int tab_size);
int						ft_checkdst(t_tetrimino *src, char **dst, int len);
t_tetrimino				*ft_newstetri(char *tab, int i);
t_tetrimino				*start(char **tab);
int						ft_check(char *src);
char					*readfile(char *file_name);
char					**rangetab(char *src);
void					ft_puttab(char **tab);
char					**solution(char **tmp);

#endif
