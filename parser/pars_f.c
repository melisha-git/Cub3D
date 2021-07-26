/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melisha <melisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 20:44:16 by melisha           #+#    #+#             */
/*   Updated: 2021/01/26 02:18:35 by melisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int		pars_f(char *line, t_vars *obj, int i)
{
	obj->fill.f_r = 0;
	obj->fill.f_g = 0;
	obj->fill.f_b = 0;
	if (!(fn_init_color(&obj->fill.f_r, &i, line, 1)))
		return (-1);
	if (!(fn_init_color(&obj->fill.f_g, &i, line, 1)))
		return (-1);
	if (!(fn_init_color(&obj->fill.f_b, &i, line, 0)))
		return (-1);
	i = ft_space(line, i);
	if (line[i] != '\0')
		return (-1);
	if (obj->fill.f_r < 0 || obj->fill.f_r > 255
		|| obj->fill.f_g < 0 || obj->fill.f_g > 255
		|| obj->fill.f_b < 0 || obj->fill.f_b > 255)
		return (-1);
	return (i);
}
