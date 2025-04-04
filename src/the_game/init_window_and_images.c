/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_window_and_images.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/07 14:41:53 by livliege      #+#    #+#                 */
/*   Updated: 2025/04/04 15:58:42 by livliege      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_minimap_size(t_game *data)
{
	if (WINDOW_HEIGHT > WINDOW_WIDTH)
	{
		data->minimap.minimap_size =  WINDOW_WIDTH / MINIMAP_SCALE;
	}
	else 
	{
		data->minimap.minimap_size =  WINDOW_HEIGHT / MINIMAP_SCALE;
	}
}

void	init_minimap_border_image(t_game *data)
{
	data->minimap_border_image = mlx_new_image(data->window, data->minimap.minimap_size + 2, data->minimap.minimap_size + 2);
	if (data->minimap_border_image == NULL)
	{
		mlx_terminate(data->window);
		error_message("Image could not be created\n");
	}
	if (mlx_image_to_window(data->window, data->minimap_border_image, 9, 9) < 0)
	{
		mlx_delete_image(data->window, data->window_image);
		mlx_delete_image(data->window, data->minimap_image);
		mlx_terminate(data->window);
		error_message("Image could not be displayed on the window\n");
	}
}

void	init_minimap_image(t_game *data)
{
	get_minimap_size(data);
	data->minimap_image = mlx_new_image(data->window, data->minimap.minimap_size, data->minimap.minimap_size);
	if (data->minimap_image == NULL)
	{
		mlx_terminate(data->window);
		error_message("Image could not be created\n");
	}
	if (mlx_image_to_window(data->window, data->minimap_image, 10, 10) < 0)
	{
		mlx_delete_image(data->window, data->window_image);
		mlx_terminate(data->window);
		error_message("Image could not be displayed on the window\n");
	}
	init_minimap_border_image(data);
}

void	init_window(t_game *data)
{
	data->window = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, false);
	if (data->window == NULL)
	{
		error_message("Window could not be created\n");
	}
	data->window_image = mlx_new_image(data->window, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (data->window_image == NULL)
	{
		mlx_terminate(data->window);
		error_message("Image could not be created\n");
	}
	if (mlx_image_to_window(data->window, data->window_image, 0, 0) < 0)
	{
		mlx_terminate(data->window);
		error_message("Image could not be displayed on the window\n");
	}
}

void init_wall_textures(t_textures	*textures)
{
	textures->north_texture = mlx_load_png(textures->path_to_north_texture);
	if (!textures->north_texture)
		error_message("Loading north wall failed\n");
	textures->east_texture = mlx_load_png(textures->path_to_east_texture);
	if (!textures->east_texture)
		error_message("Loading east wall failed\n");
	textures->south_texture = mlx_load_png(textures->path_to_south_texture);
	if (!textures->south_texture)
		error_message("Loading south wall failed\n");
	textures->west_texture = mlx_load_png(textures->path_to_west_texture);
	if (!textures->west_texture)
		error_message("Loading west wall failed\n");
}
