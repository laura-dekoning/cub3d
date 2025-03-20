/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_game.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: livliege <livliege@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/07 14:41:53 by livliege      #+#    #+#                 */
/*   Updated: 2025/03/20 17:34:32 by livliege      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/liath.h"

long get_time_in_ms(void)
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}

// void calculate_fps(void)
// {
// 	static long last_time = 0;
// 	static int frame_count = 0;
// 	static float fps = 0.0;

// 	long current_time = get_time_in_ms();
// 	frame_count++;

// 	if (current_time - last_time >= 1000) // Update every second
// 	{
// 		fps = frame_count * 1000.0 / (current_time - last_time);
// 		printf("FPS: %.2f\n", fps);
// 		frame_count = 0;
// 		last_time = current_time;
// 	}
// }

// void	fps(t_data *data)
// {
// 	// double time;
// 	// double old_time;
// 	// double frame_time;
	
	
// 	data->fps_counter.old_time = data->fps_counter.time;
// 	data->fps_counter.time = (double)get_time_in_ms();
// 	data->fps_counter.frame_time = (data->fps_counter.time - data->fps_counter.old_time) / 1000.0; // frame_time is the time this frame has taken in seconds.
// 	printf("%f\n", 1.0 / data->fps_counter.frame_time);

// 	data->player.moving_speed = data->fps_counter.frame_time * MOVING_SPEED;
// 	data->player.rotating_speed = data->fps_counter.frame_time * ROTATING_SPEED;
// }

void	game(t_data *data)
{
	// fill_canvas(data, COLOUR_DARK_GRAY);
	draw_ceiling_and_floor(data);
	raycasting(data);

	// fps(data);
	
	minimap(data);
}

void	images_to_window(t_data *data)
{
	if (mlx_image_to_window(data->window, data->window_image, 0, 0) < 0)
	{
		mlx_terminate(data->window);
		error_and_exit("Image could not be displayed on the window\n");
	}
	if (mlx_image_to_window(data->window, data->minimap_image, 10, 10) < 0)
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
