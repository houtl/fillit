/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 17:34:35 by thou              #+#    #+#             */
/*   Updated: 2016/12/09 17:28:09 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_free_tab(char **tab, int tab_size)
{
	int i;

	i = 0;
	while (i < tab_size)
	{
		ft_strdel(&tab[i]);
		i++;
	}
	ft_strdel(tab);
}

int			ft_checkdst(t_tetrimino *src, char **dst, int len)
{
	int			i;

	i = 0;
	while (i < 4)
	{
		if (src->y + src->tetrimino[i][0] >= len ||
				src->x + src->tetrimino[i][1] >= len)
			return (0);
		if (ft_isalpha(dst[src->y + src->tetrimino[i][0]]
				[src->x + src->tetrimino[i][1]]))
			return (0);
		i++;
	}
	return (1);
}

t_tetrimino	*ft_newstetri(char *tab, int n)
{
	t_tetrimino *tmp;
	int			i;
	int			j;

	tmp = (t_tetrimino*)malloc(sizeof(t_tetrimino));
	if (!tmp)
		return (NULL);
	i = 0;
	j = 0;
	while (i < 20 && j < 4)
		if (tab[i++] == '#')
		{
			tmp->tetrimino[j][0] = (i - 1) / 5;
			tmp->tetrimino[j++][1] = (i - 1) % 5;
		}
	tmp->letter = 'A' + n;
	tmp->x = 0;
	tmp->y = 0;
	tmp->next = NULL;
	return (tmp);
}

t_tetrimino	*start(char **tab)
{
	t_tetrimino *tmp;
	t_tetrimino	*prc;
	int			i;

	prc = ft_newstetri(tab[0], 0);
	i = 1;
	tmp = prc;
	while (tab[i])
	{
		tmp->next = ft_newstetri(tab[i], i);
		tmp = tmp->next;
		i++;
	}
	return (prc);
}
