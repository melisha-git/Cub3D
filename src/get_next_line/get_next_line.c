/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melisha <melisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 18:04:10 by melisha           #+#    #+#             */
/*   Updated: 2021/01/26 03:52:41 by melisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_cleaner(char *line, char *buff)
{
	char	*leaks;

	leaks = line;
	if (!(line = ft_strjoin(line, buff)))
		return (NULL);
	free(leaks);
	return (line);
}

static int		free_buff(char *buff)
{
	if (buff)
		free(buff);
	return (-1);
}

static char		*ft_checker(char **cache, char **line)
{
	char	*p;
	char	*leak;

	p = NULL;
	if (*cache)
	{
		if ((p = ft_strchr(*cache, '\n')))
		{
			*p = '\0';
			*line = ft_strdup(*cache);
			leak = *cache;
			*cache = ft_strdup(++p);
			free(leak);
		}
		else
		{
			*line = ft_strdup(*cache);
			free(*cache);
			*cache = NULL;
		}
	}
	else
		*line = ft_strdup("");
	return (p);
}

int				get_next_line(int fd, char **line)
{
	char		*buff;
	int			j;
	char		*p;
	static char	*cache;

	if (!(buff = (char *)malloc((2)))
		|| !line || (read(fd, buff, 0) < 0))
		return (-1);
	p = ft_checker(&cache, line);
	while (!p && (j = read(fd, buff, 1)))
	{
		buff[j] = '\0';
		if ((p = ft_strchr(buff, '\n')))
		{
			*p = '\0';
			if (!(cache = ft_strdup(++p)))
				return (free_buff(buff));
		}
		if (!(*line = ft_cleaner(*line, buff)))
			return (free_buff(buff));
	}
	free(buff);
	return (p != NULL ? 1 : 0);
}
