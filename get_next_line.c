/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbukuba <cbukuba@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:17:45 by cbukuba           #+#    #+#             */
/*   Updated: 2022/01/24 17:16:20 by cbukuba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	char			buf[BUFFER_SIZE + 1];
	int				ret;
	char			*line;
	static char		*str = "";

	ret = 1;
	if (fd == -1)
		return (NULL);
	while (ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret < 0)
			return (NULL);
		buf[ret] = 0;
		str = ft_strjoin(str, buf);
		if (ft_strchr(str, '\n'))
			break;
	}
	line = ft_strdup(str);
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
		printf("%s\n", line);
	// }
	return 0;
}