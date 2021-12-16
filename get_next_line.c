/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbukuba <cbukuba@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:17:45 by cbukuba           #+#    #+#             */
/*   Updated: 2021/12/16 04:01:37 by cbukuba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			buf[BUFFER_SIZE + 1];
	int				ret;
	char			*temp;
	static char		*str = NULL;

	if (fd < 0)
		return (NULL);
	while (ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
			return (NULL);
		buf[ret] = '\0';
		temp = str;
		str = ft_strjoin(temp, buf);
		free (temp);
		if (ft_strchr(str, '\n'))
			break;
	}
	// ft_strtrim(str, '\n');
	return (str);
}

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
int main()
{
	int fd = open("text.txt", O_RDONLY);
	char *str = get_next_line(fd);
	printf("%s", str);
}