/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 15:39:55 by thou              #+#    #+#             */
/*   Updated: 2017/01/05 15:39:25 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**creattab(char **dst, int len)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	dst = ft_memalloc(sizeof(char*) * (len + 1));
	while (i < len)
	{
		dst[i] = ft_memalloc(sizeof(char) * (len + 1));
		while (j < len)
			dst[i][j++] = '.';
		dst[i++][j] = 0;
		j = 0;
	}
	dst[i] = NULL;
	return (dst);
}

char	**writetab(t_tetrimino *src, char **dst)
{
	int			i;

	i = 0;
	while (i < 4)
	{
		dst[src->y + (src->tetrimino[i][0])]
			[src->x + (src->tetrimino[i][1])] = src->letter;
		i++;
	}
	return (dst);
}

char	**resettab(t_tetrimino *src, char **dst)
{
	int			i;

	i = 0;
	while (i < 4)
	{
		dst[src->y + (src->tetrimino[i][0])]
			[src->x + (src->tetrimino[i][1])] = '.';
		i++;
	}
	return (dst);
}

int		ft_solvedst(char **dst, t_tetrimino *src, int len)
{
	if (!src)
		return (1);
	while (src->x < len || src->y < len)
	{
		if (ft_checkdst(src, dst, len) == 1)
		{
			dst = writetab(src, dst);
			if (ft_solvedst(dst, src->next, len) == 1)
				return (1);
			dst = resettab(src, dst);
		}
		if (src->x < len)
			src->x++;
		else
		{
			src->x = 0;
			src->y++;
		}
	}
	src->x = 0;
	src->y = 0;
	return (0);
}

char	**solution(char **tmp)
{
	t_tetrimino	*src;
	char		**dst;
	int			len;

	len = 2;
	src = start(tmp);
	dst = creattab(NULL, len);
	while (ft_solvedst(dst, src, len) == 0)
	{
		len++;
		src->x = 0;
		src->y = 0;
		ft_free_tab(dst, len);
		dst = creattab(dst, len);
	}
	return (dst);
}
