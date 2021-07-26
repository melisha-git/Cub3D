/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melisha <melisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 14:31:08 by melisha           #+#    #+#             */
/*   Updated: 2021/01/27 22:30:06 by melisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		fn_pars_av(char *av)
{
	int		i;

	i = 0;
	if (av[i] != '-' || av[i + 1] != '-')
		return (-1);
	i += 2;
	if (av[i] != 's' || av[i + 1] != 'a' ||
		av[i + 2] != 'v' || av[i + 3] != 'e'
		|| av[i + 4] != '\0')
		return (-1);
	return (1);
}

void	fn_count_arg(t_vars obj, int argc, char **argv)
{
	if (argc == 2)
	{
		if (!(fn_raycasting(&obj)))
			fn_error("Error : unable to allocate memory \n");
		mlx_put_image_to_window(obj.mlx, obj.win, obj.img.img, 0, 0);
		system("afplay sound/hello.mp3 &");
		system("afplay sound/02567.mp3 &");
		mlx_hook(obj.win, 2, 0L, key_press, &obj);
		mlx_hook(obj.win, 3, 0L, key_release, &obj);
		mlx_hook(obj.win, 17, 0, but_hook, &obj);
		mlx_loop_hook(obj.mlx, key_hook, &obj);
		mlx_loop(obj.mlx);
	}
	else if (argc == 3)
	{
		if ((fn_pars_av(argv[2])) == -1)
		{
			fn_error("Error : not validate \n");
			exit(0);
		}
		if (!(fn_raycasting(&obj)))
			fn_error("Error : unable to allocate memory \n");
		fn_save(&obj);
	}
}

int		main(int argc, char **argv)
{
	t_img_data	img;
	t_vars		obj;

	obj.fill.file = argv[1];
	if (!(fn_parser(&obj)))
		fn_error("Error : not validate \n");
	if (!(fn_init_vars_and_img_data_structs(&obj, &img, argc)))
		return (fn_error("Is absent mlx"));
	fn_research_n(&obj);
	if (!(fn_count_sprites(&obj)))
		return (fn_error("Error : unable to allocate memory \n"));
	fn_count_arg(obj, argc, argv);
	return (0);
}
