/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melisha <melisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 15:40:33 by melisha           #+#    #+#             */
/*   Updated: 2021/01/25 23:56:01 by melisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

char	*fn_parser(t_vars *obj)
{
	int		fd;

	fd = open(obj->fill.file, O_RDONLY);
	if (fd == -1 || fd == 0)
	{
		perror(obj->fill.file);
		exit(0);
	}
	if (!(fn_pars_argument(obj, fd)))
		return (NULL);
	if (!(fn_pars_map(obj, fd)))
		return (NULL);
	close(fd);
	return ("OK");
}
