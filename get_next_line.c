/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbukuba <cbukuba@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:17:45 by cbukuba           #+#    #+#             */
/*   Updated: 2022/03/04 05:07:42 by cbukuba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*next_line(char *str)
{
	char	*next_line;
	int		i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i ++;
	if (str[i] == 0)
		return (NULL);
	next_line = ft_substr(str, i + 1, ft_strlen(str) - i);
	return (next_line);
}

static	char *first_line(char *str)
{
	int		i;
	char	*first_line;

	i = 0;
	if (!str)
		return (NULL);
	while (str && str[i] != '\n' && str[i])
		i ++;
	first_line = malloc(sizeof(char) * (i + 1));
	if (!first_line)
		return(NULL);
	// if (str[i] == '\0')
	// 	return (NULL);
	i = 0;
	while (str && str[i] && str[i] != '\n')
	{
		first_line[i] = str[i];
		i ++;
	}
	if (str[i] == '\n')
	{
		first_line[i] = str[i];
		i ++;
	}
	first_line[i] = 0;
	return (first_line);
}

char	*get_next_line(int fd)
{
	char			buf[BUFFER_SIZE + 1];
	int				ret;
	char			*line;
	static char		*str;
	
	if (fd < 0)
		return (NULL);
	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
			return (NULL);
		buf[ret] = 0;
		if (!str)
			str = ft_strdup("");
		str = ft_strjoin(buf, str);
		if (ft_strchr(str, '\n'))
			break;
	}
	line = first_line(str);
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
	char *line;

	line = ft_strdup("");
	while (line)
	 {
		line = get_next_line(fd);
		printf("%s", line);
	 }
	return 0;
}
