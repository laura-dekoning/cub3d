/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_game.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: livliege <livliege@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/07 14:41:53 by livliege      #+#    #+#                 */
/*   Updated: 2025/03/15 20:25:25 by livliege      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "../../incl/liath.h"

void	fill_canvas(t_data *data)
{
	uint32_t	x;
	uint32_t	y;

	y = 0;
	while (y < data->window_image->height)
	{
		x = 0;
		while (x < data->window_image->width)
		{
			mlx_put_pixel(data->window_image, x, y, COLOUR_GRAY);
			x++;
		}
		y++;
	}
}

void	draw_filled_square(mlx_image_t *image, t_vector_f start_pos, uint32_t width, uint32_t height, uint64_t colour)
{
	uint32_t	x;
	uint32_t	y;

	y = start_pos.y;
	while (y < start_pos.y + height)
	{
		x = start_pos.x;
		while (x < start_pos.x + width)
		{
			if (x < image->width && y < image->height)
				mlx_put_pixel(image, x, y, colour);
			x++;
		}
		y++;
	}
}

void draw_filled_circle(mlx_image_t	*image, t_vector_f centre, int radius, int colour) 
{
	int x;
	int y;
	
	y = -radius;
	while (y <= radius) 
	{
		x = -radius;
		while (x <= radius) 
		{
			if ((centre.x + x >= 0 && centre.y + y >= 0 && centre.x + x < (int)image->width && centre.y + y < (int)image->height) && (x * x + y * y <= radius * radius)) // Check if the point is inside the circle
			{
				mlx_put_pixel(image, centre.x + x, centre.y + y, colour);
			}
			x++;
		}
		y++;
	}
}

void	draw_line(mlx_image_t *image, t_vector_f start, t_vector_f end, uint64_t colour)
{
	float	step_x;
	float	step_y;
	float	max;

	//get total length
	step_x = end.x - start.x;
	step_y = end.y - start.y;
	//get amount of steps
	max = get_max(fabsf(step_x), fabsf(step_y));	// fabsf() returns the absolute value of a float
	// get step length for x and y
	step_x /= max;
	step_y /= max;
	// compare ints because floats are unreliable
	while ((int)(start.x - end.x) || (int)(start.y - end.y))
	{
		if (start.x >= 0 && start.y >= 0 && start.x < (int)image->width && start.y < (int)image->height)
			mlx_put_pixel(image, start.x, start.y, colour);
		start.x += step_x;
		start.y += step_y;
	}
}
int message_i = 0;		// TAKE OUT

void	draw_player(t_data *data, mlx_image_t *image)
{
	t_vector_f start_pos;
	t_vector_f end_pos;
	// t_vector_f player_pos_one;		// top-left courner of player
	// t_vector_f player_pos_two;		// bottom-right courner of player


	// player_pos_one.x = data->player->pos.x - PLAYER_SIZE;
	// player_pos_one.y = data->player->pos.y - PLAYER_SIZE;
	// player_pos_two.x = data->player->pos.x + PLAYER_SIZE;
	// player_pos_two.y = data->player->pos.y + PLAYER_SIZE;


	start_pos.x = data->player->pos.x;
	start_pos.y = data->player->pos.y;

	// if ((player_pos_one.x >= 0 && player_pos_one.y >= 0 && player_pos_one.x < data->minimap_size.x && player_pos_one.y < data->minimap_size.y) && \
	// (player_pos_two.x >= 0 && player_pos_two.y >= 0 && player_pos_two.x < data->minimap_size.x && player_pos_two.y < data->minimap_size.y))
	// {
	// 	if ((data->map->map[(int)(player_pos_one.y / GRIDSIZE)][(int)(player_pos_one.x / GRIDSIZE)] == '1') || \
	// 	(data->map->map[(int)(player_pos_two.y / GRIDSIZE)][(int)(player_pos_two.x / GRIDSIZE)] == '1'))
	// 	{
	// 		data->player->wall_hit = true;
	// 		// printf("%d	Player hit wall!\n", message_i);		// TAKE OUT
	// 		message_i++;		// TAKE OUT
	// 	}
	// 	else
	// 	{
	// 		data->player->wall_hit = false;
	// 		// printf("%d	Player is FREEEEE!\n", message_i);		// TAKE OUT
	// 		message_i++;		// TAKE OUT
	// 	}
	// }
	
	end_pos.x = data->player->pos.x + data->player->dir.x * NOSE_LENGTH;
	end_pos.y = data->player->pos.y + data->player->dir.y * NOSE_LENGTH;
	
	draw_filled_circle(image, start_pos, PLAYER_SIZE, COLOUR_YELLOW);
	draw_line(image, start_pos, end_pos, COLOUR_GREEN);
}

void	draw_2D_map(t_data *data, mlx_image_t *image)
{
	int x;
	int y;
	t_vector_f offset;
	uint64_t colour;
	
	y = 0;
	while (y < data->map->rows)
	{
		x = 0;
		while (x < data->map->cols)
		{
			// offset.x = (x * GRIDSIZE) + x;
			// offset.y = (y * GRIDSIZE) + y;
			offset.x = x * GRIDSIZE;
			offset.y = y * GRIDSIZE;
			if (data->map->map[y][x] == '1')
			{	
				colour = COLOUR_BLACK;
			}
			else 
			{	
				colour = COLOUR_LIGHT_GRAY;
			}
			draw_filled_square(image, offset, GRIDSIZE, GRIDSIZE, colour);
			x++;
		}
		y++;
	}
}

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
		mlx_terminate(data->window);
		error_and_exit("Image could not be displayed on the window\n");
	}

	fill_canvas(data);
	game(data);
	
	mlx_loop_hook(data->window, key_is_pressed, data);
	mlx_loop(data->window);
	mlx_terminate(data->window);
}
