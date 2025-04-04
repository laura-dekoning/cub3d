/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minimap.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/15 20:25:33 by livliege      #+#    #+#                 */
/*   Updated: 2025/04/04 16:56:41 by livliege      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"


void	init_minimap(t_game *data)
{
	data->minimap.grid_size = data->minimap.minimap_size / MINIMAP_GRID;
	data->minimap.player_size = data->minimap.grid_size / 1.5;
	
// good rays, but the player "walks" inside the gridspace its curently in
	data->minimap.player_pos.x  = (MINIMAP_GRID / 2 + ((int)data->player->pos.x % GRIDSIZE) / (float)GRIDSIZE) * data->minimap.grid_size;
	data->minimap.player_pos.y  = (MINIMAP_GRID / 2 + ((int)data->player->pos.y % GRIDSIZE) / (float)GRIDSIZE) * data->minimap.grid_size;
// player stays still in the gridspace its curently in but the rays are off
	// data->minimap.player_pos.x  = (MINIMAP_GRID / 2) * data->minimap.grid_size;
	// data->minimap.player_pos.y  = (MINIMAP_GRID / 2) * data->minimap.grid_size;
	
	data->minimap.back_ground_colour = COLOUR_BLACK;
	data->minimap.wall_colour = COLOUR_DARK_GRAY;
	data->minimap.floor_colour = COLOUR_GRAY;

	data->minimap.player_colour = COLOUR_YELLOW;
	data->minimap.ray_colour = COLOUR_RED; 	// i you make this a colour with alpha turned off, the rays will look like they are shining trough the minimap hihi
	data->minimap.arrow_colour = COLOUR_GREEN; 

	data->minimap.border_colour = COLOUR_YELLOW;
	data->minimap.border_size = 20;
}

void	minimap(t_game *data)
{
	init_minimap(data);	
	draw_2D_map(data);
	draw_player(data);
	draw_border(data, data->minimap.border);
}
