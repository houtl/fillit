/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxiao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 13:21:23 by xxiao             #+#    #+#             */
/*   Updated: 2016/12/30 15:37:04 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>

static int	ft_check_char(char *tab)
{
	int	block;
	int	empty;
	int	line;
	int i;

	block = 0;
	empty = 0;
	line = 0;
	i = 0;
	while (i < 20)
	{
		if (*tab == '#')
			block++;
		if (*tab == '.')
			empty++;
		if (*tab == '\n')
			line++;
		tab++;
		i++;
	}
	if (block != 4 || empty != 12 || line != 4)
		return (0);
	return (1);
}

static	int	ft_checkloc(char *s)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 20)
	{
		if (s[i] == '#')
		{
			if (i != 0 && s[i - 1] == '#')
				j++;
			if (s[i + 1] == '#')
				j++;
			if (i < 14 && s[i + 5] == '#')
				j++;
			if (i > 4 && s[i - 5] == '#')
				j++;
		}
		i++;
	}
	if (j == 6 || j == 8)
		return (1);
	return (0);
}

static	int	ft_check_return(char *s)
{
	int	i;

	i = 0;
	while (i < 20)
	{
		if (s[i] == '\n')
		{
			if (i % 5 != 4)
				return (0);
		}
		i++;
	}
	return (1);
}

int			ft_check(char *tab)
{
	if (*tab == 0 || !tab)
		return (0);
	while (*tab)
	{
		if (ft_strlen(tab) < 20)
			return (0);
		if (ft_check_char(tab) != 1)
			return (0);
		if (ft_check_return(tab) != 1)
			return (0);
		if (ft_checkloc(tab) != 1)
			return (0);
		tab = tab + 20;
		if (*tab == '\n' && tab[1] != 0)
			tab++;
		else if (*tab != '\n' && *tab)
			return (0);
		else if (*tab == '\n' && tab[1] == 0)
			return (0);
	}
	return (1);
}
