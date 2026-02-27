/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melisha <melisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 18:03:38 by melisha           #+#    #+#             */
/*   Updated: 2021/01/26 00:26:17 by melisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	fn_paint_vert_sprites(t_vars *obj, int x, int i)
{
	int		y;
	int		color;

	y = obj->texture.sprite.start_y - 1;
	while (++y < obj->texture.sprite.end_y)
	{
		obj->texture.sprite.tex_y = ((((y) * 256 -
		obj->fill.r_two * 128 + obj->texture.sprite.s_h * 128) * 64)
		/ obj->texture.sprite.s_h) / 256;
		color = texpixcolor(&obj->texture.sprite.img_sprites,
		obj->texture.sprite.tex_x, obj->texture.sprite.tex_y);
		fn_shadow(&color, obj->texture.sprite.distance[i], 2.1);
		if (texpixcolor(&obj->texture.sprite.img_sprites,
		obj->texture.sprite.tex_x, obj->texture.sprite.tex_y) != 0)
			my_mlx_pixel_put(&obj->img, x, y, color);
	}
}

void	fn_paint_sprite(t_vars *obj, int i)
{
	int		x;

	x = obj->texture.sprite.start_x - 1;
	while (++x < obj->texture.sprite.end_x)
	{
		obj->texture.sprite.tex_x = (int)(256 * (x - (-obj->texture.sprite.s_w /
		2 + obj->texture.sprite.sprite_screen)) * 64 / obj->texture.sprite.s_w)
		/ 256;
		if (obj->texture.sprite.transform_y > 0 && x > 0 &&
			x < (int)obj->fill.r_one &&
			obj->texture.sprite.transform_y < obj->ray.raycast.perpbuffer[x])
			fn_paint_vert_sprites(obj, x, i);
	}
}
