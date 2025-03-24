/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wall_textures.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: livliege <livliege@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/21 20:53:06 by livliege      #+#    #+#                 */
/*   Updated: 2025/03/21 20:53:06 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/liath.h"

mlx_texture_t	*set_wall_texture(t_data *data, t_ray *ray)
{
	if (ray->wall_3d.wall_side == NORTH)
	{
		ray->wall_3d.texture = data->textures.north_texture;
	}
	else if (ray->wall_3d.wall_side == EAST)
	{
		ray->wall_3d.texture = data->textures.east_texture;
	}
	else if (ray->wall_3d.wall_side == SOUTH)
	{
		ray->wall_3d.texture = data->textures.south_texture;
	}
	else // if (ray->wall_3d.wall_side == WEST)
	{
		ray->wall_3d.texture = data->textures.west_texture;
	}
	return (ray->wall_3d.texture);
}

void set_wall_side(t_ray *ray)
{
	if (ray->wall_3d.N_S_wall == true)
	{
		if (ray->step_dir.y < 0)
			ray->wall_3d.wall_side = NORTH;
		else
			ray->wall_3d.wall_side = SOUTH;
	}
	else
	{
		if (ray->step_dir.x < 0)
			ray->wall_3d.wall_side = WEST;
		else
			ray->wall_3d.wall_side = EAST;
	}
}

void init_wall_sagment(t_data *data, t_ray *ray)
{

	float excess_height;

	ray->wall_3d.wall_distance = (data->window->width / 2) / tan((FOV * ONE_D_RADIAN) / 2);
	ray->wall_3d.corrected_distance = ray->distance * cos(ray->angle - data->player.angle);

	// fix fisheye
	// ray->wall_3d.wall_height = (ray->wall_3d.wall_distance * GRIDSIZE_3D) / ray->distance;  			// for some fun fisheye effects ;)
	ray->wall_3d.wall_height = (ray->wall_3d.wall_distance * GRIDSIZE_3D) / ray->wall_3d.corrected_distance;

	ray->wall_3d.wall_top = fmax(0, (data->window->height / 2) - (ray->wall_3d.wall_height / 2));
	ray->wall_3d.wall_bottom = fmin(data->window->height, (data->window->height / 2) + (ray->wall_3d.wall_height / 2));
	
	// fix wall zooms in to the centre of the texture
	if (ray->wall_3d.wall_height > data->window->height)
	{
		excess_height = ray->wall_3d.wall_height - data->window->height;
		ray->wall_3d.texture_y_pos = (excess_height / 2.0) * (ray->wall_3d.texture->height / ray->wall_3d.wall_height);
	}
	// fix if texture goes off the top of the screen
	else if (ray->wall_3d.wall_top < 0)
	{
		ray->wall_3d.texture_y_pos = -ray->wall_3d.wall_top * ray->wall_3d.texture->height / ray->wall_3d.wall_height;
	}
	// if texture stays on the screen (top)
	else
	{
		ray->wall_3d.texture_y_pos = 0.0f;
	}
	// fix if texture goes off the bottom of the screen
	if (ray->wall_3d.wall_bottom > data->window->height)
	{
		ray->wall_3d.wall_bottom = data->window->height;
	}

	ray->wall_3d.line_width = data->window->width / NUMB_RAYS;
	set_wall_side(ray);
	set_wall_texture(data, ray);
}
