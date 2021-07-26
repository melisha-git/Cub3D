/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_so.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melisha <melisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 21:16:51 by melisha           #+#    #+#             */
/*   Updated: 2021/01/26 06:28:39 by melisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int		pars_so(char *line, t_vars *obj, int i)
{
	int		len;
	int		fd;

	if (line[i] != ' ')
		return (-1);
	i = ft_space(line, i);
	len = i;
	while (line[len] != ' ' && line[len])
		len++;
	if (line[len] == ' ')
		len--;
	if (!(obj->fill.so = ft_substr(line, i, len - i + 1)))
		fn_error("Error : unable to allocate memory \n");
	fd = open(obj->fill.so, O_RDONLY);
	if (fd == -1)
	{
		perror(obj->fill.so);
		exit(0);
	}
	close(fd);
	return (i);
}
