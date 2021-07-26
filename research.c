/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   research.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melisha <melisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 13:45:23 by melisha           #+#    #+#             */
/*   Updated: 2021/01/26 06:23:31 by melisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		fn_fill_sprite_arr_str(t_vars *obj, int len, int j)
{
	int		i;

	i = 0;
	while (obj->fill.map[j][i])
	{
		if (obj->fill.map[j][i] == '2')
		{
			obj->texture.sprite.sprite_x[len] = j;
			obj->texture.sprite.sprite_y[len] = i;
			len++;
		}
		i++;
	}
	return (len);
}

char	*fn_fill_sprite_arr(t_vars *obj, int len)
{
	int		i;
	int		j;

	if (!(obj->texture.sprite.sprite_x = (int *)malloc(sizeof(int) * (len))))
		return (NULL);
	if (!(obj->texture.sprite.sprite_y = (int *)malloc(sizeof(int) * (len))))
		return (NULL);
	j = 0;
	len = 0;
	while (obj->fill.map[j])
	{
		i = 0;
		len = fn_fill_sprite_arr_str(obj, len, j);
		j++;
	}
	obj->texture.sprite.len = len;
	if (!(obj->ray.raycast.perpbuffer =
	(double *)malloc(sizeof(double) * obj->fill.r_one)))
		return (NULL);
	return ("OK");
}

char	*fn_count_sprites(t_vars *obj)
{
	int		i;
	int		j;
	int		len;

	j = 0;
	len = 0;
	while (obj->fill.map[j])
	{
		i = 0;
		while (obj->fill.map[j][i])
		{
			if (obj->fill.map[j][i] == '2')
				len++;
			i++;
		}
		j++;
	}
	return (fn_fill_sprite_arr(obj, len));
}

void	fn_init_cordinate_player(t_vars *obj)
{
	if (obj->fill.map[(int)obj->player.pos_y][(int)obj->player.pos_x] == 'N')
	{
		obj->player.dir_y = -1;
		obj->ray.plane_x = 0.66;
	}
	else if (obj->fill.map[(int)obj->player.pos_y]
	[(int)obj->player.pos_x] == 'S')
	{
		obj->player.dir_y = 1;
		obj->ray.plane_x = -0.66;
	}
	else if (obj->fill.map[(int)obj->player.pos_y]
	[(int)obj->player.pos_x] == 'W')
	{
		obj->player.dir_x = -1;
		obj->ray.plane_y = -0.66;
	}
	else if (obj->fill.map[(int)obj->player.pos_y]
	[(int)obj->player.pos_x] == 'E')
	{
		obj->player.dir_x = 1;
		obj->ray.plane_y = 0.66;
	}
}

int		fn_research_n(t_vars *obj)
{
	int		i;
	int		j;

	j = 0;
	while (obj->fill.map[j])
	{
		i = 0;
		while (obj->fill.map[j][i])
		{
			if (obj->fill.map[j][i] == 'N' || obj->fill.map[j][i] == 'W'
			|| obj->fill.map[j][i] == 'S' || obj->fill.map[j][i] == 'E')
			{
				obj->player.pos_x = i;
				obj->player.pos_y = j;
				fn_init_cordinate_player(obj);
				obj->player.pos_x += 0.5;
				obj->player.pos_y += 0.5;
				obj->fill.map[j][i] = '0';
			}
			i++;
		}
		j++;
	}
	return (1);
}
