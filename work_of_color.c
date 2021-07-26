/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_of_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melisha <melisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 13:01:04 by melisha           #+#    #+#             */
/*   Updated: 2021/01/26 02:33:05 by melisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int				fn_hex_color(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

unsigned int	texpixcolor(t_img_data *img, int x, int y)
{
	char			*addr;
	unsigned int	color;

	addr = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	color = *(unsigned int*)addr;
	return (color);
}

int				fn_card_point(t_vars *obj)
{
	if (obj->ray.raycast.side == 0)
	{
		if (obj->ray.raycast.step_x > 0)
			return (texpixcolor(&obj->texture.img_text_we,
			obj->texture.tex_x, obj->texture.tex_y));
		else if (obj->ray.raycast.step_x < 0)
			return (texpixcolor(&obj->texture.img_text_ea,
			obj->texture.tex_x, obj->texture.tex_y));
	}
	else if (obj->ray.raycast.side == 1)
	{
		if (obj->ray.raycast.step_y < 0)
			return (texpixcolor(&obj->texture.img_text_no,
			obj->texture.tex_x, obj->texture.tex_y));
		else
			return (texpixcolor(&obj->texture.img_text_so,
			obj->texture.tex_x, obj->texture.tex_y));
	}
	return (0);
}

char			*fn_init_sprites(t_vars *obj)
{
	if (!(obj->texture.sprite.img_sprites.img =
	mlx_xpm_file_to_image(obj->mlx, obj->fill.s,
	&obj->texture.sprite.t_width, &obj->texture.sprite.t_height)))
		return (NULL);
	if (!(obj->texture.sprite.img_sprites.addr =
	mlx_get_data_addr(obj->texture.sprite.img_sprites.img,
	&obj->texture.sprite.img_sprites.bits_per_pixel,
	&obj->texture.sprite.img_sprites.line_length,
	&obj->texture.sprite.img_sprites.endian)))
		return (NULL);
	return ("OK");
}

char			*fn_init_texture(t_vars *obj)
{
	if (!(fn_init_no(obj)) ||
	!(fn_init_so(obj)) ||
	!(fn_init_we(obj)) ||
	!(fn_init_ea(obj)))
		return (NULL);
	return ("OK");
}
