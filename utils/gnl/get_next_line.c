#include "../../so_long.h"

int	is_line(char *s)
{
	while (*s)
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}

char	*read_file(int fd, char *buffer)
{
	char	*fake_buffer;
	int		i;
	char	*temp;

	i = 1;
	while (i)
	{
		fake_buffer = ft_malloc((size_t)BUFFER_SIZE + 1);
		if (!fake_buffer)
			return (NULL);
		i = read(fd, fake_buffer, BUFFER_SIZE);
		if (i < 0)
			return (NULL);
		fake_buffer[i] = 0;
		temp = alloc_and_free(buffer, fake_buffer);
		if (!temp)
			return (NULL);
		buffer = ft_strdup(temp);
		if (!buffer)
			return (NULL);
		if (is_line(buffer))
			break ;
	}
	return (buffer);
}

char	*ft_get_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = ft_malloc(i + 1);
	if (!line)
		return (NULL);
	line[i] = 0;
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*ft_next_line(char *buffer)
{
	char	*new_buffer;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	if (ft_strlen(buffer) - i == 0)
		return (NULL);
	new_buffer = ft_malloc(ft_strlen(buffer) - i + 1);
	if (!new_buffer)
		return (NULL);
	j = 0;
	while (buffer[i])
		new_buffer[j++] = buffer[i++];
	new_buffer[j] = 0;
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (ft_malloc(-1), NULL);
	line = ft_get_line(buffer);
	buffer = ft_next_line(buffer);
	return (line);
}