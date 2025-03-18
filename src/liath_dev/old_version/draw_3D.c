/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_3D.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: livliege <livliege@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/17 14:09:53 by livliege      #+#    #+#                 */
/*   Updated: 2025/03/17 14:09:46 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/liath.h"

void draw_3d_wall(t_data *data, t_ray *ray, int ray_i, float angle)
{
	float		wall_height;
    int			wall_top;
    int			wall_bottom;
    float		wall_distance;
	float		corrected_distance;
	t_vector_f 	start;
	t_vector_f 	end;
	int 		slice_width;
	int 		screen_x;
	int			i;

	wall_distance = (data->window->width / 2) / tan((90.0 * ONE_DEGREE) / 2);

	corrected_distance = ray->distance * cos(angle - data->player->angle);
	wall_height = (GRIDSIZE * wall_distance) / corrected_distance;

	wall_top = get_max(0, (data->window->height / 2) - (wall_height / 2));
	wall_bottom = get_min(data->window->height, (data->window->height / 2) + (wall_height / 2));
	
	slice_width = data->window->width / NUMB_RAYS;
	i = 0;
	while (i < slice_width)
	{
		screen_x = ray_i * slice_width + i;
		if (screen_x >= data->window->width)
			break;
		start.x = ray_i * slice_width + i;
		start.y = wall_top;
		end.x = ray_i * slice_width + i;
		end.y = wall_bottom;
		draw_line(data->window_image, start, end, COLOUR_BLUE);
		i++;
	}
}

// void render_3d_game(t_data *data)
// {
// 	int i;

// 	i = 0;
// 	while (i < NUMB_RAYS)
// 	{
// 		dir.x = cos(angle);
// 		dir.y = sin(angle);
// 		draw_3d_wall(data, &data->ray[i], i, angle);
// 		angle += angle_step;
// 		if (angle > (2 * PI))
// 		{
// 			angle -= (2 * PI);
// 		}
// 		if (angle < 0)
// 		{			
// 			angle += (2 * PI);
// 		}
// 		i++;
// 	}
// }
