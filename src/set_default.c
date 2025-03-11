
#include "cub3d.h"

void	set_default(t_data *data)
{
	data->north_texture = ft_strdup(DEF_NORTH);
	data->south_texture = ft_strdup(DEF_SOUTH);
	data->east_texture = ft_strdup(DEF_EAST);
	data->west_texture = ft_strdup(DEF_WEST);
	data->floor = string_to_rgb(DEF_FLOOR);
	data->ceiling = string_to_rgb(DEF_CEILING);
	data->map = ft_split(DEF_MAP, '\n');
	data->player->x = 5;
	data->player->y = 2;
	data->player->dir = SOUTH;
}
