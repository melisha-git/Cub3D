/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_leaks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melisha <melisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 23:44:33 by melisha           #+#    #+#             */
/*   Updated: 2021/01/25 23:45:41 by melisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

char	*fn_add_plus(t_vars *obj)
{
	char	*leaks;

	leaks = obj->fill.buff;
	if (!(obj->fill.buff = ft_strjoin(obj->fill.buff, "+")))
		return (NULL);
	free(leaks);
	return ("OK");
}

char	*add_line(t_vars *obj, char *line)
{
	char	*leaks;

	leaks = obj->fill.buff;
	if (!(obj->fill.buff = ft_strjoin(obj->fill.buff, line))
		|| !(fn_add_plus(obj)))
		return (NULL);
	free(leaks);
	return ("OK");
}
