/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melisha <melisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 01:25:14 by melisha           #+#    #+#             */
/*   Updated: 2021/01/26 01:31:36 by melisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	fn_turn_r(t_vars *obj)
{
	double	savedirx;
	double	saveplaney;

	savedirx = obj->player.dir_x;
	obj->player.dir_x = obj->player.dir_x
	* cos(-obj->ray.speed) - obj->player.dir_y * sin(-obj->ray.speed);
	obj->player.dir_y = savedirx *
	sin(-obj->ray.speed) + obj->player.dir_y * cos(-obj->ray.speed);
	saveplaney = obj->ray.plane_x;
	obj->ray.plane_x = obj->ray.plane_x *
	cos(-obj->ray.speed) - obj->ray.plane_y * sin(-obj->ray.speed);
	obj->ray.plane_y = saveplaney *
	sin(-obj->ray.speed) + obj->ray.plane_y * cos(-obj->ray.speed);
	obj->player.angle += 1.0;
}

void	fn_turn_l(t_vars *obj)
{
	double	savedirx;
	double	saveplanex;

	savedirx = obj->player.dir_x;
	obj->player.dir_x = obj->player.dir_x *
	cos(obj->ray.speed) - obj->player.dir_y * sin(obj->ray.speed);
	obj->player.dir_y = savedirx * sin(obj->ray.speed)
	+ obj->player.dir_y * cos(obj->ray.speed);
	saveplanex = obj->ray.plane_x;
	obj->ray.plane_x = obj->ray.plane_x *
	cos(obj->ray.speed) - obj->ray.plane_y * sin(obj->ray.speed);
	obj->ray.plane_y = saveplanex * sin(obj->ray.speed)
	+ obj->ray.plane_y * cos(obj->ray.speed);
	obj->player.angle += 1.0;
}
