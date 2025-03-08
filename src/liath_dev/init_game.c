/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_game.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: livliege <livliege@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/07 14:41:53 by livliege      #+#    #+#                 */
/*   Updated: 2025/03/08 14:08:27 by anonymous     ########   odam.nl         */
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
				mlx_put_pixel(data->image, x, y, COLOUR_GRAY);
			x++;
		}
		y++;
	}
}

void	put_pixels(t_data *data, t_vector start_pos, uint32_t width, uint32_t height, uint64_t colour)
{
	uint32_t	x;
	uint32_t	y;

	y = start_pos.y;
	while (y < start_pos.y + height)
	{
		x = start_pos.x;
		while (x < start_pos.x + width)
		{
			if (x < data->image->width && y < data->image->height)
				mlx_put_pixel(data->image, x, y, colour);
			x++;
		}
		y++;
	}
}

void	draw_player(t_data *data)
{
	t_vector start_pos;

	start_pos.x = data->player->pos.x;
	start_pos.y = data->player->pos.y;
	put_pixels(data,start_pos, 10, 10, COLOUR_YELLOW);
}

void	draw_2D_map(t_data *data)
{
	int x;
	int y;
	t_vector offset;
	uint64_t colour;
	
	y = 0;
	while (y < data->map->rows)
	{
		x = 0;
		while (x < data->map->cols)
		{
			offset.x = (x * data->map->size) + x;
			offset.y = (y * data->map->size) + y;
			if (data->map->map[y][x] == '1')
			{	
				colour = COLOUR_WHITE;
			}
			else 
			{	
				colour = COLOUR_BLACK;
			}
			put_pixels(data, offset, data->map->size, data->map->size, colour);
			x++;
		}
		y++;
	}
}

void	game(t_data *data)
{
	draw_2D_map(data);
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
	game(data);
	// ------------------------------------------------------------------------------
	
	mlx_loop_hook(data->window, key_is_pressed, data);
	mlx_loop(data->window);
	mlx_terminate(data->window);
}