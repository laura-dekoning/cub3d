/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_game.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/04 14:34:34 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/04/07 16:16:59 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_map(t_game *game, t_game *game)
{
	size_t	i;
	size_t	j;

	game->map->rows = game->map->rows;
	game->map->cols = game->map->cols;
	game->map->map_width_px = game->map->cols * GRIDSIZE;
	game->map->map_height_px = game->map->rows * GRIDSIZE;
	game->map->map = (char **)safe_calloc(game, game, game->map->rows, sizeof(char *));
	i = 0;
	while (i < game->map->rows) 
	{
		game->map->map[i] = ft_strdup(game->map->map[i]);
		if (game->map->map[i] == NULL)
			error_free_game_and_game(game, game, MALLOC);
		i++;
	}
}

void	parse_player(t_game *game, t_game *game)
{
	size_t	x;
	size_t	y;
	float	offset;
	
	offset = GRIDSIZE / 2;
	if (game->player->dir == NORTH)
		game->player->angle = DIR_NORTH;
	else if (game->player->dir == EAST)
		game->player->angle = DIR_EAST;
	else if (game->player->dir == SOUTH)
		game->player->angle = DIR_SOUTH;
	else if (game->player->dir == WEST)
		game->player->angle = DIR_WEST;
	game->player->pos.x = (game->player->x * GRIDSIZE) + offset;
	game->player->pos.y = (game->player->y * GRIDSIZE) + offset;
	game->player->dir.x = cos(game->player->angle);
	game->player->dir.y = sin(game->player->angle);
	game->player->wall_hit = false;
	
	printf("player pos.x	: %f\n", game->player->pos.x);  		//    === TAKEOUT ===
	printf("player pos.y	: %f\n", game->player->pos.y);  		//    === TAKEOUT ===
	printf("player dir.x	: %f\n", game->player->dir.x);  		//    === TAKEOUT ===
	printf("player dir.y	: %f\n", game->player->dir.y);  		//    === TAKEOUT ===
	printf("player angle	: %f\n", game->player->angle);  		//    === TAKEOUT ===
}

void	get_game(t_game *game, t_game * game)
{
	game->floor_colour = rgb_to_hex(game->floor[0], game->floor[1], game->floor[2]);
	game->ceiling_colour = rgb_to_hex(game->ceiling[0], game->ceiling[1], game->ceiling[2]);
	parse_map(game, game);
	parse_player(game, game);
	init_window(game);
	init_minimap_image(game);
	init_wall_textures(game, &game->textures);
	free_game(game);
}
