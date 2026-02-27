/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pos_sprite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melisha <melisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 18:00:01 by melisha           #+#    #+#             */
/*   Updated: 2021/01/26 01:16:40 by melisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	fn_init_start_sprite(t_vars *obj)
{
	obj->texture.sprite.start_y = -obj->texture.sprite.s_h / 2
	+ obj->fill.r_two / 2 + obj->texture.sprite.move_screen;
	if (obj->texture.sprite.start_y < 0)
		obj->texture.sprite.start_y = 0;
	obj->texture.sprite.end_y = obj->texture.sprite.s_h / 2
	+ obj->fill.r_two / 2 + obj->texture.sprite.move_screen;
	if (obj->texture.sprite.end_y >= (int)obj->fill.r_two)
		obj->texture.sprite.end_y = obj->fill.r_two - 1;
	obj->texture.sprite.s_w = abs((int)(obj->fill.r_one /
	(obj->texture.sprite.transform_y)));
	obj->texture.sprite.start_x = -obj->texture.sprite.s_w /
	2 + obj->texture.sprite.sprite_screen;
	if (obj->texture.sprite.start_x < 0)
		obj->texture.sprite.start_x = 0;
	obj->texture.sprite.end_x = obj->texture.sprite.s_w / 2
	+ obj->texture.sprite.sprite_screen;
	if (obj->texture.sprite.end_x >= (int)obj->fill.r_one)
		obj->texture.sprite.end_x = obj->fill.r_one - 1;
}

void	init_pos_sprite(t_vars *obj, int i)
{
	obj->texture.sprite.pos_x =
	obj->texture.sprite.sprite_x[i] - obj->player.pos_y + 0.5;
	obj->texture.sprite.pos_y =
	obj->texture.sprite.sprite_y[i] - obj->player.pos_x + 0.5;
	obj->texture.sprite.inv_deg = 1.0 / (obj->ray.plane_y *
	obj->player.dir_x - obj->player.dir_y * obj->ray.plane_x);
	obj->texture.sprite.transform_x = obj->texture.sprite.inv_deg *
	(obj->player.dir_x * obj->texture.sprite.pos_x - obj->player.dir_y
	* obj->texture.sprite.pos_y);
	obj->texture.sprite.transform_y = obj->texture.sprite.inv_deg *
	(-obj->ray.plane_x * obj->texture.sprite.pos_x + obj->ray.plane_y
	* obj->texture.sprite.pos_y);
	obj->texture.sprite.sprite_screen = (int)((obj->fill.r_one / 2) *
	(1 + obj->texture.sprite.transform_x / obj->texture.sprite.transform_y));
	obj->texture.sprite.move_screen = (int)
	(0.0 / obj->texture.sprite.transform_y);
	obj->texture.sprite.s_h = abs((int)(obj->fill.r_two
	/ (obj->texture.sprite.transform_y)));
	fn_init_start_sprite(obj);
}
