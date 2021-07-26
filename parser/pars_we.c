/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_we.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melisha <melisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 21:18:23 by melisha           #+#    #+#             */
/*   Updated: 2021/01/26 06:28:46 by melisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int		pars_we(char *line, t_vars *obj, int i)
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
	if (!(obj->fill.we = ft_substr(line, i, len - i + 1)))
		fn_error("Error : unable to allocate memory \n");
	fd = open(obj->fill.we, O_RDONLY);
	if (fd == -1)
	{
		perror(obj->fill.we);
		exit(0);
	}
	close(fd);
	return (i);
}
