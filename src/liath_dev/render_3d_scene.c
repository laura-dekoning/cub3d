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

void render_3d_scene(t_data *data, int ray_i, int wall_top, int wall_bottom)
{
	int 		slice_width;
	int 		screen_x;
	int			i;
	t_vector_f 	start;
	t_vector_f 	end;

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


void cast_ray(t_data *data, t_ray *ray, int ray_i, float angle)
{
	float		wall_height;
    int			wall_top;
    int			wall_bottom;
    float		wall_distance;
	float		corrected_distance;

	wall_distance = (data->window->width / 2) / tan((FOV * ONE_D_RADIAN) / 2);
	corrected_distance = ray->distance * cos(angle - data->player.angle);

	wall_height = (wall_distance * GRIDSIZE) / corrected_distance;
	// wall_height = (wall_distance * GRIDSIZE) / ray->distance;

	wall_top = get_max(0, (data->window->height / 2) - (wall_height / 2));
	wall_bottom = get_min(data->window->height, (data->window->height / 2) + (wall_height / 2));
	render_3d_scene(data, ray_i, wall_top, wall_bottom);
}


