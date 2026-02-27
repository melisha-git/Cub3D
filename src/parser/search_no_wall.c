/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_no_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melisha <melisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 23:49:26 by melisha           #+#    #+#             */
/*   Updated: 2021/01/29 07:00:49 by melisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

char	*fn_search_no_wall(int i, int j, t_vars *obj)
{
	if (obj->fill.map[j][i] != '2' && obj->fill.map[j][i] != '0'
		&& (obj->fill.map[j][i] != 'N' && obj->fill.map[j][i] != 'W'
		&& obj->fill.map[j][i] != 'S' && obj->fill.map[j][i] != 'E')
		&& obj->fill.map[j][i] != '1' && obj->fill.map[j][i] != ' ')
		return (NULL);
	if (obj->fill.map[j][i] == '2' || obj->fill.map[j][i] == '0'
		|| obj->fill.map[j][i] == 'N' || obj->fill.map[j][i] == 'W'
		|| obj->fill.map[j][i] == 'S' || obj->fill.map[j][i] == 'E')
		if (!(fn_check_pos(obj, j, i)))
			return (NULL);
	return ("OK");
}
