/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_init_raycast.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melisha <melisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 14:14:11 by melisha           #+#    #+#             */
/*   Updated: 2021/01/26 01:10:55 by melisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	fn_init_texpos(t_vars *obj)
{
	if (obj->ray.raycast.side == 0)
		obj->texture.wall = obj->player.pos_y
		+ obj->ray.raycast.perp_wall_dist * obj->ray.dir_y;
	else
		obj->texture.wall =
		obj->player.pos_x + obj->ray.raycast.perp_wall_dist * obj->ray.dir_x;
	obj->texture.wall -= floor((obj->texture.wall));
	obj->texture.tex_x =
	(int)(obj->texture.wall * (double)(obj->texture.t_width));
	if (obj->ray.raycast.side == 0 && obj->ray.dir_x > 0)
		obj->texture.tex_x = obj->texture.t_width - obj->texture.tex_x - 1;
	if (obj->ray.raycast.side == 1 && obj->ray.dir_y < 0)
		obj->texture.tex_x = obj->texture.t_height - obj->texture.tex_x - 1;
	obj->texture.step = 1.0 * obj->texture.t_width / obj->ray.raycast.lineh;
	obj->texture.texpos = (obj->ray.raycast.start - obj->fill.r_two / 2 +
	obj->ray.raycast.lineh / 2) * obj->texture.step;
}

void	fn_raycast_init_before(t_vars *obj, int x)
{
	obj->ray.dir_x = obj->player.dir_x + obj->ray.plane_x *
	(2 * x / (double)obj->fill.r_one - 1);
	obj->ray.dir_y = obj->player.dir_y + obj->ray.plane_y *
	(2 * x / (double)obj->fill.r_one - 1);
	obj->ray.raycast.map_x = (int)(obj->player.pos_x);
	obj->ray.raycast.map_y = (int)(obj->player.pos_y);
	obj->ray.raycast.delta_dist_x = sqrt(1 +
	(obj->ray.dir_y * obj->ray.dir_y) / (obj->ray.dir_x * obj->ray.dir_x));
	obj->ray.raycast.delta_dist_y = sqrt(1 +
	(obj->ray.dir_x * obj->ray.dir_x) / (obj->ray.dir_y * obj->ray.dir_y));
	obj->ray.raycast.hit = 0;
}

void	fn_raycast_init_after(t_vars *obj)
{
	if (obj->ray.raycast.side == 0)
		obj->ray.raycast.perp_wall_dist = (obj->ray.raycast.map_x -
		obj->player.pos_x + (1 - obj->ray.raycast.step_x) / 2) / obj->ray.dir_x;
	else
		obj->ray.raycast.perp_wall_dist = (obj->ray.raycast.map_y -
		obj->player.pos_y + (1 - obj->ray.raycast.step_y) / 2) / obj->ray.dir_y;
	obj->ray.raycast.lineh =
	(int)(obj->fill.r_two / obj->ray.raycast.perp_wall_dist);
	obj->ray.raycast.start =
	((-obj->ray.raycast.lineh / 2) + obj->fill.r_two / 2);
	if (obj->ray.raycast.start < 0)
		obj->ray.raycast.start = 0;
	obj->ray.raycast.end = (obj->ray.raycast.lineh / 2) + (obj->fill.r_two / 2);
	if (obj->ray.raycast.end >= obj->fill.r_two)
		obj->ray.raycast.end = obj->fill.r_two - 1;
}

void	fn_raycast_init_dir_r(t_vars *obj)
{
	if (obj->ray.dir_x < 0)
	{
		obj->ray.raycast.step_x = -1;
		obj->ray.raycast.side_dist_x = (obj->player.pos_x -
		obj->ray.raycast.map_x) * obj->ray.raycast.delta_dist_x;
	}
	else
	{
		obj->ray.raycast.step_x = 1;
		obj->ray.raycast.side_dist_x = (obj->ray.raycast.map_x +
		1.0 - obj->player.pos_x) * obj->ray.raycast.delta_dist_x;
	}
	if (obj->ray.dir_y < 0)
	{
		obj->ray.raycast.step_y = -1;
		obj->ray.raycast.side_dist_y = (obj->player.pos_y -
		obj->ray.raycast.map_y) * obj->ray.raycast.delta_dist_y;
	}
	else
	{
		obj->ray.raycast.step_y = 1;
		obj->ray.raycast.side_dist_y = (obj->ray.raycast.map_y +
		1.0 - obj->player.pos_y) * obj->ray.raycast.delta_dist_y;
	}
}

void	fn_raycast_init_hit(t_vars *obj)
{
	while (obj->ray.raycast.hit == 0)
	{
		if (obj->ray.raycast.side_dist_x < obj->ray.raycast.side_dist_y)
		{
			obj->ray.raycast.side_dist_x += obj->ray.raycast.delta_dist_x;
			obj->ray.raycast.map_x += obj->ray.raycast.step_x;
			obj->ray.raycast.side = 0;
		}
		else
		{
			obj->ray.raycast.side_dist_y += obj->ray.raycast.delta_dist_y;
			obj->ray.raycast.map_y += obj->ray.raycast.step_y;
			obj->ray.raycast.side = 1;
		}
		if (obj->fill.map[obj->ray.raycast.map_y]
		[obj->ray.raycast.map_x] == '1')
			obj->ray.raycast.hit = 1;
	}
}
