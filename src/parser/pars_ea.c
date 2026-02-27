/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_ea.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melisha <melisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 21:22:05 by melisha           #+#    #+#             */
/*   Updated: 2021/01/26 06:28:50 by melisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int		pars_ea(char *line, t_vars *obj, int i)
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
	if (!(obj->fill.ea = ft_substr(line, i, len - i + 1)))
		fn_error("Error : unable to allocate memory \n");
	fd = open(obj->fill.ea, O_RDONLY);
	if (fd == -1)
	{
		perror(obj->fill.ea);
		exit(0);
	}
	close(fd);
	return (i);
}
