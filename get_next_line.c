/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbukuba <cbukuba@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:17:45 by cbukuba           #+#    #+#             */
/*   Updated: 2021/12/24 15:05:07 by cbukuba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

// int	count_line(char *str)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (*str && str[i])
// 	{
// 		if (str[i] == '\n')
// 			j ++;
// 		i ++;
// 	}
// 	return (j);
// }

char	*get_next_line(int fd)
{
	char			buf[BUFFER_SIZE + 1];
	int				ret;
	static char		*str ="";
	char			**box;
	static int		i = -1;
	// int				line_count = 0;

	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = 0;
		str = ft_strjoin(str, buf);
		if (ft_strchr(str, '\n'))
			break;
	}
	// line_count = count_line(str);
	// printf("%d", line_count);
	box = ft_split(str, '\n');
	// if (i < line_count)
	i ++;
	return (box[i]);
}

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
// int main()
// {
// 	int fd;
// 	fd = open("text.txt", O_RDONLY);
// 	printf("%s\n", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// }
int main()
{
    int fd;
    char *line;
    fd = open("text", O_RDONLY);

    while (line != NULL)
    {
        line = get_next_line(fd);
        printf("--- FINAL LINE = %s\n", line);
    }
    return (0);
}