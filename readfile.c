/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 14:47:00 by thou              #+#    #+#             */
/*   Updated: 2016/12/06 17:46:53 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*readfile(char *file_name)
{
	int		fd;
	int		ret;
	char	src;
	int		i;
	char	*dst;

	if ((fd = open(file_name, O_RDONLY)) < 0)
		return (NULL);
	i = 0;
	while ((ret = read(fd, &src, 1)))
		i++;
	close(fd);
	if ((fd = open(file_name, O_RDONLY)) < 0)
		return (NULL);
	dst = ft_strnew(i);
	while (read(fd, dst, i))
		;
	dst[i] = 0;
	close(fd);
	return (dst);
}
