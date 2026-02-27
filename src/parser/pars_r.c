/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melisha <melisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:57:22 by melisha           #+#    #+#             */
/*   Updated: 2021/01/26 02:15:00 by melisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int		overflow(unsigned int *c, char s)
{
	unsigned int	save;

	save = *c;
	*c = *c * 10 + s - '0';
	if (save > *c)
		*c = 4294967294;
	return (1);
}

int		pars_r(char *line, t_vars *obj, int i)
{
	unsigned int	width;
	unsigned int	height;

	width = 0;
	height = 0;
	if (line[i] != ' ')
		return (-1);
	i = ft_space(line, i) - 1;
	while (line[++i] >= '0' && line[i] <= '9')
		overflow(&width, line[i]);
	i = ft_space(line, i) - 1;
	while (line[++i] >= '0' && line[i] <= '9')
		overflow(&height, line[i]);
	i = ft_space(line, i);
	if (line[i] != '\0')
		return (-1);
	if (width == 0 || height == 0)
		return (-1);
	if ((int)width < 0)
		width = 100000;
	if ((int)height < 0)
		height = 10000;
	obj->fill.r_one = (int)width;
	obj->fill.r_two = (int)height;
	return (i);
}
