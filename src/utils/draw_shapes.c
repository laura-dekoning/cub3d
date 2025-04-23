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

#include "cub3d.h"

void	draw_filled_rectangle(mlx_image_t *image, t_vector_s start_pos, \
t_vector_s end_pos, uint64_t colour)
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

void	draw_filled_circle(mlx_image_t	*image, t_vector_f centre, \
int radius, int colour)
{
	int	x;
	int	y;

	y = -radius;
	while (y <= radius)
	{
		x = -radius;
		while (x <= radius)
		{
			if ((centre.x + x >= 0 && centre.y + y >= 0 && \
				centre.x + x < (int)image->width && \
				centre.y + y < (int)image->height) && \
				(x * x + y * y <= radius * radius))
			{
				mlx_put_pixel(image, centre.x + x, centre.y + y, colour);
			}
			x++;
		}
		y++;
	}
}

void	draw_circle(mlx_image_t *image, t_vector_f centre, \
int radius, int colour)
{
	int		x;
	int		y;
	double	angle_step;
	double	angle;

	angle_step = 1.0 / radius;
	angle = 0;
	while (angle < 2 * PI)
	{
		x = (int)(centre.x + cos(angle) * radius);
		y = (int)(centre.y + sin(angle) * radius);
		if (x >= 0 && y >= 0 && \
			x < (int)image->width && y < (int)image->height)
		{
			mlx_put_pixel(image, x, y, colour);
		}
		angle += angle_step;
	}
}

void	draw_line(mlx_image_t *image, t_vector_f start, \
t_vector_f end, uint64_t colour)
{
	float	step_x;
	float	step_y;
	float	max;

	step_x = end.x - start.x;
	step_y = end.y - start.y;
	max = fmax(fabsf(step_x), fabsf(step_y));
	step_x /= max;
	step_y /= max;
	while ((int)(start.x - end.x) || (int)(start.y - end.y))
	{
		if (start.x >= 0 && start.y >= 0 && \
			start.x < (int)image->width && start.y < (int)image->height)
			mlx_put_pixel(image, start.x, start.y, colour);
		start.x += step_x;
		start.y += step_y;
	}
}
