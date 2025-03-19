/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_shapes.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: livliege <livliege@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/17 14:15:59 by livliege      #+#    #+#                 */
/*   Updated: 2025/03/17 14:15:59 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/liath.h"



// void	draw_filled_square(mlx_image_t *image, t_vector_f start_pos, uint32_t width, uint32_t height, uint64_t colour)
// {
// 	uint32_t	x;
// 	uint32_t	y;

// 	y = start_pos.y;
// 	while (y < start_pos.y + height)
// 	{
// 		x = start_pos.x;
// 		while (x < start_pos.x + width)
// 		{
// 			if (x < image->width && y < image->height)
// 				mlx_put_pixel(image, x, y, colour);
// 			x++;
// 		}
// 		y++;
// 	}
// }

// void draw_filled_circle(mlx_image_t	*image, t_vector_f centre, int radius, int colour) 
// {
// 	int x;
// 	int y;
	
// 	y = -radius;
// 	while (y <= radius) 
// 	{
// 		x = -radius;
// 		while (x <= radius) 
// 		{
// 			if ((centre.x + x >= 0 && centre.y + y >= 0 && centre.x + x < (int)image->width && centre.y + y < (int)image->height) && (x * x + y * y <= radius * radius))
// 			{
// 				mlx_put_pixel(image, centre.x + x, centre.y + y, colour);
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// }

// void draw_circle(mlx_image_t *image, t_vector_f centre, int radius, int colour)
// {
// 	int x;
// 	int y;
// 	double angle_step;
// 	double angle;

// 	angle_step = 1.0 / radius;
// 	angle = 0;

// 	while (angle < 2 * PI)
// 	{
// 		x = (int)(centre.x + cos(angle) * radius);
// 		y = (int)(centre.y + sin(angle) * radius);
// 		if (x >= 0 && y >= 0 && x < (int)image->width && y < (int)image->height)
// 		{
// 			mlx_put_pixel(image, x, y, colour);
// 		}
// 		angle += angle_step;
// 	}
// }


void	draw_line(mlx_image_t *image, t_vector_f start, t_vector_f end, uint64_t colour)
{
	float	step_x;
	float	step_y;
	float	max;

	//get total length
	step_x = end.x - start.x;
	step_y = end.y - start.y;
	//get amount of steps
	max = get_max(fabsf(step_x), fabsf(step_y));	// fabsf() returns the absolute value of a float
	// get step length for x and y
	step_x /= max;
	step_y /= max;
	// compare ints because floats are unreliable
	while ((int)(start.x - end.x) || (int)(start.y - end.y))
	{
		if (start.x >= 0 && start.y >= 0 && start.x < (int)image->width && start.y < (int)image->height)
			mlx_put_pixel(image, start.x, start.y, colour);
		start.x += step_x;
		start.y += step_y;
	}
}

void	fill_canvas(t_data *data)
{
	uint32_t	x;
	uint32_t	y;

	y = 0;
	while (y < data->window_image->height)
	{
		x = 0;
		while (x < data->window_image->width)
		{
			mlx_put_pixel(data->window_image, x, y, COLOUR_GRAY);
			x++;
		}
		y++;
	}
}
