/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melisha <melisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 20:56:18 by melisha           #+#    #+#             */
/*   Updated: 2021/01/26 02:18:49 by melisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int		pars_c(char *line, t_vars *obj, int i)
{
	obj->fill.c_r = 0;
	obj->fill.c_g = 0;
	obj->fill.c_b = 0;
	if (!(fn_init_color(&obj->fill.c_r, &i, line, 1)))
		return (-1);
	if (!(fn_init_color(&obj->fill.c_g, &i, line, 1)))
		return (-1);
	if (!(fn_init_color(&obj->fill.c_b, &i, line, 0)))
		return (-1);
	i = ft_space(line, i);
	if (line[i] != '\0')
		return (-1);
	if (obj->fill.c_r < 0 || obj->fill.c_r > 255
		|| obj->fill.c_g < 0 || obj->fill.c_g > 255
		|| obj->fill.c_b < 0 || obj->fill.c_b > 255)
		return (-1);
	return (i);
}
