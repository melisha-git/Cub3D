/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melisha <melisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:05:05 by melisha           #+#    #+#             */
/*   Updated: 2021/01/29 07:12:39 by melisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

char	*fn_check_pos(t_vars *obj, int j, size_t i)
{
	if (j == 0 || i == 0)
		return (NULL);
	if (!obj->fill.map[j + 1] || !obj->fill.map[j - 1])
		return (NULL);
	if (ft_strlen(obj->fill.map[j - 1]) < i
		|| ft_strlen(obj->fill.map[j + 1]) < i)
		return (NULL);
	if (obj->fill.map[j][i - 1] == ' ' || obj->fill.map[j][i - 1] == '\0'
		|| obj->fill.map[j][i + 1] == ' ' || obj->fill.map[j][i + 1] == '\0')
		return (NULL);
	if (obj->fill.map[j - 1][i] == ' ' || obj->fill.map[j - 1][i] == '\0'
		|| obj->fill.map[j + 1][i] == ' ' || obj->fill.map[j + 1][i] == '\0')
		return (NULL);
	if (obj->fill.map[j - 1][i - 1] == ' ' ||
		obj->fill.map[j - 1][i - 1] == '\0'
		|| obj->fill.map[j - 1][i + 1] == ' '
		|| obj->fill.map[j - 1][i + 1] == '\0'
		|| obj->fill.map[j + 1][i - 1] == ' '
		|| obj->fill.map[j + 1][i - 1] == '\0'
		|| obj->fill.map[j + 1][i + 1] == ' '
		|| obj->fill.map[j + 1][i + 1] == '\0')
		return (NULL);
	return ("OK");
}

char	*fn_check_count_player(t_vars *obj)
{
	int		i;
	int		j;

	j = 0;
	obj->fill.flag_params.p = 0;
	while (obj->fill.map[j])
	{
		i = 0;
		while (obj->fill.map[j][i])
		{
			if ((obj->fill.map[j][i] == 'N' || obj->fill.map[j][i] == 'W'
				|| obj->fill.map[j][i] == 'S' ||
				obj->fill.map[j][i] == 'E') && obj->fill.flag_params.p == 1)
				return (NULL);
			if ((obj->fill.map[j][i] == 'N' || obj->fill.map[j][i] == 'W'
				|| obj->fill.map[j][i] == 'S' ||
				obj->fill.map[j][i] == 'E') && obj->fill.flag_params.p == 0)
				obj->fill.flag_params.p = 1;
			i++;
		}
		j++;
	}
	if (obj->fill.flag_params.p == 0)
		return (NULL);
	return ("OK");
}

char	*ft_valid_map(t_vars *obj)
{
	int		i;
	int		j;

	j = 0;
	if (!(fn_check_count_player(obj)))
		return (NULL);
	while (obj->fill.map[j])
	{
		i = 0;
		while (obj->fill.map[j][i])
		{
			if (!(fn_search_no_wall(i, j, obj)))
				return (NULL);
			i++;
		}
		j++;
	}
	return ("OK");
}

char	*fn_pars_map(t_vars *obj, int fd)
{
	char	*line;
	int		r;

	if (!(fn_add_plus(obj)))
		fn_error("Error : unable to allocate memory \n");
	get_next_line(fd, &line);
	if (!(add_line(obj, line)))
		fn_error("Error : unable to allocate memory \n");
	while (line[0] == '1' || line[0] == ' ')
	{
		free(line);
		r = get_next_line(fd, &line);
		if (!(add_line(obj, line)))
			fn_error("Error : unable to allocate memory \n");
		if (r == 0)
			break ;
	}
	if (r != 0)
		return (NULL);
	free(line);
	if (!(obj->fill.map = ft_split(obj->fill.buff, '+')))
		fn_error("Error : unable to allocate memory \n");
	free(obj->fill.buff);
	return (ft_valid_map(obj));
}
