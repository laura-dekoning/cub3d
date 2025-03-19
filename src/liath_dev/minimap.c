/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minimap.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: livliege <livliege@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/15 20:25:33 by livliege      #+#    #+#                 */
/*   Updated: 2025/03/19 22:36:28 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "../../incl/liath.h"

void	minimap(t_data *data)
{
	int x;
	int y;
	t_vector_i offset;
	t_vector_i minimap_offset;
	uint64_t colour;
	
	// minimap_offset.x = data->player.pos.x - MINIMAP_WIDTH / 2;
	// minimap_offset.y = data->player.pos.y - MINIMAP_HEIGHT / 2;
	
	draw_filled_square(data->minimap_image, (t_vector_i){0, 0}, MINIMAP_WIDTH, MINIMAP_HEIGHT, COLOUR_DARK_GRAY);

	y = 0;
	while (y < data->map->rows)
	{
		x = 0;
		while (x < data->map->cols)
		{
		// to draw minimap with gridlines (but this causes problems with the rays):
			// offset.x = (x * GRIDSIZE) + x;
			// offset.y = (y * GRIDSIZE) + y;
			offset.x = (x * GRIDSIZE); // - minimap_offset.x;
			offset.y = (y * GRIDSIZE); // - minimap_offset.y;

			// if (offset.x + GRIDSIZE > -GRIDSIZE && offset.y + GRIDSIZE > -GRIDSIZE && offset.x < MINIMAP_WIDTH + GRIDSIZE && offset.y < MINIMAP_HEIGHT + GRIDSIZE)
			if (offset.x + GRIDSIZE > 0 && offset.y + GRIDSIZE > 0 && offset.x < MINIMAP_WIDTH && offset.y < MINIMAP_HEIGHT)
			{
				if (data->map->map[y][x] == '1')
				{	
					colour = COLOUR_BLACK;
				}
				else
				{	
					colour = COLOUR_LIGHT_GRAY;
				}
				draw_filled_square(data->minimap_image, offset, GRIDSIZE, GRIDSIZE, colour);
			}
			x++;
		}
		y++;
	}
	// Draw border
	colour = COLOUR_WHITE;
	draw_filled_square(data->minimap_image, (t_vector_i){0, 0}, MINIMAP_WIDTH, 2, colour);
	draw_filled_square(data->minimap_image, (t_vector_i){0, MINIMAP_HEIGHT - 2}, MINIMAP_WIDTH, 2, colour);
	draw_filled_square(data->minimap_image, (t_vector_i){0, 0}, 2, MINIMAP_HEIGHT, colour);
	draw_filled_square(data->minimap_image, (t_vector_i){MINIMAP_WIDTH - 2, 0}, 2, MINIMAP_HEIGHT, colour);
}