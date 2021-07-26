/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melisha <melisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 10:12:09 by melisha           #+#    #+#             */
/*   Updated: 2020/11/17 18:22:43 by melisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	int		i;
	int		j;
	int		sum;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	sum = (ft_strlen(s1) + ft_strlen(s2));
	if (!(s = (char *)malloc((sum + 1) * sizeof(char))))
		return (NULL);
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		s[i] = s2[j];
		j++;
		i++;
	}
	s[i] = '\0';
	return (s);
}

char		*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	i = 0;
	if (!(s2 = (char *)malloc(((ft_strlen(s1) + 1) * sizeof(char)))))
		return (NULL);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char		*ft_strchr(const char *str, int ch)
{
	int				i;
	char			*src;
	unsigned char	a;

	a = (unsigned char)ch;
	src = (char *)str;
	i = 0;
	while (src[i] != a)
	{
		if (src[i] == '\0')
			return (NULL);
		i++;
	}
	if (a == src[i])
		return (&src[i]);
	else
		return (NULL);
}

void		*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;
	size_t	csize;
	size_t	i;
	char	*sarr;

	i = 0;
	csize = size * nmemb;
	if (!(arr = malloc(csize)))
		return (NULL);
	sarr = (char *)arr;
	while (i < csize)
	{
		sarr[i] = '\0';
		i++;
	}
	return (arr);
}
