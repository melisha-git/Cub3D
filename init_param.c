/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melisha <melisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 12:50:16 by melisha           #+#    #+#             */
/*   Updated: 2021/01/27 19:58:47 by melisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	fn_init_move(t_vars *obj)
{
	obj->flag.up = 0;
	obj->flag.down = 0;
	obj->flag.left = 0;
	obj->flag.right = 0;
	obj->flag.turn_l = 0;
	obj->flag.turn_r = 0;
}

void	fn_init_ray_and_player_param(t_vars *obj)
{
	obj->player.speed = 0.05;
	obj->ray.speed = 0.05;
	obj->player.dir_x = 0;
	obj->player.dir_y = 0;
	obj->ray.plane_x = 0;
	obj->ray.plane_y = 0;
	obj->player.life = 100;
}

char	*fn_init_vars_and_img_data_structs(t_vars *obj,
		t_img_data *img, int argc)
{
	int		max_w;
	int		max_h;

	if (!(obj->mlx = mlx_init()))
		return (NULL);
	fn_init_ray_and_player_param(obj);
	fn_init_move(obj);
	if (argc == 2)
	{
		mlx_get_screen_size(obj->mlx, &max_w, &max_h);
		obj->fill.r_one > max_w ? obj->fill.r_one = max_w : 0;
		obj->fill.r_two > max_h ? obj->fill.r_two = max_h : 0;
	}
	obj->win = mlx_new_window(obj->mlx, obj->fill.r_one,
				obj->fill.r_two, "cub3D");
	img->img = mlx_new_image(obj->mlx, obj->fill.r_one, obj->fill.r_two);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
				&img->line_length, &img->endian);
	obj->img = *img;
	return ("OK");
}
