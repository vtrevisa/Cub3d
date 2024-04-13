#include "../../include/cub3D.h"

char    *remove_lnbrk(t_data *data, char *str)
{
    char    *ret;
    int        i;
    int        j;

    i = 0;
    j = 0;
    ret = malloc (sizeof (char) * data->max_x);
    while (str[i])
    {
        if (str[i] != '\n')
        {
            ret[j] = str[i];
            j++;
            i++;
        }
        else
            i++;
    }
    return (ret);
}

int    map_reader(t_data *data)
{
    int        fd;
    char    *tmp;
    char    *map_name;
    int        l;

    l = 1;
    map_name = ft_strjoin ("./src/maps/", data->map_name);
    fd = open (map_name, O_RDONLY);
    if (fd < 0)
        return (map_error());
    data->blocks_nbr = get_quantity_blocks \
            (&data->map_size[0], & data->map_size[1], map_name);
    show_map_nbrs(data);
    free(map_name);
    tmp = get_next_line(fd);
    data->map = malloc(sizeof(char) * data->blocks_nbr);
    ft_bzero(data->map, data->blocks_nbr);
    while (tmp)
    {
        tmp = cat_map(data, tmp, fd, l);
        l++;
    }
    data->map_lined = remove_lnbrk(data, data->map);
    // show_map(data->map);
}
