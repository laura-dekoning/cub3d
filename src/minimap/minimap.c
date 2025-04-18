/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minimap.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/15 20:25:33 by livliege      #+#    #+#                 */
/*   Updated: 2025/04/18 19:16:23 by livliege      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_minimap(t_game *game)
{
	game->minimap.grid_size = game->minimap.minimap_size / MINIMAP_GRID;
	game->minimap.player_size = game->minimap.grid_size / 1.5;
	game->minimap.player_pos.x = (MINIMAP_GRID / 2 + ((int)game->player->pos.x % GRIDSIZE) / (float)GRIDSIZE) * game->minimap.grid_size;
	game->minimap.player_pos.y = (MINIMAP_GRID / 2 + ((int)game->player->pos.y % GRIDSIZE) / (float)GRIDSIZE) * game->minimap.grid_size;
	game->minimap.back_ground_colour = COLOUR_BLACK;
	game->minimap.wall_colour = COLOUR_DARK_GRAY;
	game->minimap.floor_colour = COLOUR_GRAY;
	game->minimap.player_colour = COLOUR_YELLOW;
	game->minimap.ray_colour = COLOUR_LIGHT_BLUE;
	game->minimap.arrow_colour = COLOUR_DARK_BLUE;
	game->minimap.border_colour = COLOUR_DARK_PINK;
	game->minimap.border_size = 10;
}

void	minimap(t_game *game)
{
	init_minimap(game);
	draw_2d_map(game);
	draw_player(game);
	draw_border(game, game->minimap.border);
}
