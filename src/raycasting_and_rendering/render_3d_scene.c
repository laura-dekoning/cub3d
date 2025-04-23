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

#include "cub3d.h"

void	set_texture_y(t_ray *ray, int texture_y)
{
	ray->wall_3d.texture_y = texture_y;
	if (ray->wall_3d.texture_y >= (int)ray->wall_3d.texture->height)
		ray->wall_3d.texture_y = ray->wall_3d.texture->height - 1;
	if (ray->wall_3d.texture_y < 0)
		ray->wall_3d.texture_y = 0;
}

uint64_t	get_pixel_colour(t_ray *ray, int texture_y)
{
	int				pixel_index;
	uint8_t			*pixel_array;
	int				pixel_array_len;
	uint64_t		colour_hex;
	t_colour_rgba	colour;

	pixel_array = ray->wall_3d.texture->pixels;
	pixel_array_len = ray->wall_3d.texture->width * \
	ray->wall_3d.texture->height * ray->wall_3d.texture->bytes_per_pixel;
	set_texture_y(ray, texture_y);
	pixel_index = (ray->wall_3d.texture_y * ray->wall_3d.texture->width + \
		ray->wall_3d.texture_x) * ray->wall_3d.texture->bytes_per_pixel;
	if (pixel_index + 2 > pixel_array_len)
		return (0);
	colour.r = pixel_array[pixel_index];
	colour.g = pixel_array[pixel_index + 1];
	colour.b = pixel_array[pixel_index + 2];
	colour.a = ray->wall_3d.wall_shadow;
	colour_hex = (colour.r << 24) | (colour.g << 16) | \
	(colour.b << 8) | colour.a;
	return (colour_hex);
}

void	put_pixel_safe(t_game *game, t_ray *ray, t_vector_s	screen_pos, \
float texture_y)
{
	uint64_t		colour;

	if (screen_pos.x > 0 && screen_pos.y > 0 && screen_pos.x < \
		game->window_image->width && screen_pos.y < game->window_image->height)
	{
		colour = get_pixel_colour(ray, (int)texture_y);
		mlx_put_pixel(game->window_image, screen_pos.x, screen_pos.y, colour);
	}
}

void	draw_wall_segment(t_game *game, t_ray *ray, \
int wall_top, int wall_bottom)
{
	t_vector_s		screen_pos;
	float			texture_y;
	int				i;

	texture_y = ray->wall_3d.texture_y_pos;
	i = 0;
	while (i < ray->wall_3d.line_width)
	{
		screen_pos.x = ray->index * ray->wall_3d.line_width + i;
		if (screen_pos.x >= (uint32_t)game->window->width)
			break ;
		texture_y = ray->wall_3d.texture_y_pos;
		screen_pos.y = wall_top;
		while (screen_pos.y < (uint32_t)wall_bottom)
		{
			put_pixel_safe(game, ray, screen_pos, texture_y);
			texture_y += ray->wall_3d.texture_y_step;
			screen_pos.y++;
		}
		i++;
	}
}

void	render_3d_wall_segment(t_game *game, t_ray *ray)
{
	if (ray->wall_3d.wall_side == NORTH || ray->wall_3d.wall_side == SOUTH)
	{
		ray->wall_3d.wall_hit_screen_x = \
		fmod(ray->end_pos.x, GRIDSIZE) / GRIDSIZE;
	}
	else if (ray->wall_3d.wall_side == EAST || ray->wall_3d.wall_side == WEST)
	{
		ray->wall_3d.wall_hit_screen_x = \
		fmod(ray->end_pos.y, GRIDSIZE) / GRIDSIZE;
	}
	fix_mirrored_effect(ray);
	ray->wall_3d.texture_x = (int)(ray->wall_3d.wall_hit_screen_x * \
		ray->wall_3d.texture->width);
	ray->wall_3d.texture_y_step = (float)ray->wall_3d.texture->height / \
	ray->wall_3d.wall_height;
	draw_wall_segment(game, ray, ray->wall_3d.wall_top, \
		ray->wall_3d.wall_bottom);
}
