/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melisha <melisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 01:20:10 by melisha           #+#    #+#             */
/*   Updated: 2021/01/27 14:48:25 by melisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	fn_move_up(t_vars *obj)
{
	if (obj->fill.map[(int)((obj->player.pos_y + obj->player.dir_y
	* obj->player.speed))][(int)(obj->player.pos_x)] == '0')
		obj->player.pos_y += obj->player.dir_y * obj->player.speed;
	if (obj->fill.map[(int)(obj->player.pos_y)][(int)
	(obj->player.pos_x + obj->player.dir_x * obj->player.speed)] == '0')
		obj->player.pos_x += obj->player.dir_x * obj->player.speed;
}

void	fn_move_down(t_vars *obj)
{
	if (obj->fill.map[(int)(obj->player.pos_y - obj->player.dir_y
	* obj->player.speed)][(int)(obj->player.pos_x)] == '0')
		obj->player.pos_y -= obj->player.dir_y * obj->player.speed;
	if (obj->fill.map[(int)(obj->player.pos_y)][(int)
	(obj->player.pos_x - obj->player.dir_x * obj->player.speed)] == '0')
		obj->player.pos_x -= obj->player.dir_x * obj->player.speed;
}

void	fn_move_right(t_vars *obj)
{
	if (obj->fill.map[(int)((obj->player.pos_y + obj->player.dir_x
	* obj->player.speed))][(int)(obj->player.pos_x)] == '0')
		obj->player.pos_y += obj->player.dir_x * obj->player.speed;
	if (obj->fill.map[(int)(obj->player.pos_y)][(int)(obj->player.pos_x
	- obj->player.dir_y * obj->player.speed)] == '0')
		obj->player.pos_x -= obj->player.dir_y * obj->player.speed;
}

void	fn_move_left(t_vars *obj)
{
	if (obj->fill.map[(int)((obj->player.pos_y - obj->player.dir_x
	* obj->player.speed))][(int)(obj->player.pos_x)] == '0')
		obj->player.pos_y -= obj->player.dir_x * obj->player.speed;
	if (obj->fill.map[(int)(obj->player.pos_y)][(int)(obj->player.pos_x
	+ obj->player.dir_y * obj->player.speed)] == '0')
		obj->player.pos_x += obj->player.dir_y * obj->player.speed;
}
