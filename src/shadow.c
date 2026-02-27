/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melisha <melisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:03:57 by melisha           #+#    #+#             */
/*   Updated: 2021/01/26 00:27:31 by melisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	fn_shadow(int *color, double distance, float shaider)
{
	if (distance > 20)
	{
		*color = 0;
		return ;
	}
	while (distance >= 0.3)
	{
		*color = ((*color >> 1) & 0x7f7f7f);
		distance -= shaider;
	}
}
