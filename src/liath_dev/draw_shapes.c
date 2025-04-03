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


/*
* @param start_pos is the top left courner of the rectancle
* @param start_pos is the bottum right courner of the rectancle
*/
void	draw_filled_rectangle(mlx_image_t *image, t_vector_i start_pos, t_vector_i end_pos, uint64_t colour)
{
	uint32_t	x;
	uint32_t	y;

	y = start_pos.y;
	while (y < (uint32_t)(start_pos.y + end_pos.y))
	{
		x = start_pos.x;
		while (x < (uint32_t)(start_pos.x + end_pos.x))
		{
			if (x > 0 && y > 0 && x < image->width && y < image->height)
				mlx_put_pixel(image, x, y, colour);
			x++;
		}
		y++;
	}
}

void draw_filled_circle(mlx_image_t	*image, t_vector_f centre, int radius, int colour) 
{
	int x;
	int y;
	
	y = -radius;
	while (y <= radius) 
	{
		x = -radius;
		while (x <= radius) 
		{
			if ((centre.x + x >= 0 && centre.y + y >= 0 && centre.x + x < (int)image->width && centre.y + y < (int)image->height) && (x * x + y * y <= radius * radius))
			{
				mlx_put_pixel(image, centre.x + x, centre.y + y, colour);
			}
			x++;
		}
		y++;
	}
}

void draw_circle(mlx_image_t *image, t_vector_f centre, int radius, int colour)
{
	int x;
	int y;
	double angle_step;
	double angle;

	angle_step = 1.0 / radius;
	angle = 0;

	while (angle < 2 * PI)
	{
		x = (int)(centre.x + cos(angle) * radius);
		y = (int)(centre.y + sin(angle) * radius);
		if (x >= 0 && y >= 0 && x < (int)image->width && y < (int)image->height)
		{
			mlx_put_pixel(image, x, y, colour);
		}
		angle += angle_step;
	}
}


void	draw_line(mlx_image_t *image, t_vector_f start, t_vector_f end, uint64_t colour)
{
	float	step_x;
	float	step_y;
	float	max;

	//get total length
	step_x = end.x - start.x;
	step_y = end.y - start.y;
	//get amount of steps
	max = fmax(fabsf(step_x), fabsf(step_y));	// fabsf() returns the absolute value of a float
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

void	draw_ceiling_and_floor(t_data *data)
{
	t_vector_i	ceiling_start;
	t_vector_i	ceiling_end;
	t_vector_i	floor_start;
	t_vector_i	floor_end;
	uint32_t	c_col;
	uint32_t	f_col;

	c_col = data->ceiling_colour;
	f_col = data->floor_colour;

	ceiling_start.x = 0;
	ceiling_start.y = 0;
	ceiling_end.x = data->window_image->width;
	ceiling_end.y = data->window_image->height / 2;

	floor_start.x = 0;
	floor_start.y = data->window_image->height / 2;
	floor_end.x = data->window_image->width;
	floor_end.y = data->window_image->height;

	draw_filled_rectangle(data->window_image, ceiling_start, ceiling_end, c_col);
	draw_filled_rectangle(data->window_image, floor_start, floor_end, f_col);
}
