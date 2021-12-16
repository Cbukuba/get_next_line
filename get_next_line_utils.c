#include "get_next_line.h"

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

static int	find_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i ++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		start;
	int		len;

	start = 0;
	while (find_in_set(s1[start], set) && s1[start])
		start ++;
	len = ft_strlen(s1);
	while (find_in_set(s1[len - 1], set) && len > start)
		len --;
	str = malloc(sizeof(char) * (len - start + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (start < len)
		str[i ++] = s1[start ++];
	str[i] = '\0';
	return (str);
}