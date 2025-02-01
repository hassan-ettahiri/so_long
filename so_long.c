#include <unistd.h>
#include "so_long.h"

int check_param(char* str)
{
    int i = 0;

    while(str[i] && str[i] != '.')
        i++;
    if(!str[i] || ft_strcmp(&str[i], ".ber") != 0)
        return 0;
    return 1;
}
int check_map(char* str)
{
    int i;
    int e;
    int p;
    int c;

    i = 0;
    e = 0;
    p = 0;
    c = 0;
    while (str[i])
    {
        if(str[i] == 'E' || str[i] == '\n' || str[i] == 'P' || str[i] == 'C' || str[i] == '0' || str[i] == '1')
        {
            if((str[i] == '\n' && str[i + 1] == '\n') || ((i == 0 || str[i + 1] == '\0') && str[i] == '\n'))
                return 0;
            else if(str[i] == 'E')
                e++;
            else if(str[i] == 'P')
                p++;
            else if(str[i] == 'C')
                c++;
        }
        else
            return 0;
        i++;
    }
    if(e != 1 || p != 1 || c < 1)
        return 0;
    return 1;
}

int check_len(char** str)
{
    int i;

    i = 0;
    while(str[i + 1]){
        if(ft_strlen(str[i]) != ft_strlen(str[i + 1]))
            return 0;
        i++;
    }
    return 1;
}

int check_wall(char **map)
{
    int i;
    int j;

    i = 0;
    while(map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if((i == 0 || !map[i + 1]) && map[i][j] != '1')
                return 0;
            if((j == 0 || !map[i][j + 1]) && map[i][j] != '1')
                return 0;
            j++;
        } 
        i++;
    }
    return 1;
}

void find_player(char **map, int *x, int *y)
{
    int i;
    int j;

    i = 0;
    while(map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if(map[i][j] == 'P'){
                *y = i;
                *x = j;
            }
            j++;
        } 
        i++;
    }
}

void floodfill(char **map, int x, int y)
{
	if (map[y][x] == '0' || map[y][x] == 'E'
		|| map[y][x] == 'C' || map[y][x] == 'P')
	{
		if (map[y][x] == 'E')
		{
			map[y][x] = 'X';
			return ;
		}	
		map[y][x] = 'X';
	}
	else
		return ;
	floodfill(map, x - 1, y);
	floodfill(map, x + 1, y);
	floodfill(map, x, y - 1);
	floodfill(map, x, y + 1);
}

int check_road_is_correct(char **map)
{
    int i;
    int j;

    i = 0;
    while(map[i]){
        j = 0;
        while(map[i][j]){
            if(!(map[i][j] == 'X' || map[i][j] == '1' || map[i][j] == '0'))
                return 0;
            j++;
        }
        i++;
    }
    return 1;
}

int check_wall_and_floatfill(char *map)
{
    char **map2d;
    int x;
    int y;

    map2d = ft_split(map, '\n');
    if(!map2d || check_len(map2d) == 0 || check_wall(map2d) == 0)
        return 0;
    find_player(map2d, &x, &y);
    floodfill(map2d, x, y);
    if(check_road_is_correct(map2d) == 0)
        return 0;
    return 1;
}

int check_file_and_map(char* str, char ***map2d)
{
    int fd;
    char *line;
    char *map;

    map = NULL;
    fd = open(str, O_RDONLY);
    if(fd == -1)
        return 2;
    line = get_next_line(fd);
    if(!line)
        return 0;
    while(line)
    {
        map = ft_strjoin(map, line);
        line = get_next_line(fd);
    }
    if(check_map(map) == 0 || check_wall_and_floatfill(map) == 0)
        return 0;
    *map2d = ft_split(map, '\n');
    if(!(*map2d))
        return 0;
    return 1;
}
int main(int ac, char **av)
{
    char **map;

    if (ac != 2 || check_param(av[1]) == 0)
        return (write(1, "incorrect parameter\n", 21),ft_malloc(-1), 1);
    if(check_file_and_map(av[1], &map) == 0)
        return (write(1, "incorrect map\n", 15),ft_malloc(-1), 1);
    if(check_file_and_map(av[1], &map) == 2)
        return (write(1, "incorrect file\n", 16),ft_malloc(-1), 1);
    for(int i = 0;map[i];i++){
        for(int j = 0;map[i][j];j++){
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
    return (ft_malloc(-1), 0);
}
