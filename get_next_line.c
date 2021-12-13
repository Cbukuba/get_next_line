/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbukuba <cbukuba@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:17:45 by cbukuba           #+#    #+#             */
/*   Updated: 2021/12/13 22:48:52 by cbukuba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*-define BUFFER_SIZE =xx dans le Makefile
  -lire jusque '\n'*/

//#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	//size_t	i;
	size_t	ret;
	if (fd == -1)
		return (NULL);
	ret = read (fd, buf, BUFFER_SIZE);
	buf[ret] = '\0';
	return (buf);
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