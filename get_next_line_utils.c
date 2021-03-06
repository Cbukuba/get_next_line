#include "get_next_line.h"

size_t	ft_strlen(char const *str)
{
	int	c;

	c = 0;
	while (str[c] != '\0')
		c ++;
	return (c);
}

static	char	*ft_strcat(char *dest, char const *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i] != '\0')
		i ++;
	j = 0;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	return (dest);
}

char	*ft_strchr(char const *s, int c)
{
	int		i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return (str + i);
		i ++;
	}
	if (str[i] == (char)c)
		return (str + i);
	return (NULL);
}

static char	*str_link(char *str, char const *s1, char const *s2)
{
	int	i;
	int	lng1;
	int	lng2;

	lng1 = ft_strlen(s1);
	lng2 = ft_strlen(s2);
	i = 0;
	ft_strcat(str, s1);
	while (i < lng2)
	{
		str[lng1] = s2[i];
		lng1 ++;
		i ++;
	}
	str[lng1] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		lng1;
	int		lng2;

	if (!s1 || !s2)
		return (NULL);
	lng1 = ft_strlen(s1);
	lng2 = ft_strlen(s2);
	str = malloc(sizeof(char) * (lng1 + lng2 + 1));
	if (!str)
		return (0);
	*str = 0;
	str_link(str, s1, s2);
	return (str);
}

char	*ft_strdup(char const *s)
{
	int		i;
	int		lng;
	char	*p;

	if (!s)
		return (NULL);
	lng = 0;
	while (s[lng] != '\0')
		lng ++;
	p = (char *)malloc(sizeof(char) * lng + 1);
	if (!p)
		return (NULL);
	i = 0;
	while (i < lng)
	{
		p[i] = s[i];
		i ++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*str;
	size_t		p;

	i = 0;
	p = ft_strlen(s);
	if (p < start)
	{
		str = malloc(sizeof(char));
		if (!str)
			return (NULL);
		*str = '\0';
		return (str);
	}
	if (len > p)
		len = p;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}