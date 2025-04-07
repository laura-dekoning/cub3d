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

void	init_border(t_game *game, t_mm_border *border)
{
	border->top_line_start.x = 0;
	border->top_line_start.y = 0;
	border->top_line_end.x = game->minimap_image->width + 2;
	border->top_line_end.y = game->minimap.border_size;
	border->bottom_line_start.x = 0;
	border->bottom_line_start.y = game->minimap_image->height + 2 - game->minimap.border_size;
	border->bottom_line_end.x = game->minimap_image->width + 2;
	border->bottom_line_end.y = game->minimap_image->height + 2;
	border->left_line_start.x = 0;
	border->left_line_start.y = 0;
	border->left_line_end.x = game->minimap.border_size;
	border->left_line_end.y = game->minimap_image->height + 2;
	border->right_line_start.x = game->minimap_image->width + 2 - game->minimap.border_size;
	border->right_line_start.y = 0;
	border->right_line_end.x = game->minimap_image->width + 2;
	border->right_line_end.y = game->minimap_image->height + 2;
	border->colour = game->minimap.border_colour;
}

void	draw_border(t_game *game, t_mm_border border)
{
	init_border(game, &border);
	draw_filled_rectangle(game->minimap_border_image, border.top_line_start, border.top_line_end, border.colour);
	draw_filled_rectangle(game->minimap_border_image, border.bottom_line_start, border.bottom_line_end, border.colour);
	draw_filled_rectangle(game->minimap_border_image, border.left_line_start, border.left_line_end, border.colour);
	draw_filled_rectangle(game->minimap_border_image, border.right_line_start, border.right_line_end, border.colour);
}

void	draw_minimap_background(t_game *game)
{
	t_vector_s start_pos;
	t_vector_s end_pos;
	
	start_pos.x = 0;
	start_pos.y = 0;
	end_pos.x = start_pos.x + game->minimap.minimap_size;
	end_pos.y = start_pos.y + game->minimap.minimap_size;
	draw_filled_rectangle(game->minimap_image, start_pos, end_pos, game->minimap.back_ground_colour);
}

static void init_player_map_pos(t_game *game, t_vector_s *player_map_pos)
{
	player_map_pos->x = game->player->pos.x / GRIDSIZE;	// center player in the minimap
	player_map_pos->y = game->player->pos.y / GRIDSIZE;
}

static void init_map_pos(t_vector_s	*map_pos, t_vector_s player_map_pos, int x, int y)
{
	map_pos->x = player_map_pos.x + (x - MINIMAP_GRID / 2); // map coordinates relative to player
	map_pos->y = player_map_pos.y + (y - MINIMAP_GRID / 2);
}

void	init_mimimap_grid(t_game *game, int map[MINIMAP_GRID][MINIMAP_GRID])
{
	int			x;
	int			y;
	t_vector_s	map_pos;
	t_vector_s	player_map_pos;

	init_player_map_pos(game, &player_map_pos);
	y = 0;
	while (y < MINIMAP_GRID)
	{
		x = 0;
		while (x < MINIMAP_GRID)
		{
			init_map_pos(&map_pos, player_map_pos, x, y);
			if (map_pos.y < 0 || map_pos.y >= game->map->rows || map_pos.x < 0 || map_pos.x >= game->map->cols)// check if map position is out of bounds
				map[y][x] = MM_NONE;
			else if (game->map->map[map_pos.y][map_pos.x] == '1')
				map[y][x] = MM_WALL;
			else
				map[y][x] = MM_FLOOR;
			x++;
		}
		y++;
	}
}

static void	set_colour(t_game *game, int map, uint64_t *colour)
{

	if (map == MM_WALL)
	{	
		*colour = game->minimap.wall_colour;
	}
	else if (map == MM_FLOOR)
	{	
		*colour = game->minimap.floor_colour;
	}
	else // if (map == MM_NONE)
	{	
		*colour = game->minimap.back_ground_colour;
	}
}

void	draw_2D_map(t_game *game)
{
	int			x;
	int			y;
	int			map[MINIMAP_GRID][MINIMAP_GRID];
	uint64_t	colour;
	t_vector_s	start_pos;
	t_vector_s	end_pos;

	init_mimimap_grid(game, map);
	draw_minimap_background(game);
	y = 0;
	while (y < MINIMAP_GRID)
	{
		x = 0;
		while (x < MINIMAP_GRID)
		{
			start_pos.x = x * game->minimap.grid_size; //	(to draw minimap with gridlines (skips a pixel every row and col))
			start_pos.y = y * game->minimap.grid_size; //	(but this causes problems with the rays) (i can do it later on top of the map if i want to)
			end_pos.x = start_pos.x + game->minimap.grid_size;
			end_pos.y = start_pos.y + game->minimap.grid_size;
			set_colour(game, map[y][x], &colour);
			draw_filled_rectangle(game->minimap_image, start_pos, end_pos, colour);
			x++;
		}
		y++;
	}
}
