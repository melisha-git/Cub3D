/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_press_key.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melisha <melisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 12:57:13 by melisha           #+#    #+#             */
/*   Updated: 2021/01/27 22:34:25 by melisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		but_hook(int keycode)
{
	keycode = 3;
	system("killall afplay;afplay sound/vyjdi.mp3");
	exit(0);
	return (1);
}

int		key_press(int keycode, t_vars *obj)
{
	if (keycode == 53)
	{
		system("killall afplay;afplay sound/vyjdi.mp3");
		mlx_destroy_window(obj->mlx, obj->win);
		exit(1);
	}
	if (keycode == 13 || keycode == 126)
		obj->flag.up = 1;
	if (keycode == 1 || keycode == 125)
		obj->flag.down = 1;
	if (keycode == 0)
		obj->flag.left = 1;
	if (keycode == 2)
		obj->flag.right = 1;
	if (keycode == 124)
		obj->flag.turn_l = 1;
	if (keycode == 123)
		obj->flag.turn_r = 1;
	if (keycode == 48)
	{
		system("afplay sound/hit.mp3 &");
		obj->player.life = obj->player.life - 10;
	}
	return (1);
}

int		key_release(int keycode, t_vars *obj)
{
	if (keycode == 13 || keycode == 126)
		obj->flag.up = 0;
	if (keycode == 1 || keycode == 125)
		obj->flag.down = 0;
	if (keycode == 0)
		obj->flag.left = 0;
	if (keycode == 2)
		obj->flag.right = 0;
	if (keycode == 124)
		obj->flag.turn_l = 0;
	if (keycode == 123)
		obj->flag.turn_r = 0;
	return (1);
}

int		key_hook(t_vars *obj)
{
	if (obj->flag.up == 1)
		fn_move_up(obj);
	if (obj->flag.down == 1)
		fn_move_down(obj);
	if (obj->flag.turn_r == 1)
		fn_turn_r(obj);
	if (obj->flag.turn_l == 1)
		fn_turn_l(obj);
	if (obj->flag.right == 1)
		fn_move_right(obj);
	if (obj->flag.left == 1)
		fn_move_left(obj);
	mlx_destroy_image(obj->mlx, obj->img.img);
	obj->img.img = mlx_new_image(obj->mlx, obj->fill.r_one, obj->fill.r_two);
	obj->img.addr = mlx_get_data_addr(obj->img.img,
	&obj->img.bits_per_pixel, &obj->img.line_length, &obj->img.endian);
	if (!(fn_raycasting(obj)))
		fn_error("Error : unable to allocate memory \n");
	mlx_put_image_to_window(obj->mlx, obj->win, obj->img.img, 0, 0);
	fn_paint_life(obj);
	return (1);
}
