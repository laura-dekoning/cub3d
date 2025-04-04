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

# include "cub3d.h"

void	init_border(t_game *data, t_mm_border *border)
{
	border->top_line_start.x = 0;
	border->top_line_start.y = 0;
	border->top_line_end.x = data->minimap_image->width + 2;
	border->top_line_end.y = data->minimap.border_size;
	border->bottom_line_start.x = 0;
	border->bottom_line_start.y = data->minimap_image->height + 2 - data->minimap.border_size;
	border->bottom_line_end.x = data->minimap_image->width + 2;
	border->bottom_line_end.y = data->minimap_image->height + 2;
	border->left_line_start.x = 0;
	border->left_line_start.y = 0;
	border->left_line_end.x = data->minimap.border_size;
	border->left_line_end.y = data->minimap_image->height + 2;
	border->right_line_start.x = data->minimap_image->width + 2 - data->minimap.border_size;
	border->right_line_start.y = 0;
	border->right_line_end.x = data->minimap_image->width + 2;
	border->right_line_end.y = data->minimap_image->height + 2;
	border->colour = data->minimap.border_colour;
}

void	draw_border(t_game *data, t_mm_border border)
{
	init_border(data, &border);
	draw_filled_rectangle(data->minimap_border_image, border.top_line_start, border.top_line_end, border.colour);
	draw_filled_rectangle(data->minimap_border_image, border.bottom_line_start, border.bottom_line_end, border.colour);
	draw_filled_rectangle(data->minimap_border_image, border.left_line_start, border.left_line_end, border.colour);
	draw_filled_rectangle(data->minimap_border_image, border.right_line_start, border.right_line_end, border.colour);
}

void	draw_minimap_background(t_game *data)
{
	t_vector_i start_pos;
	t_vector_i end_pos;
	
	start_pos.x = 0;
	start_pos.y = 0;
	end_pos.x = start_pos.x + data->minimap.minimap_size;
	end_pos.y = start_pos.y + data->minimap.minimap_size;
	draw_filled_rectangle(data->minimap_image, start_pos, end_pos, data->minimap.back_ground_colour);
}

static void init_player_map_pos(t_game *data, t_vector_i *player_map_pos)
{
	player_map_pos->x = data->player.pos.x / GRIDSIZE;	// center player in the minimap
	player_map_pos->y = data->player.pos.y / GRIDSIZE;
}

static void init_map_pos(t_vector_i	*map_pos, t_vector_i player_map_pos, int x, int y)
{
	map_pos->x = player_map_pos.x + (x - MINIMAP_GRID / 2); // map coordinates relative to player
	map_pos->y = player_map_pos.y + (y - MINIMAP_GRID / 2);
}

void	init_mimimap_grid(t_game *data, int map[MINIMAP_GRID][MINIMAP_GRID])
{
	int			x;
	int			y;
	t_vector_i	map_pos;
	t_vector_i	player_map_pos;

	init_player_map_pos(game, &player_map_pos);
	y = 0;
	while (y < MINIMAP_GRID)
	{
		x = 0;
		while (x < MINIMAP_GRID)
		{
			init_map_pos(&map_pos, player_map_pos, x, y);
			if (map_pos.y < 0 || map_pos.y >= data->map->rows || map_pos.x < 0 || map_pos.x >= data->map->cols)// check if map position is out of bounds
				map[y][x] = MM_NONE;
			else if (data->map->map[map_pos.y][map_pos.x] == '1')
				map[y][x] = MM_WALL;
			else
				map[y][x] = MM_FLOOR;
			x++;
		}
		y++;
	}
}

static void	set_colour(t_game *data, int map, uint64_t *colour)
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

void	draw_2D_map(t_game *data)
{
	int			x;
	int			y;
	int			map[MINIMAP_GRID][MINIMAP_GRID];
	uint64_t	colour;
	t_vector_i	start_pos;
	t_vector_i	end_pos;

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
