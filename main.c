/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 13:24:34 by thou              #+#    #+#             */
/*   Updated: 2017/01/05 16:07:51 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	ft_puttab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		ft_putstr(tab[i]);
		ft_putchar('\n');
		i++;
	}
}

int		main(int ac, char **av)
{
	char	**tab;
	char	*src;

	if (ac != 2)
	{
		write(1, "usage: fillit [file]\n", 21);
		return (0);
	}
	if (!(src = readfile(av[1])))
	{
		write(1, "error\n", 6);
		return (0);
	}
	if (ft_check(src) == 0)
	{
		write(1, "error\n", 6);
		return (0);
	}
	if (!(tab = rangetab(src)))
	{
		write(1, "error\n", 6);
		return (0);
	}
	ft_puttab(solution(tab));
	return (0);
}
