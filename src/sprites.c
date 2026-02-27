/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melisha <melisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 23:14:13 by melisha           #+#    #+#             */
/*   Updated: 2021/01/26 00:53:22 by melisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	*fn_sprite_distance(t_vars *obj)
{
	int		i;

	i = 0;
	if (!(obj->texture.sprite.distance =
	(float *)malloc(sizeof(float) * obj->texture.sprite.len)))
		return (NULL);
	while (i < obj->texture.sprite.len)
	{
		obj->texture.sprite.distance[i] =
		(pow(obj->player.pos_x - obj->texture.sprite.sprite_y[i], 2)
		+ pow(obj->player.pos_y - obj->texture.sprite.sprite_x[i], 2));
		i++;
	}
	return ("OK");
}

void	ft_swap(int *dist, int *dist2)
{
	float	swap;

	swap = *dist;
	*dist = *dist2;
	*dist2 = swap;
}

void	fn_sort_sprites(t_vars *obj)
{
	int		i;
	int		j;
	float	swap;

	i = 1;
	while (i < obj->texture.sprite.len)
	{
		j = i;
		while ((int)obj->texture.sprite.distance[j] >
		(int)obj->texture.sprite.distance[j - 1] && j != 0)
		{
			swap = obj->texture.sprite.distance[j];
			obj->texture.sprite.distance[j] =
			obj->texture.sprite.distance[j - 1];
			obj->texture.sprite.distance[j - 1] = swap;
			ft_swap(&obj->texture.sprite.sprite_x[j],
			&obj->texture.sprite.sprite_x[j - 1]);
			ft_swap(&obj->texture.sprite.sprite_y[j],
			&obj->texture.sprite.sprite_y[j - 1]);
			j -= 1;
		}
		i++;
	}
}

void	fn_paint_sprites(t_vars *obj)
{
	int		i;

	i = 0;
	fn_sort_sprites(obj);
	while (i < obj->texture.sprite.len)
	{
		init_pos_sprite(obj, i);
		fn_paint_sprite(obj, i);
		i++;
	}
}
