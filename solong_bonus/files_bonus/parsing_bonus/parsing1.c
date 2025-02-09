#include "../../so_long_bonus.h"

int check_param(char* str)
{
    int c = ft_strlen(str);

    if(c < 4 || ft_strcmp(&str[c - 4], ".ber") != 0)
        return 0;
    return 1;
}

void	increment(char ch, int *e, int *p, int *c, int *h)
{
	if (ch == 'E')
		(*e)++;
	else if (ch == 'P')
		(*p)++;
	else if (ch == 'C')
		(*c)++;
    else if(ch == 'H')
        h++;
}

int check_map(char* str)
{
    int i;
    int e;
    int p;
    int c;
    int h;

    1 && (i = 0, e = 0, p = 0, c = 0, h = 0);
    while (str[i])
    {
        if(str[i] == 'E' || str[i] == '\n' || str[i] == 'P' || str[i] == 'C' || str[i] == '0' || str[i] == '1' || str[i] == 'H')
        {
            if((str[i] == '\n' && str[i + 1] == '\n') || ((i == 0 || str[i + 1] == '\0') && str[i] == '\n'))
                return 0;
            increment(str[i], &e, &p, &c, &h);
        }
        else
            return 0;
        i++;
    }
    if(e != 1 || p != 1 || c < 1 || h < 1)
        return 0;
    return 1;
}

int check_len(char** str)
{
    int i;

    i = 0;
    while(str[i + 1]){
        if(ft_strlen(str[i]) != ft_strlen(str[i + 1]) || ft_strlen(str[i]) > 60)
            return 0;
        i++;
    }
    if(i > 31)
        return 0;
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