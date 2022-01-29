/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbukuba <cbukuba@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:17:45 by cbukuba           #+#    #+#             */
/*   Updated: 2022/01/29 14:36:59 by cbukuba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*next_line(char *str)
{
	char	*next_line;
	int		i;

	i = 0;
	while (!(ft_strchr(str, '\n')) && str[i])
		i ++;
	next_line = ft_substr(str, i, ft_strlen(str) - i);
	return (next_line);
}

char	*get_next_line(int fd)
{
	char			buf[BUFFER_SIZE + 1];
	int				ret;
	char			*line;
	static char		*str = "";

	ret = 1;
	if (fd < 0)
		return (NULL);
	while (ret > 0)
	{
		ret = read(fd, buf, 1);
		if (ret == -1)
		{
			return (NULL);
		}
		buf[ret] = 0;
		if (ft_strchr(str, '\n'))
			break;
		str = ft_strjoin(str, buf);
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

	while (line)
	 {
		line = get_next_line(fd);
		printf("%s", line);
	 }
	return 0;
}
