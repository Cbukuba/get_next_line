/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbukuba <cbukuba@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:17:45 by cbukuba           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/01/21 03:16:29 by cbukuba          ###   ########.fr       */
=======
/*   Updated: 2022/01/24 17:16:20 by cbukuba          ###   ########.fr       */
>>>>>>> f12a2051b63f48c8e2362bad0c0a618e99048c43
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
<<<<<<< HEAD
		ret = read(fd, buf, 1);
=======
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret < 0)
			return (NULL);
		buf[ret] = 0;
>>>>>>> f12a2051b63f48c8e2362bad0c0a618e99048c43
		str = ft_strjoin(str, buf);
		if (ft_strchr(str, '\n'))
			break;
		buf[ret] = 0;
	}
<<<<<<< HEAD
	if (str[ft_strlen(str)] == '\0')
		return (NULL);
	line = ft_strdup(str);
	str = str + (ft_strlen(str) + 1);
=======
	line = ft_strdup(str);
>>>>>>> f12a2051b63f48c8e2362bad0c0a618e99048c43
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
<<<<<<< HEAD
	}
=======
		line = get_next_line(fd);
		printf("%s\n", line);
	// }
>>>>>>> f12a2051b63f48c8e2362bad0c0a618e99048c43
	return 0;
}