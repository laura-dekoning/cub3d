/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minimap.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: livliege <livliege@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/15 20:25:33 by livliege      #+#    #+#                 */
/*   Updated: 2025/03/27 14:13:11 by livliege      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "../../incl/liath.h"


void	init_minimap(t_data *data)
{
	data->minimap.grid_size = data->minimap.minimap_size / MINIMAP_GRID;
	data->minimap.player_size = data->minimap.grid_size / 1.5;
	
	data->minimap.back_ground_colour = COLOUR_BLACK;
	data->minimap.wall_colour = COLOUR_DARK_GRAY;
	data->minimap.floor_colour = COLOUR_GRAY;
	
// good rays, but the player "walks" inside the gridspace its curently in
	data->minimap.player_pos.x  = (MINIMAP_GRID / 2 + ((int)data->player.pos.x % GRIDSIZE) / (float)GRIDSIZE) * data->minimap.grid_size;
	data->minimap.player_pos.y  = (MINIMAP_GRID / 2 + ((int)data->player.pos.y % GRIDSIZE) / (float)GRIDSIZE) * data->minimap.grid_size;
// player stays still in the gridspace its curently in but the rays are off
	// data->minimap.player_pos.x  = (MINIMAP_GRID / 2) * data->minimap.grid_size;
	// data->minimap.player_pos.y  = (MINIMAP_GRID / 2) * data->minimap.grid_size;

	data->minimap.player_colour = COLOUR_YELLOW;
	data->minimap.ray_colour = COLOUR_RED; 	// i you make this a colour with alpha turned off, the rays will look like they are shining trough the minimap hihi
	data->minimap.arrow_colour = COLOUR_GREEN; 
	
	data->minimap.border_size = 20;
	data->minimap.border_colour = COLOUR_YELLOW;
}


void	minimap(t_data *data)
{
	init_minimap(data);	
	draw_2D_map(data);
	draw_player(data);
	draw_border(data);
}



