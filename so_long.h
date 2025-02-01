#ifndef SO_LONG_H
#define SO_LONG_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 7
# endif

typedef struct s_gb
{
	void		*ptr;
	struct s_gb	*next;
}t_gb;

size_t	ft_strlen(const char *s);
void	*ft_malloc(ssize_t len);

int ft_strcmp(const char *str1, const char *str2);
char	*ft_strjoin(char const *s1, char const *s2);
char	*alloc_and_free(char *buffer, char *fake_buffer);
char	*ft_strdup(const char *s1);
int		is_line(char *s);
char	*read_file(int fd, char *buffer);
char	*ft_get_line(char *buffer);
char	*ft_next_line(char *buffer);
char	*get_next_line(int fd);
char	**ft_split(char const *s, char c);

#endif