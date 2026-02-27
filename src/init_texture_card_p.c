/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture_card_p.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melisha <melisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 00:31:44 by melisha           #+#    #+#             */
/*   Updated: 2021/01/26 02:31:24 by melisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	*fn_init_no(t_vars *obj)
{
	if (!(obj->texture.img_text_no.img =
	mlx_xpm_file_to_image(obj->mlx, obj->fill.no,
	&obj->texture.t_width, &obj->texture.t_height)))
		return (NULL);
	if (!(obj->texture.img_text_no.addr =
	mlx_get_data_addr(obj->texture.img_text_no.img,
	&obj->texture.img_text_no.bits_per_pixel,
	&obj->texture.img_text_no.line_length,
	&obj->texture.img_text_no.endian)))
		return (NULL);
	return ("OK");
}

char	*fn_init_so(t_vars *obj)
{
	if (!(obj->texture.img_text_so.img =
	mlx_xpm_file_to_image(obj->mlx, obj->fill.so,
	&obj->texture.t_width, &obj->texture.t_height)))
		return (NULL);
	if (!(obj->texture.img_text_so.addr =
	mlx_get_data_addr(obj->texture.img_text_so.img,
	&obj->texture.img_text_so.bits_per_pixel,
	&obj->texture.img_text_so.line_length,
	&obj->texture.img_text_so.endian)))
		return (NULL);
	return ("OK");
}

char	*fn_init_we(t_vars *obj)
{
	if (!(obj->texture.img_text_we.img =
	mlx_xpm_file_to_image(obj->mlx, obj->fill.we,
	&obj->texture.t_width, &obj->texture.t_height)))
		return (NULL);
	if (!(obj->texture.img_text_we.addr =
	mlx_get_data_addr(obj->texture.img_text_we.img,
	&obj->texture.img_text_we.bits_per_pixel,
	&obj->texture.img_text_we.line_length,
	&obj->texture.img_text_we.endian)))
		return (NULL);
	return ("OK");
}

char	*fn_init_ea(t_vars *obj)
{
	if (!(obj->texture.img_text_ea.img =
	mlx_xpm_file_to_image(obj->mlx, obj->fill.ea,
	&obj->texture.t_width, &obj->texture.t_height)))
		return (NULL);
	if (!(obj->texture.img_text_ea.addr =
	mlx_get_data_addr(obj->texture.img_text_ea.img,
	&obj->texture.img_text_ea.bits_per_pixel,
	&obj->texture.img_text_ea.line_length,
	&obj->texture.img_text_ea.endian)))
		return (NULL);
	return ("OK");
}
