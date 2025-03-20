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

uint64_t	parse_wall_colours(t_ray *ray)
{
	uint64_t colour;

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
	return (colour);
}

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
	colour = parse_wall_colours(ray);



	line_width = data->window->width / (NUMB_RAYS);
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

	wall_height = (wall_distance * GRIDSIZE_3D) / corrected_distance;
	// wall_height = (wall_distance * GRIDSIZE_3D) / ray->distance;

	wall_top = get_max(0, (data->window->height / 2) - (wall_height / 2));
	wall_bottom = get_min(data->window->height, (data->window->height / 2) + (wall_height / 2));
	render_3d_scene(data, ray, ray_i, wall_top, wall_bottom);
}

void	draw_ceiling_and_floor(t_data *data)
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


