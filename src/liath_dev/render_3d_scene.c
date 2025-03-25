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

/*
typedef struct mlx_texture
{
    uint32_t width;
    uint32_t height;
    uint8_t  bytes_per_pixel;
    uint8_t* pixels;
} mlx_texture_t;
 

width: The texture’s width in pixels.
height: The texture’s height in pixels.
bytes_per_pixel: Always 4 (RGBA), meaning every pixel uses 4 bytes.
pixels: An array where every 4 consecutive values represent the Red, Green, Blue, and Alpha (transparency) of a pixel.

array length = width * height * bytes_per_pixel;
*/


void set_texture_y(t_ray *ray, int texture_y)
{
	// to fix ghost effect
	ray->wall_3d.texture_y = texture_y;
	if (ray->wall_3d.texture_y >= (int)ray->wall_3d.texture->height)
		ray->wall_3d.texture_y = ray->wall_3d.texture->height - 1;
	if (ray->wall_3d.texture_y < 0)
		ray->wall_3d.texture_y = 0;
}

uint64_t	get_pixel_colour(t_ray *ray, int texture_y)
{
	int				pixel_index;
	uint8_t				*pixel_array;
	int 			pixel_array_len;
	uint64_t		colour;
	uint8_t			r;
	uint8_t			g;
	uint8_t			b;
	uint8_t			a;

	pixel_array = ray->wall_3d.texture->pixels;
	pixel_array_len = ray->wall_3d.texture->width * ray->wall_3d.texture->height  * ray->wall_3d.texture->bytes_per_pixel;

	set_texture_y(ray, texture_y);
	pixel_index = (ray->wall_3d.texture_y * ray->wall_3d.texture->width + ray->wall_3d.texture_x) * ray->wall_3d.texture->bytes_per_pixel;
	if (pixel_index + 2 > pixel_array_len)
		return(0);	// black pixel?
	r = pixel_array[pixel_index];
	g = pixel_array[pixel_index + 1];
	b = pixel_array[pixel_index + 2];
	// a = pixel_array[pixel_index + 3];
	a = ray->wall_3d.wall_shadow;

	colour = (r << 24) | (g << 16) | (b << 8) | a;
	return (colour);
}

void	draw_wall_segment(t_data *data, t_ray *ray, int ray_i, int wall_top, int wall_bottom)
{
	uint32_t		x;
	uint32_t		y;
	uint64_t		colour;
	float 			texture_y;
	int				i;

	texture_y = ray->wall_3d.texture_y_pos;
	i = 0;
	while (i < ray->wall_3d.line_width)
	{
		x = ray_i * ray->wall_3d.line_width + i;
		if (x >= (uint32_t)data->window->width) 
			break;
		texture_y = ray->wall_3d.texture_y_pos;
		y = wall_top;
		while (y < (uint32_t)wall_bottom)
		{
			if (x > 0 && y > 0 && x < data->window_image->width && y < data->window_image->height)
			{
				// create shadow by drawing a pixel in the wall colour first, then the texture pixel with an alpha depending on the distance
				// mlx_put_pixel(data->window_image, x, y, data->walls_colour); // background collor
				colour = get_pixel_colour(ray, (int)texture_y);
				mlx_put_pixel(data->window_image, x, y, colour); // texture			
			}
			texture_y += ray->wall_3d.texture_y_step;
			y++;
		}
		i++;
	}
}

void render_3d_wall_sagment(t_data *data, t_ray *ray, int ray_i)
{
	if (ray->wall_3d.wall_side == NORTH || ray->wall_3d.wall_side == SOUTH)
	{
		ray->wall_3d.wall_hit_screen_x = fmod(ray->end_pos.x, GRIDSIZE) / GRIDSIZE;
	}
	else if (ray->wall_3d.wall_side == EAST || ray->wall_3d.wall_side == WEST)
	{
		ray->wall_3d.wall_hit_screen_x = fmod(ray->end_pos.y, GRIDSIZE) / GRIDSIZE;
	}

	// to fix mirrored effect
	if (ray->wall_3d.wall_side == SOUTH || ray->wall_3d.wall_side == WEST)
	{
		ray->wall_3d.wall_hit_screen_x = 1.0 - ray->wall_3d.wall_hit_screen_x;
	}

	ray->wall_3d.texture_x = (int)(ray->wall_3d.wall_hit_screen_x * ray->wall_3d.texture->width);
	ray->wall_3d.texture_y_step = (float)ray->wall_3d.texture->height / ray->wall_3d.wall_height;

	draw_wall_segment(data, ray, ray_i, ray->wall_3d.wall_top, ray->wall_3d.wall_bottom);


}
