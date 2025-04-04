/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   festival_map.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/25 16:06:19 by livliege      #+#    #+#                 */
/*   Updated: 2025/04/04 12:39:00 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"


void parse_festival_map(t_game *data)
{
	size_t	i;
	size_t	j;

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
	"11111111123411111111",
	"10000000000000000001",
	"10000000000000000001",
	"1000000000N000000001",
	"10000000000000000001",
	"10000000000000000001",
	"10000300000000000001",
	"10000300000000000001",
	"10000300000000000001",
	"10000300000000000001",
	"10000300000000000001",
	"10000300000000000001",
	"10000300000000000001",
	"10000000000000000001",
	"10000000000000000001",
	"10000000000000000001",
	"10000000000000000001",
	"10000000000000000001",
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
			if (satoui(data->map->map[i][j]) > 0)
				printf("%c ", '#');
			else if (satoui(data->map->map[i][j]) == 0)
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

// void parse_player(t_game *data)
// {
// 	int x;
// 	int y;
// 	float offset;
	
// 	offset = GRIDSIZE / 2;
// 	y = 0;
// 	while (y < data->map->rows) 
// 	{
// 		x = 0;
// 		while (x < data->map->cols) 
// 		{
// 			if (!ft_isdigit(data->map->map[y][x])) 
// 			{
// 				if (data->map->map[y][x] == 'N') 
// 				{
// 					data->player.angle = DIR_NORTH;
// 					data->player.pos.x = (x * GRIDSIZE) + offset;
// 					data->player.pos.y = (y * GRIDSIZE) + offset;
// 				}
// 				if (data->map->map[y][x] == 'S')
// 				{
// 					data->player.angle = DIR_SOUTH;
// 					data->player.pos.x = (x * GRIDSIZE) + offset;
// 					data->player.pos.y = (y * GRIDSIZE) + offset;
// 				}
// 				if (data->map->map[y][x] == 'E') 
// 				{
// 					data->player.angle = DIR_EAST;
// 					data->player.pos.x = (x * GRIDSIZE) + offset;
// 					data->player.pos.y = (y * GRIDSIZE) + offset;
// 				}
// 				if (data->map->map[y][x] == 'W')
// 				{
// 					data->player.angle = DIR_WEST;
// 					data->player.pos.x = (x * GRIDSIZE) + offset;
// 					data->player.pos.y = (y * GRIDSIZE) + offset;
// 				}
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// 	data->player.dir.x = cos(data->player.angle);
// 	data->player.dir.y = sin(data->player.angle);
// 	data->player.wall_hit = false;
	
// 	printf("player pos.x	: %f\n", data->player.pos.x);  		//    === TAKEOUT ===
// 	printf("player pos.y	: %f\n", data->player.pos.y);  		//    === TAKEOUT ===
// 	printf("player dir.x	: %f\n", data->player.dir.x);  		//    === TAKEOUT ===
// 	printf("player dir.y	: %f\n", data->player.dir.y);  		//    === TAKEOUT ===
// 	printf("player angle	: %f\n", data->player.angle);  		//    === TAKEOUT ===
// }

void init_festival_wall_textures(t_festival_textures	*f_textures)
{
	f_textures->drink_shop_texture = mlx_load_png(f_textures->path_to_drink_shop);
	if (!f_textures->drink_shop_texture)
		error_and_exit("Loading drink shop png failed\n");
	f_textures->food_shop_texture = mlx_load_png(f_textures->path_to_food_shop);
	if (!f_textures->food_shop_texture)
		error_and_exit("Loading food shop png failed\n");
	f_textures->merch_shop_texture = mlx_load_png(f_textures->path_to_merch_shop);
	if (!f_textures->merch_shop_texture)
		error_and_exit("Loading merch shop png failed\n");
	f_textures->dixies_texture = mlx_load_png(f_textures->path_to_dixies);
	if (!f_textures->dixies_texture)
		error_and_exit("Loading dixies png failed\n");
	f_textures->wall_texture = mlx_load_png(f_textures->path_to_wall);
	if (!f_textures->wall_texture)
		error_and_exit("Loading wall png failed\n");
	f_textures->stage_texture = mlx_load_png(f_textures->path_to_stage);
	if (!f_textures->stage_texture)
		error_and_exit("Loading stage png failed\n");
}

void parse_festival_environment(t_game *data)
{
	data->ceiling_colour = COLOUR_AQUA;
	data->floor_colour = COLOUR_DARK_GREEN;
	// data->walls_colour = COLOUR_DARK_GRAY; // shadow

	data->festival_textures.path_to_drink_shop = "./textures/fun_wall.png";
	data->festival_textures.path_to_food_shop = "./textures/fun_wall.png";
	data->festival_textures.path_to_merch_shop = "./textures/fun_wall.png";
	data->festival_textures.path_to_dixies = "./textures/fun_wall.png";
	data->festival_textures.path_to_wall = "./textures/fun_wall.png";
	data->festival_textures.path_to_stage = "./textures/fun_wall.png";

	data->festival_map = true;
}


void	festival_parsing(t_game *data)
{
	printf("FESTIVAL MAP!\n");
	// parse_map(data);
	// parse_player(data);
	
	parse_festival_environment(data);
}
