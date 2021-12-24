/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbukuba <cbukuba@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:17:45 by cbukuba           #+#    #+#             */
/*   Updated: 2021/12/24 15:21:51 by cbukuba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	count_line(char *str)
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

char	*get_next_line(int fd)
{
	char			buf[BUFFER_SIZE + 1];
	int				ret;
	static char		*str ="";
	char			**box;
	static int		i = -1;

	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = 0;
		str = ft_strjoin(str, buf);
		if (ft_strchr(str, '\n'))
			break;
	}
	box = ft_split(str, '\n');
	if (i <= count_line(str) + 1)
		i ++;
	else
		return (NULL);
	return (box[i]);
}

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
	int fd;
	fd = open("text.txt", O_RDONLY);
	char *line;
	// Pourquoi la boucle seule ne fonctionne pas?"
	line = get_next_line(fd);
	printf("%s\n", line);
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("%s\n", line);
	}
}