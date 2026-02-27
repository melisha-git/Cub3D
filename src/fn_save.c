/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_save.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melisha <melisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 19:00:00 by melisha           #+#    #+#             */
/*   Updated: 2021/01/27 15:16:30 by melisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	get_pixel_to_window(t_vars *obj, int fd)
{
	int	i;
	int	j;
	int	color;

	i = obj->fill.r_two;
	while (--i >= 0)
	{
		j = -1;
		while (++j < obj->fill.r_one)
		{
			color = *(int*)(obj->img.addr + (i * obj->img.line_length
					+ j * (obj->img.bits_per_pixel / 8)));
			write(fd, &color, 4);
		}
	}
}

void	fn_bi_inf(int fd, t_vars *obj)
{
	int		bytes_struct;
	int		zero;
	short	planes;
	int		bi_size;

	bytes_struct = 40;
	zero = 0;
	planes = 1;
	bi_size = obj->fill.r_one * obj->fill.r_two;
	write(fd, &bytes_struct, 4);
	write(fd, &obj->fill.r_one, 4);
	write(fd, &obj->fill.r_two, 4);
	write(fd, &planes, 2);
	planes = 32;
	write(fd, &planes, 2);
	write(fd, &zero, 4);
	write(fd, &bi_size, 4);
	bi_size = 1000;
	write(fd, &bi_size, 4);
	write(fd, &bi_size, 4);
	write(fd, &zero, 4);
	write(fd, &zero, 4);
}

void	fn_life_header(t_vars *obj, int fd)
{
	int		size;
	int		zero;
	int		bits;

	size = obj->fill.r_one * obj->fill.r_two * 4 + 54;
	zero = 0;
	bits = 54;
	write(fd, "BM", 2);
	write(fd, &size, 4);
	write(fd, &zero, 4);
	write(fd, &bits, 4);
}

void	fn_save(t_vars *obj)
{
	int		fd;

	fd = open("Screen Shot.bmp", O_CREAT | O_RDWR, 0666);
	if (fd == -1)
	{
		perror(NULL);
		exit(0);
	}
	fn_life_header(obj, fd);
	fn_bi_inf(fd, obj);
	get_pixel_to_window(obj, fd);
	close(fd);
}
