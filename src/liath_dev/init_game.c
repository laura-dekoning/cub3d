/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_game.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: livliege <livliege@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/07 14:41:53 by livliege      #+#    #+#                 */
/*   Updated: 2025/03/24 20:23:26 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/liath.h"


void	game(t_data *data)
{
	draw_ceiling_and_floor(data);
	raycasting(data);

	minimap(data);
}

void	get_minimap_size(t_data *data)
{
	if (WINDOW_HEIGHT > WINDOW_WIDTH)
	{
		data->minimap.minimap_size =  WINDOW_WIDTH / 5;
	}
	else 
	{
		data->minimap.minimap_size =  WINDOW_HEIGHT / 5;
	}
}

void	init_minimap_image(t_data *data)
{
	get_minimap_size(data);
	data->minimap_image = mlx_new_image(data->window, data->minimap.minimap_size, data->minimap.minimap_size);
	if (data->minimap_image == NULL)
	{
		mlx_terminate(data->window);
		error_and_exit("Image could not be created\n");
	}
	if (mlx_image_to_window(data->window, data->minimap_image, 10, 10) < 0)
	{
		mlx_delete_image(data->window, data->window_image);
		mlx_terminate(data->window);
		error_and_exit("Image could not be displayed on the window\n");
	}
}

void	init_window(t_data *data)
{
	data->window = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, false);
	if (data->window == NULL)
	{
		error_and_exit("Window could not be created\n");
	}
	data->window_image = mlx_new_image(data->window, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (data->window_image == NULL)
	{
		mlx_terminate(data->window);
		error_and_exit("Image could not be created\n");
	}
	if (mlx_image_to_window(data->window, data->window_image, 0, 0) < 0)
	{
		mlx_terminate(data->window);
		error_and_exit("Image could not be displayed on the window\n");
	}

}

void init_wall_textures(t_textures	*textures)
{
	textures->north_texture = mlx_load_png(textures->path_to_north_texture);
	if (!textures->north_texture)
		error_and_exit("Loading north wall failed\n");
	textures->east_texture = mlx_load_png(textures->path_to_east_texture);
	if (!textures->east_texture)
		error_and_exit("Loading east wall failed\n");
	textures->south_texture = mlx_load_png(textures->path_to_south_texture);
	if (!textures->south_texture)
		error_and_exit("Loading south wall failed\n");
	textures->west_texture = mlx_load_png(textures->path_to_west_texture);
	if (!textures->west_texture)
		error_and_exit("Loading west wall failed\n");
}


void cub3d(t_data *data)
{
	init_window(data);
	init_minimap_image(data);	
	init_wall_textures(&data->textures);

	game(data);
	
	mlx_loop_hook(data->window, is_key_pressed, data);
	mlx_loop(data->window);

	mlx_delete_image(data->window, data->window_image);
	mlx_delete_image(data->window, data->minimap_image);
	
	mlx_terminate(data->window);
}
