/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_game.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: livliege <livliege@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/07 14:41:53 by livliege      #+#    #+#                 */
/*   Updated: 2025/03/07 15:14:43 by livliege      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "../../incl/liath.h"

void	fill_canvas(t_data *data)
{
	uint32_t	x;
	uint32_t	y;

	y = 0;
	while (y < data->image->height)
	{
		x = 0;
		while (x < data->image->width)
		{
			if (x < data->image->width && y < data->image->height)
				mlx_put_pixel(data->image, x, y, 0x333333FF);
			x++;
		}
		y++;
	}
}

void	draw_player(t_data *data)
{
	(void)data;
}

void	game(t_data *data)
{
	draw_player(data);
}

void	init_window(t_data *data)
{
	data->window = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, false);
	if (data->window == NULL)
	{
		error_and_exit("Window could not be created\n");
	}
	data->image = mlx_new_image(data->window, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (data->image == NULL)
	{
		mlx_terminate(data->window);
		error_and_exit("Image could not be created\n");
	}
	mlx_image_to_window(data->window, data->image, 0, 0);
	fill_canvas(data); // we now have a gray empty screen!
	// ------------------------------------------------------------------------------

	game(data);

	mlx_loop_hook(data->window, key_is_pressed, data);
	printf("TEST1\n");
	mlx_loop(data->window);
	printf("TEST2\n");
	mlx_terminate(data->window);
}