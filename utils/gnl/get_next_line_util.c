#include "../../so_long.h"

char	*alloc_and_free(char *buffer, char *fake_buffer)
{
	char	*temp;

	temp = ft_strjoin(buffer, fake_buffer);
	if (!temp)
		return (NULL);
	return (temp);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dest;

	i = 0;
	while (s1[i])
		i++;
	dest = ft_malloc((i + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dest[i] = (char)(s1)[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*ptr;
	int		i;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2);
	ptr = ft_malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (*s1)
		ptr[i++] = *s1++;
	while (*s2)
		ptr[i++] = *s2++;
	ptr[i] = 0;
	return (ptr);
}