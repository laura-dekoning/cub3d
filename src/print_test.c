
#include "cub3d.h"


void	print_player(t_player *player)
{
	printf(B_P"Player:\n"DEF);
	printf("x = %i\ty = %i\n", player->x, player->y);
	if (player->dir == NORTH)
		printf("dir = north\n");
	else if (player->dir == SOUTH)
		printf("dir = south\n");
	else if (player->dir == EAST)
		printf("dir = east\n");
	else if (player->dir == WEST)
		printf("dir = west\n");
}

void	print_map(t_map *map)
{
	int	i;

	i = 0;
	printf(B_G"Map:\n"DEF);
	printf("rows\t: %i\tcols\t: %i\n", map->rows, map->cols);
	while (map->map[i] != '\0')
	{
		printf("%s", map->map[i]);
		i++;
	}
}
void	print_floor_and_ceiling(int *floor, int *ceiling)
{
	printf(B_W"Floor: "R"%i, "G"%i, "B"%i, \n"DEF, floor[0], floor[1], floor[2]);
	printf(B_W"Ceiling: "R"%i, "G"%i, "B"%i, \n"DEF, ceiling[0], ceiling[1], ceiling[2]);
}

void	print_data(t_data *data)
{
	printf(B_O"Data:\n"DEF);
	printf(G"North texture:"DEF" %s\n", data->north_texture);
	printf(Y"South texture:"DEF" %s\n", data->south_texture);
	printf(O"East texture:"DEF" %s\n", data->east_texture);
	printf(R"West texture:"DEF" %s\n", data->west_texture);
	print_floor_and_ceiling(data->floor, data->ceiling);
	print_map(data->map);
	print_player(data->player);
}
