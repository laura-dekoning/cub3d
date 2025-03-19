/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_game.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: livliege <livliege@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/07 14:41:53 by livliege      #+#    #+#                 */
/*   Updated: 2025/03/19 22:35:23 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/liath.h"


void	game(t_data *data)
{
	fill_canvas(data);
	raycasting(data);
	minimap(data);
}

void	images_to_window(t_data *data)
{
	if (mlx_image_to_window(data->window, data->window_image, 0, 0) < 0)
	{
		mlx_terminate(data->window);
		error_and_exit("Image could not be displayed on the window\n");
	}
	if (mlx_image_to_window(data->window, data->minimap_image, 0, 0) < 0)
	{
		mlx_delete_image(data->window, data->window_image);
		mlx_terminate(data->window);
		error_and_exit("Image could not be displayed on the window\n");
	}
}

void	init_window_and_images(t_data *data)
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
	data->minimap_image = mlx_new_image(data->window, MINIMAP_WIDTH, MINIMAP_HEIGHT);
	if (data->minimap_image == NULL)
	{
		mlx_terminate(data->window);
		error_and_exit("Image could not be created\n");
	}
}



void cub3d(t_data *data)
{

	init_window_and_images(data);
	images_to_window(data);	
	
	game(data);
	
	mlx_loop_hook(data->window, is_key_pressed, data);
	mlx_loop(data->window);

	mlx_delete_image(data->window, data->window_image);
	mlx_delete_image(data->window, data->minimap_image);
	
	mlx_terminate(data->window);
}
