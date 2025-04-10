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

#include "cub3d.h"

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
	t_vector_s	start_pos;
	t_vector_s	end_pos;

	start_pos.x = 0;
	start_pos.y = 0;
	end_pos.x = start_pos.x + game->minimap.minimap_size;
	end_pos.y = start_pos.y + game->minimap.minimap_size;
	draw_filled_rectangle(game->minimap_image, start_pos, end_pos, game->minimap.back_ground_colour);
}

void	draw_2d_map(t_game *game)
{
	t_vector_s	map_index;
	int			map[MINIMAP_GRID][MINIMAP_GRID];
	uint64_t	colour;
	t_vector_s	start_pos;
	t_vector_s	end_pos;

	init_mimimap_grid(game, map);
	draw_minimap_background(game);
	map_index.y = 0;
	while (map_index.y < MINIMAP_GRID)
	{
		map_index.x = 0;
		while (map_index.x < MINIMAP_GRID)
		{
			start_pos.x = map_index.x * game->minimap.grid_size;
			start_pos.y = map_index.y * game->minimap.grid_size;
			end_pos.x = start_pos.x + game->minimap.grid_size;
			end_pos.y = start_pos.y + game->minimap.grid_size;
			set_colour(game, map[map_index.y][map_index.x], &colour);
			draw_filled_rectangle(game->minimap_image, start_pos, end_pos, colour);
			map_index.x++;
		}
		map_index.y++;
	}
}
