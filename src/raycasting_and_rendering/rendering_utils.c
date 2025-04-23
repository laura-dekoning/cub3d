/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rendering_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/04 16:00:10 by livliege      #+#    #+#                 */
/*   Updated: 2025/04/23 14:23:52 by livliege      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fix_texture_stretch(t_game *game, t_ray *ray)
{
	if (ray->wall_3d.wall_top < 0)
	{
		ray->wall_3d.texture_y_pos = -ray->wall_3d.wall_top * \
		ray->wall_3d.texture->height / ray->wall_3d.wall_height;
	}
	else
	{
		ray->wall_3d.texture_y_pos = 0.0f;
	}
	if (ray->wall_3d.wall_bottom > game->window->height)
	{
		ray->wall_3d.wall_bottom = game->window->height;
	}
}

void	fix_texture_zoom_to_centre(t_game *game, t_ray *ray)
{
	float	extra_height;

	if (ray->wall_3d.wall_height > game->window->height)
	{
		extra_height = ray->wall_3d.wall_height - game->window->height;
		ray->wall_3d.texture_y_pos = (extra_height / 2.0) * \
		(ray->wall_3d.texture->height / ray->wall_3d.wall_height);
	}
}

void	fix_mirrored_effect(t_ray *ray)
{
	if (ray->wall_3d.wall_side == SOUTH || ray->wall_3d.wall_side == WEST)
	{
		ray->wall_3d.wall_hit_screen_x = 1.0 - ray->wall_3d.wall_hit_screen_x;
	}
}
