#include"get_next_line.h"

char	*ft_strcpy(char	*dest, char	*src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	int		len2;
	int		i;
	int		len1;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	p = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i++ < len1)
		p[i - 1] = s1[i - 1];
	while (i++ < len1 + len2 + 1)
		p[i - 2] = s2[i - len1 - 2];
	p[len1 + len2] = '\0';
	free(s1);
	return (p);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return(0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	size_t			size;
	size_t			i;

	size = len;
	if (!(s))
		return (NULL);
	if (start >= ft_strlen(s) || s[0] == '\0')
		return (ft_strdup("\0"));
	if (len > ft_strlen(s))
		size = ft_strlen(s) - start;
	substr = (char *)malloc(size * sizeof(char) + 1);
	if (!(substr))
		return (0);
	i = 0;
	while (i < size)
	{
		substr[i] = (char)s[start];
		i++;
		start++;
	}
	substr[i] = '\0';
	return (substr);
}

char	*ft_strdup(char *s1)
{
	char	*s2;
	int		sz;

	sz = ft_strlen(s1);
	s2 = (char *)malloc(sz * sizeof (char) + 1);
	if (!(s2))
		return (0);
	ft_strcpy(s2, s1);
	s2[sz] = '\0';
	return (s2);
}
