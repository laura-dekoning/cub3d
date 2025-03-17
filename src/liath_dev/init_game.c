/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_game.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: livliege <livliege@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/07 14:41:53 by livliege      #+#    #+#                 */
/*   Updated: 2025/03/17 14:09:13 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/liath.h"


void	game(t_data *data)
{
	draw_2D_map(data, data->minimap_image);
	raycasting(data);
	draw_player(data, data->minimap_image);
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
	data->minimap_image = mlx_new_image(data->window, MINIMAP_WIDTH, MINIMAP_HEIGHT);
	if (data->minimap_image == NULL)
	{
		mlx_terminate(data->window);
		error_and_exit("Image could not be created\n");
	}
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
	fill_canvas(data);
	game(data);
	
	mlx_loop_hook(data->window, key_is_pressed, data);
	mlx_loop(data->window);

	mlx_delete_image(data->window, data->window_image);
	mlx_delete_image(data->window, data->minimap_image);
	
	mlx_terminate(data->window);
}
