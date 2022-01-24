/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbukuba <cbukuba@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:17:45 by cbukuba           #+#    #+#             */
/*   Updated: 2022/01/24 21:46:44 by cbukuba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*next_line(char *str)
{
	char	*next_line;
	int		i;
	// int		j;

	i = 0;
	// j = 0;
	while (!(ft_strchr(str, '\n')) && str[i])
		i ++;
	// next_line = malloc(sizeof(char) * ft_strlen(str) - i + 1);
	next_line = ft_substr(str, i, ft_strlen(str) - i);
	// if (!next_line)
	// 	return (NULL);
	// while (str[i])
	// 	next_line[j ++] = str[i ++];
	free (str);
	return (next_line);
}

char	*get_next_line(int fd)
{
	char			buf[BUFFER_SIZE + 1];
	int				ret;
	char			*line;
	static char		*str = "";
	int				i;

	i = 0;
	ret = 1;
	if (fd < 0)
		return (NULL);
	while (ret > 0)
	{
		ret = read(fd, buf, 1);
		if (ret == -1)
			return (NULL);
		buf[ret] = 0;
		str = ft_strjoin(str, buf);
		if (ft_strchr(str, '\n'))
			i ++;
		if (i == 2)
			break;
	}
	line = ft_strdup(str);
	str = next_line(str);
	return (line);
}

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
	int fd;
	fd = open("text.txt", O_RDONLY);
	char *line = "";

	// while (line != NULL)
	// {
		line = get_next_line(fd);
		printf("%s\n", line);
		line = get_next_line(fd);
		printf("%s", line);
	// }
	return 0;
}