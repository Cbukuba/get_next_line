/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbukuba <cbukuba@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:17:45 by cbukuba           #+#    #+#             */
/*   Updated: 2021/12/22 00:48:21 by cbukuba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	char			buf[BUFFER_SIZE + 1];
	int				ret = 1;
	char			*temp = "";
	static char		*str ="";
	char			*line = "";

	while (ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		printf("%d\n", ret);
		buf[ret] = 0;
		str = ft_strjoin(str, buf);
		if (ft_strchr(str, '\n'))
			break;
	}
	line = ft_strrchr(str, '\n');
	temp = str;
	str = ft_strchr(temp, '\n');
	free (temp);
	return (line);
}

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
	int fd;
	fd = open("text.txt", O_RDONLY);
	printf("%d\n", fd);
	printf("%s", get_next_line(fd));
}