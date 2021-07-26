/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_paint_life.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melisha <melisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 20:26:40 by melisha           #+#    #+#             */
/*   Updated: 2021/01/27 22:34:45 by melisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	fn_paint_life(t_vars *obj)
{
	char	*life;
	int		color;

	color = 0x00FF00;
	if (obj->player.life <= 0)
	{
		system("killall afplay");
		system("afplay sound/death_2.mp3 &");
		fn_error("you lost\n");
	}
	if (!(life = ft_itoa(obj->player.life)))
		fn_error("Error : unable to allocate memory \n");
	if (obj->player.life <= 60 && obj->player.life >= 40)
		color = 0xffd900;
	else if (obj->player.life < 40)
		color = 0xff0000;
	mlx_string_put(obj->mlx, obj->win, 10, 20, color, life);
	free(life);
}
