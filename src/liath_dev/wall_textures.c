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

// uint64_t	parse_wall_textures(t_ray *ray)
// {
// the array of ints had the colours for the pixels. pixels[0] = R; pixels[1] = G; pixels[2] = B; pixels[3] = A;
// so to get the colour of the pixel you would do this:

// u_int32_t	get_color(mlx_texture_t *tex, int x, int y, int alpha)
// {
// 	int	red;
// 	int	green;
// 	int	blue;
// 	int	i;

// 	i = y * tex->width + x;
// 	red = tex->pixels[i * tex->bytes_per_pixel];
// 	green = tex->pixels[i * tex->bytes_per_pixel + 1];
// 	blue = tex->pixels[i * tex->bytes_per_pixel + 2];
// 	return (get_rgba(red, green, blue, alpha));
// }

// 	* @param width The width of the texture.
// 	* @param height The height of the texture.
// 	* @param pixels The literal pixel data.
// 	* @param bytes_per_pixel The amount of bytes in a pixel, always 4.
// 	*/
//    typedef struct mlx_texture
//    {
// 	   uint32_t	width;
// 	   uint32_t	height;
// 	   uint8_t	bytes_per_pixel;
// 	   uint8_t*	pixels;
//    }	mlx_texture_t;


// }


mlx_texture_t	*set_wall_texture(t_data *data, t_ray *ray)
{
	mlx_texture_t	*texture;

	if (ray->wall_side == NORTH)
	{
		texture = data->walls.north_texture;
	}
	else if (ray->wall_side == EAST)
	{
		texture = data->walls.north_texture;
	}
	else if (ray->wall_side == SOUTH)
	{
		texture = data->walls.north_texture;
	}
	else // ray->wall_side == WEST
	{
		texture = data->walls.north_texture;
	}
	return (texture);
}

void render_3d_scene(t_data *data, t_ray *ray, int ray_i, int wall_top, int wall_bottom)
{
	mlx_texture_t	*texture;
	int				line_width;
	float			wall_hit_x;
	int 			tex_x;
	int 			tex_y;
	float			tex_step;
	int				i;
	uint32_t		x;
	uint32_t		y;
	uint8_t			*pixel;
	uint64_t		colour;


	line_width = data->window->width / NUMB_RAYS;
	texture = set_wall_texture(data, ray);

	if (ray->wall_side == NORTH || ray->wall_side == SOUTH)
		wall_hit_x = fmod(ray->end_pos.x, GRIDSIZE_3D) / GRIDSIZE_3D;
	else
		wall_hit_x = fmod(ray->end_pos.y, GRIDSIZE_3D) / GRIDSIZE_3D;

	if (ray->wall_side == SOUTH || ray->wall_side == WEST)
		wall_hit_x = 1.0 - wall_hit_x;

	tex_x = (int)(wall_hit_x * texture->width);
	tex_step = (float)texture->height / (wall_bottom - wall_top);

	i = 0;
	while (i < line_width)
	{
		x = line_width * ray_i + i;
		if (x >= (uint32_t)data->window->width)
			break;
		y = wall_top;
		while (y < (uint32_t)wall_bottom)
		{
			tex_y = (int)((y - wall_top) * tex_step) % texture->height;
			pixel = &texture->pixels[(tex_y * texture->width + tex_x) * 4];
			colour = (pixel[0] << 24) | (pixel[1] << 16) | (pixel[2] << 8) | pixel[3];
			if (x > 0 && y > 0 && x < data->window_image->width && y < data->window_image->height)
				mlx_put_pixel(data->window_image, x, y, colour);
			y++;
		}
		i++;
	}
}


// void render_3d_scene(t_data *data, t_ray *ray, int ray_i, int wall_top, int wall_bottom)
// {
//     int line_width = data->window->width / NUMB_RAYS;
//     int wall_height = wall_bottom - wall_top;
//     mlx_texture_t *texture = set_wall_texture(data, ray->wall_side);
//     float texture_x;
//     if (ray->wall_side == NORTH || ray->wall_side == SOUTH)
//         texture_x = fmod(ray->end_pos.x, GRIDSIZE_3D) / GRIDSIZE_3D;
//     else
//         texture_x = fmod(ray->end_pos.y, GRIDSIZE_3D) / GRIDSIZE_3D;

//     // Flip texture for SOUTH and WEST walls
//     if (ray->wall_side == SOUTH || ray->wall_side == WEST)
//         texture_x = 1.0 - texture_x;

//     int tex_x = (int)(texture_x * texture->width);
//     float tex_step = (float)texture->height / wall_height;
//     float tex_pos = 0.0f;

//     for (int i = 0; i < line_width; i++)
//     {
//         int x = ray_i * line_width + i;
//         if (x >= data->window->width) break;
//         tex_pos = 0.0f;
//         for (int y = wall_top; y < wall_bottom; y++)
//         {
//             int tex_y = (int)tex_pos % texture->height;
//             int pixel_index = (tex_y * texture->width + tex_x) * texture->bytes_per_pixel;
//             uint8_t r = texture->pixels[pixel_index];
//             uint8_t g = texture->pixels[pixel_index + 1];
//             uint8_t b = texture->pixels[pixel_index + 2];
//             uint8_t a = texture->pixels[pixel_index + 3];
//             draw_pixel(data->window_image, x, y, r, g, b, a);
//             tex_pos += tex_step;
//         }
//     }
// }


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
