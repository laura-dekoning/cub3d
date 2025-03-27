/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_minimap.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: livliege <livliege@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/24 16:08:48 by livliege      #+#    #+#                 */
/*   Updated: 2025/03/24 16:08:48 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#define MM_NONE		2
#define MM_WALL		1
#define MM_FLOOR	0

# include "../../incl/liath.h"

void	draw_border(t_data *data)
{
	t_vector_i	top_line_start;
	t_vector_i	top_line_end;
	t_vector_i	bottom_line_start;
	t_vector_i	bottom_line_end;
	t_vector_i	left_line_start;
	t_vector_i	left_line_end;
	t_vector_i	right_line_start;
	t_vector_i	right_line_end;
	uint64_t	colour;

	top_line_start.x = 0;
	top_line_start.y = 0;
	top_line_end.x = data->minimap_image->width + 2;
	top_line_end.y = data->minimap.border_size;
	bottom_line_start.x = 0;
	bottom_line_start.y = data->minimap_image->height + 2 - data->minimap.border_size;
	bottom_line_end.x = data->minimap_image->width + 2;
	bottom_line_end.y = data->minimap_image->height + 2;
	left_line_start.x = 0;
	left_line_start.y = 0;
	left_line_end.x = data->minimap.border_size;
	left_line_end.y = data->minimap_image->height + 2;
	right_line_start.x = data->minimap_image->width + 2 - data->minimap.border_size;
	right_line_start.y = 0;
	right_line_end.x = data->minimap_image->width + 2;
	right_line_end.y = data->minimap_image->height + 2;

	colour = data->minimap.border_colour;

	draw_filled_rectangle(data->minimap_border_image, top_line_start, top_line_end, colour);
	draw_filled_rectangle(data->minimap_border_image, bottom_line_start, bottom_line_end, colour);
	draw_filled_rectangle(data->minimap_border_image, left_line_start, left_line_end, colour);
	draw_filled_rectangle(data->minimap_border_image, right_line_start, right_line_end, colour);
}



void	draw_minimap_background(t_data *data)
{
	t_vector_i start_pos;
	t_vector_i end_pos;
	
	start_pos.x = 0;
	start_pos.y = 0;
	end_pos.x = start_pos.x + data->minimap.minimap_size;
	end_pos.y = start_pos.y + data->minimap.minimap_size;
	
	draw_filled_rectangle(data->minimap_image, start_pos, end_pos, data->minimap.back_ground_colour);
}
/*
plan:
- get location on the map of the player.
- draw x amount of wall or floor blocks around the player
- easy peasy 

- also data->minimap.grid_size moet waarschijnlijk afhangen van de size of the minimap en dat kan geen define zijn.


[ ][ ][ ][ ][ ]
[ ][ ][ ][ ][ ]
[ ][ ][X][ ][ ]
[ ][ ][ ][ ][ ]
[ ][ ][ ][ ][ ]


*/

void	init_mimimap_grid(t_data *data, int map[MINIMAP_GRID][MINIMAP_GRID])
{
	int x;
	int y;
	int map_x;
	int map_y;
	// char nbr[2];

	t_vector_i player_map_pos;

	// center player in the minimap
	player_map_pos.x = data->player.pos.x / GRIDSIZE;
	player_map_pos.y = data->player.pos.y / GRIDSIZE;
	y = 0;
	while (y < MINIMAP_GRID)
	{
		x = 0;
		while (x < MINIMAP_GRID)
		{
			// map coordinates relative to player
			map_x = player_map_pos.x + (x - MINIMAP_GRID / 2);
			map_y = player_map_pos.y + (y - MINIMAP_GRID / 2);
			// check if map position is out of bounds
			if (map_y < 0 || map_y >= data->map->rows || map_x < 0 || map_x >= data->map->cols)
				map[y][x] = MM_NONE;
			else if (data->map->map[map_y][map_x] == '1')
				map[y][x] = MM_WALL;
			else
				map[y][x] = MM_FLOOR;
			x++;
		}
		y++;
	}
}


static void	set_colour(t_data *data, int map, uint64_t *colour)
{

	if (map == MM_WALL)
	{	
		*colour = data->minimap.wall_colour;
	}
	else if (map == MM_FLOOR)
	{	
		*colour = data->minimap.floor_colour;
	}
	else // if (map == MM_NONE)
	{	
		*colour = data->minimap.back_ground_colour;
	}
}

void	draw_2D_map(t_data *data)
{
	int x;
	int y;
	int map[MINIMAP_GRID][MINIMAP_GRID];

	uint64_t colour;
	t_vector_i start_pos;
	t_vector_i end_pos;

	init_mimimap_grid(data, map);

	draw_minimap_background(data);

	y = 0;
	while (y < MINIMAP_GRID)
	{
		x = 0;
		while (x < MINIMAP_GRID)
		{
			start_pos.x = x * data->minimap.grid_size; //	(to draw minimap with gridlines (skips a pixel every row and col))
			start_pos.y = y * data->minimap.grid_size; //	(but this causes problems with the rays) (i can do it later on top of the map if i want to)
			end_pos.x = start_pos.x + data->minimap.grid_size;
			end_pos.y = start_pos.y + data->minimap.grid_size;

			set_colour(data, map[y][x], &colour);

			draw_filled_rectangle(data->minimap_image, start_pos, end_pos, colour);

			x++;
		}
		y++;
	}
}

