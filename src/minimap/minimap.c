/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minimap.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/15 20:25:33 by livliege      #+#    #+#                 */
/*   Updated: 2025/04/07 16:15:52 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"


void	init_minimap(t_game *game)
{
	game->minimap.grid_size = game->minimap.minimap_size / MINIMAP_GRID;
	game->minimap.player_size = game->minimap.grid_size / 1.5;
	
// good rays, but the player "walks" inside the gridspace its curently in
	game->minimap.player_pos.x  = (MINIMAP_GRID / 2 + ((int)game->player->pos.x % GRIDSIZE) / (float)GRIDSIZE) * game->minimap.grid_size;
	game->minimap.player_pos.y  = (MINIMAP_GRID / 2 + ((int)game->player->pos.y % GRIDSIZE) / (float)GRIDSIZE) * game->minimap.grid_size;
// player stays still in the gridspace its curently in but the rays are off
	// game->minimap.player_pos.x  = (MINIMAP_GRID / 2) * game->minimap.grid_size;
	// game->minimap.player_pos.y  = (MINIMAP_GRID / 2) * game->minimap.grid_size;
	
	game->minimap.back_ground_colour = COLOUR_BLACK;
	game->minimap.wall_colour = COLOUR_DARK_GRAY;
	game->minimap.floor_colour = COLOUR_GRAY;

	game->minimap.player_colour = COLOUR_YELLOW;
	game->minimap.ray_colour = COLOUR_RED; 	// i you make this a colour with alpha turned off, the rays will look like they are shining trough the minimap hihi
	game->minimap.arrow_colour = COLOUR_GREEN; 

	game->minimap.border_colour = COLOUR_YELLOW;
	game->minimap.border_size = 20;
}

void	minimap(t_game *game)
{
	init_minimap(data);	
	draw_2D_map(data);
	draw_player(data);
	draw_border(data, game->minimap.border);
}
