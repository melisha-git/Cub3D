/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melisha <melisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 22:53:17 by melisha           #+#    #+#             */
/*   Updated: 2021/01/27 15:12:25 by melisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	ft_wordcount(char const *s, char c)
{
	int		k;
	int		i;

	k = 0;
	i = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i] == c)
				i++;
			if (s[i])
				k++;
		}
		i++;
	}
	k = k + 1;
	return (k);
}

static int	ft_wordlen(char const *s, char c)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		i++;
	}
	return (i);
}

static char	**ft_cleaner(char **tmp)
{
	int		i;
	int		j;

	j = 0;
	while (*tmp[j++])
	{
		i = 0;
		while (tmp[j][i++])
			free(*tmp);
	}
	free(tmp);
	return (NULL);
}

char		**ft_split(char const *s, char c)
{
	char	**tmp;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!s)
		return (NULL);
	if (!(tmp = (char **)malloc((ft_wordcount(s, c) + 1) * sizeof(char *))))
		return (NULL);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (!s[i])
			break ;
		tmp[j] = ft_substr(&s[i], 0, ft_wordlen(&s[i], c));
		if (!tmp[j])
			return (ft_cleaner(tmp));
		while (s[i] && s[i] != c)
			i++;
		j++;
	}
	tmp[j] = 0;
	return (tmp);
}
