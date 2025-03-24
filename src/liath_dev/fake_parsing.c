/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fake_parsing.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: livliege <livliege@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/07 16:40:29 by livliege      #+#    #+#                 */
/*   Updated: 2025/03/24 20:26:10 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/liath.h"

void parse_map(t_data *data)
{
	int i;
	int j;

	data->map = (t_map *)ft_calloc(sizeof(t_map), 1);
	if (data->map == NULL)
		error_and_exit("Malloc allocation failed\n");
// =================================
	data->map->rows = 20;   // y
	data->map->cols = 20;   // x
// =================================
	data->map->map_width_px = data->map->cols * GRIDSIZE;
	data->map->map_height_px = data->map->rows * GRIDSIZE;
	
	data->map->map = (char **)malloc(data->map->rows * sizeof(char *));
	if (data->map->map == NULL)
		error_and_exit("Malloc allocation failed\n");
	i = 0;
	while (i < data->map->rows) 
	{
		data->map->map[i] = malloc(data->map->cols * sizeof(char));
		if (data->map->map[i] == NULL)
			error_and_exit("Malloc allocation failed\n");
		i++;
	}
// =========== THE MAP ============	
	char temp_map[20][20] =
{
	"11111111111111111111",
	"10000001000000000001",
	"10000001000000000001",
	"10000001000000000001",
	"11111001111111110001",
	"10000000000000000001",
	"10000000000000000001",
	"10000000000000000001",
	"10011111111100000001",
	"10010000000000000001",
	"10010000000000000001",
	"10010000000100000001",
	"10010000000100000001",
	"100100000001000N0001",
	"10010000000100000001",
	"10010000000111111111",
	"10010000000000000001",
	"10010000000000000001",
	"10000000000000000001",
	"11111111111111111111"
};

// =================================
	i = 0;
	while (i < data->map->rows) 
	{
		j = 0;
		while (j < data->map->cols) 
		{
			data->map->map[i][j] = temp_map[i][j];
			//   === TAKEOUT ===
			if (data->map->map[i][j] == '1')
				printf("%c ", '#');
			else if (data->map->map[i][j] == '0')
				printf("%c ", ' ');
			else
				printf("%c ", data->map->map[i][j]);
			//   ===============
			j++;
		}
		printf("\n"); //   === TAKEOUT ===
		i++;
	}
}

void parse_player(t_data *data)
{
	int x;
	int y;
	float offset;
	
	offset = GRIDSIZE / 2;
	y = 0;
	while (y < data->map->rows) 
	{
		x = 0;
		while (x < data->map->cols) 
		{
			if (!ft_isdigit(data->map->map[y][x])) 
			{
				if (data->map->map[y][x] == 'N') 
				{
					data->player.angle = DIR_NORTH;
					data->player.pos.x = (x * GRIDSIZE) + offset;
					data->player.pos.y = (y * GRIDSIZE) + offset;
				}
				if (data->map->map[y][x] == 'S')
				{
					data->player.angle = DIR_SOUTH;
					data->player.pos.x = (x * GRIDSIZE) + offset;
					data->player.pos.y = (y * GRIDSIZE) + offset;
				}
				if (data->map->map[y][x] == 'E') 
				{
					data->player.angle = DIR_EAST;
					data->player.pos.x = (x * GRIDSIZE) + offset;
					data->player.pos.y = (y * GRIDSIZE) + offset;
				}
				if (data->map->map[y][x] == 'W')
				{
					data->player.angle = DIR_WEST;
					data->player.pos.x = (x * GRIDSIZE) + offset;
					data->player.pos.y = (y * GRIDSIZE) + offset;
				}
			}
			x++;
		}
		y++;
	}
	data->player.dir.x = cos(data->player.angle);
	data->player.dir.y = sin(data->player.angle);
	data->player.wall_hit = false;
	
	printf("player pos.x	: %f\n", data->player.pos.x);  		//    === TAKEOUT ===
	printf("player pos.y	: %f\n", data->player.pos.y);  		//    === TAKEOUT ===
	printf("player dir.x	: %f\n", data->player.dir.x);  		//    === TAKEOUT ===
	printf("player dir.y	: %f\n", data->player.dir.y);  		//    === TAKEOUT ===
	printf("player angle	: %f\n", data->player.angle);  		//    === TAKEOUT ===
}


void parse_environment(t_data *data)
{
	data->ceiling_colour = COLOUR_AQUA;
	data->floor_colour = COLOUR_DARK_GREEN;

	data->walls_colour = COLOUR_DARK_GRAY; // shadow
	
	data->textures.path_to_north_texture = "./textures/IMG_2709.png";
	data->textures.path_to_east_texture = "./textures/fun_wall.png";
	data->textures.path_to_south_texture = "./textures/IMG_5452.png";
	data->textures.path_to_west_texture = "./textures/fun_wall.png";
}



void fake_parsing(t_data *data)
{
	parse_map(data);
	parse_player(data);
	
	parse_environment(data);
	
}
