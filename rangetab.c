/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rangetab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 15:20:11 by thou              #+#    #+#             */
/*   Updated: 2016/12/06 17:45:32 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**mvtab_vertical(char **tab)
{
	int		i;
	int		j;

	i = 0;
	while (tab[i])
	{
		while (tab[i][0] == '.' && tab[i][1] == '.' &&
				tab[i][2] == '.' && tab[i][3] == '.')
		{
			j = 0;
			while (j < 15)
			{
				tab[i][j] = tab[i][j + 5];
				j++;
			}
			while (j < 19)
				tab[i][j++] = '.';
		}
		i++;
	}
	return (tab);
}

char	**mvtab_horizon(char **tab)
{
	int		i;
	int		j;

	i = 0;
	while (tab[i])
	{
		while (tab[i][0] == '.' && tab[i][5] == '.' &&
				tab[i][10] == '.' && tab[i][15] == '.')
		{
			j = 0;
			while (j < 19)
			{
				if ((j + 1) % 5 && (j + 1) % 5 != 4)
					tab[i][j] = tab[i][j + 1];
				else if ((j + 1) % 5 == 4)
					tab[i][j] = '.';
				j++;
			}
		}
		i++;
	}
	return (tab);
}

char	**mvtab(char **tab)
{
	tab = mvtab_vertical(tab);
	tab = mvtab_horizon(tab);
	return (tab);
}

char	**rangetab(char *src)
{
	char	*a;
	int		i;
	int		j;
	char	**tab;

	a = src;
	i = 0;
	if (!src)
		return (NULL);
	tab = (char**)malloc(sizeof(char*) * (27));
	if (!tab)
		return (NULL);
	while (*a)
	{
		j = 0;
		tab[i] = (char*)malloc(sizeof(char) * (22));
		while (j < 21 && *a)
		{
			if (*a)
				tab[i][j++] = *(a++);
		}
		tab[i++][j] = 0;
	}
	tab[i] = 0;
	return (mvtab(tab));
}
