/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melisha <melisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 18:11:55 by melisha           #+#    #+#             */
/*   Updated: 2021/01/26 02:16:19 by melisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int		ft_overflow(int *c, char s)
{
	int	save;

	save = *c;
	*c = *c * 10 + s - '0';
	if (save > *c)
		*c = 2147483647;
	return (1);
}

int		fn_init_color(int *param, int *i, char *line, int f)
{
	int		count;

	count = *i;
	count = ft_space(line, count) - 1;
	if (line[count + 1] < '0' || line[count + 1] > '9')
		return (0);
	while (line[++count] >= '0' && line[count] <= '9')
		ft_overflow(param, line[count]);
	if (f == 1)
	{
		count = ft_space(line, count);
		if ((line[count]) != ',' || (line[count] == ','
			&& line[ft_space(line, count + 1)] == ','))
			return (0);
		count += 1;
	}
	*i = count;
	return (1);
}
