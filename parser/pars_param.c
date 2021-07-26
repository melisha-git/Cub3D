/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melisha <melisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:07:08 by melisha           #+#    #+#             */
/*   Updated: 2021/01/26 06:19:42 by melisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	fn_zero_params(t_vars *obj)
{
	obj->fill.flag_params.r = 0;
	obj->fill.flag_params.no = 0;
	obj->fill.flag_params.so = 0;
	obj->fill.flag_params.we = 0;
	obj->fill.flag_params.ea = 0;
	obj->fill.flag_params.s = 0;
	obj->fill.flag_params.f = 0;
	obj->fill.flag_params.c = 0;
}

int		ft_check_text(char *line, t_vars *obj)
{
	if (line[0] == 'N' && line[1] == 'O' && obj->fill.flag_params.no == 0
		&& (obj->fill.flag_params.no = 1) != -1)
		return (pars_no(line, obj, 2));
	if (line[0] == 'S' && line[1] == 'O' && obj->fill.flag_params.so == 0
		&& (obj->fill.flag_params.so = 1) != -1)
		return (pars_so(line, obj, 2));
	if (line[0] == 'W' && line[1] == 'E' && obj->fill.flag_params.we == 0
		&& (obj->fill.flag_params.we = 1) != -1)
		return (pars_we(line, obj, 2));
	if (line[0] == 'E' && line[1] == 'A' && obj->fill.flag_params.ea == 0
		&& (obj->fill.flag_params.ea = 1) != -1)
		return (pars_ea(line, obj, 2));
	if (line[0] == 'S' && line[1] == ' ' && obj->fill.flag_params.s == 0
		&& (obj->fill.flag_params.s = 1) != -1)
		return (pars_s(line, obj, 1));
	if (line[0] == '\0')
		return (0);
	return (-1);
}

int		ft_checker(char *line, t_vars *obj)
{
	if (line[0] == 'R' && obj->fill.flag_params.r == 0
		&& (obj->fill.flag_params.r = 1) != -1)
		return (pars_r(line, obj, 1));
	if (line[0] == 'F' && line[1] == ' ' && obj->fill.flag_params.f == 0
		&& (obj->fill.flag_params.f = 1) != -1)
		return (pars_f(line, obj, 2));
	if (line[0] == 'C' && line[1] == ' ' && obj->fill.flag_params.c == 0
		&& (obj->fill.flag_params.c = 1) != -1)
		return (pars_c(line, obj, 2));
	return (ft_check_text(line, obj));
}

char	*fn_check_transfer(t_vars *obj)
{
	if (obj->fill.flag_params.r == 0 || obj->fill.flag_params.f == 0
		|| obj->fill.flag_params.c == 0 || obj->fill.flag_params.no == 0
		|| obj->fill.flag_params.so == 0 || obj->fill.flag_params.we == 0
		|| obj->fill.flag_params.ea == 0 || obj->fill.flag_params.s == 0)
		return (NULL);
	return ("OK");
}

char	*fn_pars_argument(t_vars *obj, int fd)
{
	char	*line;
	int		i;
	int		r;

	fn_zero_params(obj);
	i = 0;
	while ((r = get_next_line(fd, &line)) != 0)
	{
		i = ft_space(line, i);
		if (line[i] == '1' || (line[i] == '\0' && line[i - 1] == ' '))
			break ;
		if ((i = ft_checker(line, obj)) == -1)
			return (NULL);
		free(line);
		i = 0;
	}
	if (!(obj->fill.buff = ft_strdup(line)))
		fn_error("Error : unable to allocate memory \n");
	free(line);
	return (fn_check_transfer(obj));
}
