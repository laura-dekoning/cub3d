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

void render_3d_scene(t_data *data, t_ray *ray, int ray_i, int wall_top, int wall_bottom)
{
	int 		line_width;
	int			i;
	// float		shade_shift;
	t_vector_f 	start;
	t_vector_f 	end;
	uint64_t colour;
	
	// shade_shift= ray->distance;

	// colour = darken_colour(COLOUR_YELLOW, (int)shade_shift);


	if (ray->wall_side == NORTH)
	{
		colour = COLOUR_BLUE;
	}
	else if (ray->wall_side == EAST)
	{
		colour = COLOUR_GREEN;
	}
	else if (ray->wall_side == SOUTH)
	{
		colour = COLOUR_RED;
	}
	else // ray->wall_side == WEST
	{
		colour = COLOUR_YELLOW;
	}

	line_width = data->window->width / NUMB_RAYS;
	i = 0;
	while (i < line_width)
	{	
		start.x = line_width * ray_i + i;
		if (start.x >= data->window->width)
			break;
		start.y = wall_top;
		end.x = line_width * ray_i + i;
		end.y = wall_bottom;
	
		// colour = darken_colour(colour, ray_i / 3);

		draw_line(data->window_image, start, end, colour);
		i++;
	}
}


void cast_ray(t_data *data, t_ray *ray, int ray_i)
{
	float		wall_height;
    int			wall_top;
    int			wall_bottom;
    float		wall_distance;
	float		corrected_distance;

	wall_distance = (data->window->width / 2) / tan((FOV * ONE_D_RADIAN) / 2);
	corrected_distance = ray->distance * cos(ray->angle - data->player.angle);

	wall_height = (wall_distance * GRIDSIZE) / corrected_distance;
	// wall_height = (wall_distance * GRIDSIZE) / ray->distance;

	wall_top = get_max(0, (data->window->height / 2) - (wall_height / 2));
	wall_bottom = get_min(data->window->height, (data->window->height / 2) + (wall_height / 2));
	render_3d_scene(data, ray, ray_i, wall_top, wall_bottom);
}


