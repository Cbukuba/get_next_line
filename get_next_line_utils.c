#include "get_next_line.h"

size_t	ft_strlen(char const *str)
{
	int	c;

	c = 0;
	while (str[c] != '\0')
		c ++;
	return (c);
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

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (str[i])
		i ++;
	while (i >= 0)
	{
		if (str[i] == (char)c)
			return (str + i);
		i --;
	}
	return (NULL);
}

static	int	word_count(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			i ++;
		else
		{
			j ++;
			while (s[i] && s[i] != c)
				i ++;
		}
	}
	return (j);
}

static int	word_len(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] && s[i] == c)
		i ++;
	while (s[i] && s[i] != c)
	{
		i ++;
		len ++;
	}
	return (len);
}

static	char	**free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i ++;
	}
	free (tab);
	return (tab);
}

static	char	**make_tab(char **tab, char const *s, char c, int word_num)
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = 0;
	k = 0;
	while (s[i] && k < word_num)
	{
		j = 0;
		l = word_len(s, c, i);
		tab[k] = malloc(sizeof(char) * (l + 1));
		if (!tab)
			free_tab (tab);
		while (s[i] && s[i] == c)
			i ++;
		while (s[i] && s[i] != c)
			tab[k][j++] = s[i++];
		tab[k][j] = '\0';
		k ++;
	}
	tab[k] = 0;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab = NULL;
	int		len;

	len = word_count(s, c);
	tab = malloc(sizeof(char *) * (len + 1));
	if (!tab)
		return (NULL);
	make_tab(tab, s, c, len);
	return (tab);
	free(tab);
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
