/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rendering_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/04 16:00:10 by livliege      #+#    #+#                 */
/*   Updated: 2025/04/10 17:00:59 by livliege      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fix_texture_stretch(t_game *game, t_ray *ray)
{
	// fix if texture goes off the top of the screen
	if (ray->wall_3d.wall_top < 0)
	{
		ray->wall_3d.texture_y_pos = -ray->wall_3d.wall_top * ray->wall_3d.texture->height / ray->wall_3d.wall_height;
	}
	// if texture stays on the screen (top)
	else
	{
		ray->wall_3d.texture_y_pos = 0.0f;
	}
	// fix if texture goes off the bottom of the screen
	if (ray->wall_3d.wall_bottom > game->window->height)
	{
		ray->wall_3d.wall_bottom = game->window->height;
	}
}

void	fix_texture_zoom_to_centre(t_game *game, t_ray *ray)
{
	float	extra_height;

	// fix wall zooms in to the centre of the texture
	if (ray->wall_3d.wall_height > game->window->height)
	{
		printf("TEST 0\n");

		if (ray->wall_3d.texture == NULL)
		{
			fprintf(stderr, "ERROR: ray->wall_3d.texture is NULL\n");
			printf("Texture not assigned for wall at ray x = %d, y = %d\n", ray->wall_3d.texture_x, ray->wall_3d.texture_x);
			return;
		}
		
		extra_height = ray->wall_3d.wall_height - game->window->height;
		printf("TEST 1\n");

		ray->wall_3d.texture_y_pos = (extra_height / 2.0) * (ray->wall_3d.texture->height / ray->wall_3d.wall_height);
		printf("TEST 2\n");
		
	}
}
