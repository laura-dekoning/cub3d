/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_2D.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: livliege <livliege@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/17 14:15:33 by livliege      #+#    #+#                 */
/*   Updated: 2025/03/17 14:15:33 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/liath.h"

t_ray ray[NUMB_RAYS];
t_vector_f dir;
float angle;
float angle_step;
float fov;
int i;

fov = 60.0;
angle = data->player->angle - ((fov / 2) * ONE_DEGREE);
angle_step = (fov * ONE_DEGREE) / NUMB_RAYS;
i = 0;
while (i < NUMB_RAYS)
{
	dir.x = cos(angle);
	dir.y = sin(angle);

	init_ray(data, &ray[i], dir);	
	get_ray_collision(data, &ray[i]);
	draw_ray(data, &ray[i]);

	draw_3d_wall(data, &ray[i], i, angle);

	angle += angle_step;
	if (angle > (2 * PI))
	{
		angle -= (2 * PI);
	}
	if (angle < 0)
	{			
		angle += (2 * PI);
	}
	i++;
}

void	draw_player(t_data *data, mlx_image_t *image)
{
	t_vector_f start_pos;
	t_vector_f end_pos;

	start_pos.x = data->player->pos.x;
	start_pos.y = data->player->pos.y;
	
	end_pos.x = data->player->pos.x + data->player->dir.x * NOSE_LENGTH;
	end_pos.y = data->player->pos.y + data->player->dir.y * NOSE_LENGTH;
	
	draw_filled_circle(image, start_pos, PLAYER_SIZE, COLOUR_YELLOW);
	draw_line(image, start_pos, end_pos, COLOUR_GREEN);
	// draw_mouth()
}

void	draw_2D_map(t_data *data, mlx_image_t *image)
{
	int x;
	int y;
	t_vector_f offset;
	uint64_t colour;
	
	y = 0;
	while (y < data->map->rows)
	{
		x = 0;
		while (x < data->map->cols)
		{
			// offset.x = (x * GRIDSIZE) + x;
			// offset.y = (y * GRIDSIZE) + y;
			offset.x = x * GRIDSIZE;
			offset.y = y * GRIDSIZE;
			if (data->map->map[y][x] == '1')
			{	
				colour = COLOUR_BLACK;
			}
			else 
			{	
				colour = COLOUR_LIGHT_GRAY;
			}
			draw_filled_square(image, offset, GRIDSIZE, GRIDSIZE, colour);
			x++;
		}
		y++;
	}
}
