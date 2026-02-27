/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melisha <melisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 16:11:26 by melisha           #+#    #+#             */
/*   Updated: 2021/01/26 03:16:43 by melisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*s1;
	int				i;
	unsigned int	k;

	i = 0;
	if (!s)
		return (NULL);
	k = ft_strlen(s);
	if (len - start < k)
		s1 = (char *)malloc((len + 1) * sizeof(char));
	else
		s1 = (char *)malloc((k + 1) * sizeof(char));
	if (!s1)
		return (NULL);
	else
		while (start < k && len--)
			s1[i++] = s[start++];
	s1[i] = '\0';
	return (s1);
}
