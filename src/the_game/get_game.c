/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_game.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/04 14:34:34 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/04/07 15:33:43 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void parse_map(t_game *game, t_data *data)
{
	size_t	i;
	size_t	j;

	game->map->rows = data->map->rows;
	game->map->cols = data->map->cols;
	game->map->map_width_px = data->map->cols * GRIDSIZE;
	game->map->map_height_px = data->map->rows * GRIDSIZE;
	game->map->map = (char **)safe_calloc(game->map->rows * sizeof(char *));
	if (game->map->map == NULL)
		error_message(game, data, MALLOC, 3);
	i = 0;
	while (i < game->map->rows) 
	{
		game->map->map[i] = malloc(game->map->cols * sizeof(char));
		if (game->map->map[i] == NULL)
			error_message(game, data, MALLOC, 3);
		i++;
	}
	i = 0;
	while (i < game->map->rows) 
	{
		j = 0;
		while (j < game->map->cols) 
		{
			game->map->map[i][j] = data->map->map[i][j];
			//   === TAKEOUT ===
			// if (data->map->map[i][j] == '1')
			// 	printf("%c ", '#');
			// else if (data->map->map[i][j] == '0')
			// 	printf("%c ", ' ');
			// else
			// 	printf("%c ", data->map->map[i][j]);
			// //   ===============
			j++;
		}
		// printf("\n"); //   === TAKEOUT ===
		i++;
	}
}


void parse_player(t_game *game)
{
	size_t	x;
	size_t	y;
	float	offset;
	
	offset = GRIDSIZE / 2;
	y = 0;
	while (y < game->map->rows) 
	{
		x = 0;
		while (x < game->map->cols) 
		{
			if (!ft_isdigit(game->map->map[y][x])) 
			{
				if (game->map->map[y][x] == 'N') 
				{
					game->player->angle = DIR_NORTH;
					game->player->pos.x = (x * GRIDSIZE) + offset;
					game->player->pos.y = (y * GRIDSIZE) + offset;
				}
				if (game->map->map[y][x] == 'S')
				{
					game->player->angle = DIR_SOUTH;
					game->player->pos.x = (x * GRIDSIZE) + offset;
					game->player->pos.y = (y * GRIDSIZE) + offset;
				}
				if (game->map->map[y][x] == 'E') 
				{
					game->player->angle = DIR_EAST;
					game->player->pos.x = (x * GRIDSIZE) + offset;
					game->player->pos.y = (y * GRIDSIZE) + offset;
				}
				if (game->map->map[y][x] == 'W')
				{
					game->player->angle = DIR_WEST;
					game->player->pos.x = (x * GRIDSIZE) + offset;
					game->player->pos.y = (y * GRIDSIZE) + offset;
				}
			}
			x++;
		}
		y++;
	}
	game->player->dir.x = cos(game->player->angle);
	game->player->dir.y = sin(game->player->angle);
	game->player->wall_hit = false;
	
	printf("player pos.x	: %f\n", game->player->pos.x);  		//    === TAKEOUT ===
	printf("player pos.y	: %f\n", game->player->pos.y);  		//    === TAKEOUT ===
	printf("player dir.x	: %f\n", game->player->dir.x);  		//    === TAKEOUT ===
	printf("player dir.y	: %f\n", game->player->dir.y);  		//    === TAKEOUT ===
	printf("player angle	: %f\n", game->player->angle);  		//    === TAKEOUT ===
}


void	get_game(t_game *game, t_data * data)
{

	game->floor_colour = rgb_to_hex(data->floor[0], data->floor[1], data->floor[2]);
	game->ceiling_colour = rgb_to_hex(data->ceiling[0], data->ceiling[1], data->ceiling[2]);

	parse_map(game, data);
	parse_player(game);
	
	init_window(game);
	init_minimap_image(game);
	init_wall_textures(data, &game->textures);

	free_data(data);

	cub3d(game);
}
