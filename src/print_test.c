/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_test.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/13 14:34:27 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/03/19 15:33:12 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_check(t_check *check)
{
	int	i;

	i = 0;
	printf(B_Y"Settings:\n"DEF);
	while (i < 7)
	{
		if (check->setting[i] == true)
			printf("Setting[%i] == true\n", i);
		else if (check->setting[i] == false)
			printf("Setting[%i] == false\n", i);
		i++;
	}
}

void	print_player(t_player *player)
{
	printf(B_P"Player:\n"DEF);
	printf("x = %i\ty = %i\n", player->x, player->y);
	if (player->dir == NORTH)
		printf("dir = north\n");
	else if (player->dir == EAST)
		printf("dir = east\n");
	else if (player->dir == SOUTH)
		printf("dir = south\n");
	else if (player->dir == WEST)
		printf("dir = west\n");
}

void	print_map(t_map *map)
{
	int	i;

	i = 0;
	printf(B_G"Map:\n"DEF);
	printf("rows\t: %zu\tcols\t: %zu\n", map->rows, map->cols);
	while (map->map[i] != NULL)
	{
		printf(B_W"%s\n"DEF, map->map[i]);
		i++;
	}
	print_array_with_values(map->map);
}

void	print_floor_and_ceiling(int *floor, int *ceiling)
{
	printf(B_W"Floor: "R"%i, "G"%i, "B"%i \n"DEF, floor[0], floor[1], floor[2]);
	printf(B_W"Ceiling: "R"%i, "G"%i, "B"%i \n"DEF, ceiling[0], ceiling[1], ceiling[2]);
}

void	print_array_with_values(char **map)
{
	int	x;
	int	y;

	x = 0;
	while (map[x] != NULL)
	{
		y = 0;
		while (map[x][y])
		{
			printf("|%c |", map[x][y]);
			y++;			
		}
		printf("\n");
		y = 0;
		while (map[x][y])
		{
			printf("|%i|", map[x][y]);
			y++;			
		}
		printf("\n");
		x++;
	}
}

void	print_string_with_values(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		while (str[i])
		{
			printf(B_G"|%c |", str[i]);
			i++;			
		}
		printf("\n");
		i = 0;
		while (str[i])
		{
			printf("|%i|", str[i]);
			i++;			
		}
		printf("\n"DEF);
	}
}

void	print_adjacent(char **map, int row, int col)
{
	int r = -1;
	int c;

	while (r <= 1)
	{
		c = -1;
		while (c <= 1)
		{
			printf("%c ", map[row + r][col + c]);
			c++;
		}
		printf("\n"); // Move to next line for square format
		r++;
	}
}

void	print_data(t_data *data)
{
	printf(B_O"Data:\n"DEF);
	printf(G"North texture:"DEF" [%s]\n", data->north_texture);
	printf(Y"East texture:"DEF" [%s]\n", data->east_texture);
	printf(O"South texture:"DEF" [%s]\n", data->south_texture);
	printf(R"West texture:"DEF" [%s]\n", data->west_texture);
	print_floor_and_ceiling(data->floor, data->ceiling);
	print_map(data->map);
	print_player(data->player);
	print_check(data->check);
}
