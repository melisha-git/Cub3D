/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_background.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melisha <melisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 18:28:17 by melisha           #+#    #+#             */
/*   Updated: 2021/01/27 20:26:27 by melisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	fn_raycast_vert_line(t_vars *obj, int x)
{
	int		y;
	int		color;

	y = 0;
	while (++y < (int)(obj->fill.r_two - 1))
	{
		if (y <= obj->ray.raycast.start)
		{
			color = fn_hex_color(obj->fill.c_r, obj->fill.c_g, obj->fill.c_b);
			my_mlx_pixel_put(&obj->img, x, y, color);
		}
		else if (y >= obj->ray.raycast.end)
		{
			color = fn_hex_color(obj->fill.f_r, obj->fill.f_g, obj->fill.f_b);
			fn_shadow(&color, (float)((float)obj->fill.r_two
			/ (float)y), 0.559);
			my_mlx_pixel_put(&obj->img, x, y, color);
		}
	}
}

void	fn_paint_background(t_vars *obj)
{
	int		color;
	int		x;
	int		y;

	x = 0;
	while (++x < (int)(obj->fill.r_one - 1))
	{
		fn_raycast_init_before(obj, x);
		fn_raycast_init_dir_r(obj);
		fn_raycast_init_hit(obj);
		fn_raycast_init_after(obj);
		fn_init_texpos(obj);
		obj->ray.raycast.perpbuffer[x] = obj->ray.raycast.perp_wall_dist;
		y = obj->ray.raycast.start - 1;
		while (++y < obj->ray.raycast.end)
		{
			obj->texture.tex_y =
			(int)obj->texture.texpos & (obj->texture.t_width - 1);
			obj->texture.texpos += obj->texture.step;
			color = fn_card_point(obj);
			fn_shadow(&color, obj->ray.raycast.perp_wall_dist, 2.1);
			my_mlx_pixel_put(&obj->img, x, y, color);
		}
		fn_raycast_vert_line(obj, x);
	}
}
