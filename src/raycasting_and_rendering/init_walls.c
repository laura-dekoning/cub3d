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

#include "cub3d.h"

void	set_wall_shadow(t_ray *ray)
{
	if (ray->distance > RENDER_DIST)
	{
		ray->wall_3d.wall_shadow = 0;
	}
	else
	{
		ray->wall_3d.wall_shadow = (255 - (int)(ray->distance / FOG_FACTOR));
		if (ray->wall_3d.wall_shadow > 255)
			ray->wall_3d.wall_shadow = 255;
		if (ray->wall_3d.wall_shadow < 0)
			ray->wall_3d.wall_shadow = 0;
	}
}

mlx_texture_t	*set_wall_texture(t_game *game, t_ray *ray)
{
	if (ray->wall_3d.wall_side == NORTH)
	{
		ray->wall_3d.texture = game->textures.north_texture;
	}
	else if (ray->wall_3d.wall_side == EAST)
	{
		ray->wall_3d.texture = game->textures.east_texture;
	}
	else if (ray->wall_3d.wall_side == SOUTH)
	{
		ray->wall_3d.texture = game->textures.south_texture;
	}
	else
	{
		ray->wall_3d.texture = game->textures.west_texture;
	}
	return (ray->wall_3d.texture);
}

void	set_wall_side(t_ray *ray)
{
	if (ray->wall_3d.n_s_wall == true)
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

void	init_wall_segment(t_game *game, t_ray *ray)
{
	ray->wall_3d.wall_distance = (game->window->width / 2) / \
		tan((FOV * ONE_D_RADIAN) / 2);
	ray->wall_3d.corrected_distance = ray->distance * \
		cos(ray->angle - game->player->angle);
	ray->wall_3d.wall_height = (ray->wall_3d.wall_distance * GRIDSIZE) / \
		ray->wall_3d.corrected_distance;
	ray->wall_3d.wall_top = fmax(0, (game->window->height / 2) - \
		(ray->wall_3d.wall_height / 2));
	ray->wall_3d.wall_bottom = fmin(game->window->height, \
		(game->window->height / 2) + (ray->wall_3d.wall_height / 2));
	ray->wall_3d.line_width = game->window->width / NUMB_RAYS;
	set_wall_side(ray);
	set_wall_texture(game, ray);
	set_wall_shadow(ray);
	if (ray->wall_3d.wall_side == NORTH || ray->wall_3d.wall_side == SOUTH)
	{
		ray->wall_3d.screen_x = \
			fmod(ray->end_pos.x, GRIDSIZE) / GRIDSIZE;
	}
	else if (ray->wall_3d.wall_side == EAST || ray->wall_3d.wall_side == WEST)
	{
		ray->wall_3d.screen_x = \
			fmod(ray->end_pos.y, GRIDSIZE) / GRIDSIZE;
	}
}
