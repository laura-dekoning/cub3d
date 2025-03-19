/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_canvas.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: livliege <livliege@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/19 18:16:22 by livliege      #+#    #+#                 */
/*   Updated: 2025/03/19 18:16:22 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/liath.h"


// void	draw_ceiling(t_data *data, uint32_t colour)
// {
// 	uint32_t	x;
// 	uint32_t	y;

// 	y = 0;
// 	while (y < data->window_image->height / 2)
// 	{
// 		x = 0;
// 		while (x < data->window_image->width)
// 		{
// 			mlx_put_pixel(data->window_image, x, y, colour);
// 			x++;
// 		}
// 		y++;
// 	}
// }
// void	draw_floor(t_data *data, uint32_t colour)
// {
// 	uint32_t	x;
// 	uint32_t	y;

// 	y = data->window_image->height / 2;
// 	while (y < data->window_image->height)
// 	{
// 		x = 0;
// 		while (x < data->window_image->width)
// 		{
// 			mlx_put_pixel(data->window_image, x, y, colour);
// 			x++;
// 		}
// 		y++;
// 	}
// }

void	fill_canvas(t_data *data)
{
	t_vector_i	floor_start;
	t_vector_i	ceiling_start;
	uint32_t	width;
	uint32_t	height;
	uint32_t	c_col;
	uint32_t	f_col;

	c_col = data->ceiling_colour;
	f_col = data->floor_colour;

	width = data->window_image->width;
	height = data->window_image->height / 2;

	ceiling_start.x = 0;
	ceiling_start.y = 0;
	floor_start.x = 0;
	floor_start.y = height;

	draw_filled_square(data->window_image, ceiling_start, width, height, c_col);
	draw_filled_square(data->window_image, floor_start, width, height, f_col);
}
