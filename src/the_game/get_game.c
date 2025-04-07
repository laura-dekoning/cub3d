/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_game.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/04 14:34:34 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/04/07 15:54:33 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_map(t_game *game, t_data *data)
{
	size_t	i;
	size_t	j;

	game->map->rows = data->map->rows;
	game->map->cols = data->map->cols;
	game->map->map_width_px = data->map->cols * GRIDSIZE;
	game->map->map_height_px = data->map->rows * GRIDSIZE;
	game->map->map = (char **)safe_calloc(game, data, game->map->rows, sizeof(char *));
	i = 0;
	while (i < game->map->rows) 
	{
		game->map->map[i] = ft_strdup(data->map->map[i]);
		if (game->map->map[i] == NULL)
			error_free_game_and_data(game, data, MALLOC);
		i++;
	}
}

void	parse_player(t_game *game, t_data *data)
{
	size_t	x;
	size_t	y;
	float	offset;
	
	offset = GRIDSIZE / 2;
	if (data->player->dir == NORTH)
		game->player->angle = DIR_NORTH;
	else if (data->player->dir == EAST)
		game->player->angle = DIR_EAST;
	else if (data->player->dir == SOUTH)
		game->player->angle = DIR_SOUTH;
	else if (data->player->dir == WEST)
		game->player->angle = DIR_WEST;
	game->player->pos.x = (data->player->x * GRIDSIZE) + offset;
	game->player->pos.y = (data->player->y * GRIDSIZE) + offset;
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
	parse_player(game, data);

	init_window(game);
	init_minimap_image(game);
	init_wall_textures(data, &game->textures);
	free_data(data);
}
