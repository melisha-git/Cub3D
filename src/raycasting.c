/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melisha <melisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 14:54:16 by melisha           #+#    #+#             */
/*   Updated: 2021/01/27 20:43:02 by melisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	*fn_raycasting(t_vars *obj)
{
	if (!(fn_init_texture(obj)))
		return (NULL);
	if (!(fn_init_sprites(obj)))
		return (NULL);
	if (!(fn_sprite_distance(obj)))
		return (NULL);
	fn_sort_sprites(obj);
	fn_paint_background(obj);
	fn_paint_sprites(obj);
	fn_paint_life(obj);
	free(obj->texture.sprite.distance);
	return ("OK");
}
