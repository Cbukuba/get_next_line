/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbukuba <cbukuba@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:17:45 by cbukuba           #+#    #+#             */
/*   Updated: 2022/01/21 03:16:29 by cbukuba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	count_line(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*str && str[i])
	{
		if (str[i] == '\n')
			j ++;
		i ++;
	}
	return (j);
}

static	char	**free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i ++;
	}
	free (tab);
}

char	*get_next_line(int fd)
{
	char			buf[BUFFER_SIZE + 1];
	int				ret;
	char			*line;
	static char		*str ="";

	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, buf, 1);
		str = ft_strjoin(str, buf);
		if (ft_strchr(str, '\n'))
			break;
		buf[ret] = 0;
	}
	if (str[ft_strlen(str)] == '\0')
		return (NULL);
	line = ft_strdup(str);
	str = str + (ft_strlen(str) + 1);
	return (line);
}

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
int main()
{
	int fd;
	fd = open("text.txt", O_RDONLY);
	char *line = "";

	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("%s\n", line);
	}
	return 0;
}