/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_game.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: livliege <livliege@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/07 14:41:53 by livliege      #+#    #+#                 */
/*   Updated: 2025/03/13 23:31:09 by anonymous     ########   odam.nl         */
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
			mlx_put_pixel(data->image, x, y, COLOUR_GRAY);
			x++;
		}
		y++;
	}
}

void	draw_filled_square(t_data *data, t_vector_f start_pos, uint32_t width, uint32_t height, uint64_t colour)
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

void draw_filled_circle(t_data *data, t_vector_f centre, int radius, int colour) 
{
    int x;
	int y;
	
	y = -radius;
    while (y <= radius) 
    {
		x = -radius;
        while (x <= radius) 
        {
            if ((centre.x + x >= 0 && centre.y + y >= 0 && centre.x + x < (int)data->image->width && centre.y + y < (int)data->image->height) && (x * x + y * y <= radius * radius)) // Check if the point is inside the circle
            {
                mlx_put_pixel(data->image, centre.x + x, centre.y + y, colour);
            }
			x++;
        }
		y++;
    }
}

float	get_max(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void	draw_line(t_data *data, t_vector_f start, t_vector_f end, uint64_t colour)
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
		if (start.x >= 0 && start.y >= 0 && start.x < (int)data->image->width && start.y < (int)data->image->height)
			mlx_put_pixel(data->image, start.x, start.y, colour);
		start.x += step_x;
		start.y += step_y;
	}
}

void	draw_player(t_data *data)
{
	t_vector_f start_pos;
	t_vector_f end_pos;

	start_pos.x = data->player->pos.x;
	start_pos.y = data->player->pos.y;
	
	end_pos.x = data->player->pos.x + data->player->dir.x * NOSE_LENGTH;
	end_pos.y = data->player->pos.y + data->player->dir.y * NOSE_LENGTH;
	
    draw_filled_circle(data, start_pos, PLAYER_SIZE, COLOUR_YELLOW);
	draw_line(data, start_pos, end_pos, COLOUR_GREEN);
}

void	draw_2D_map(t_data *data)
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
			offset.x = (x * GRIDSIZE) + x;
			offset.y = (y * GRIDSIZE) + y;
			if (data->map->map[y][x] == '1')
			{	
				colour = COLOUR_WHITE;
			}
			else 
			{	
				colour = COLOUR_BLACK;
			}
			draw_filled_square(data, offset, GRIDSIZE, GRIDSIZE, colour);
			x++;
		}
		y++;
	}
}

void	game(t_data *data)
{
	draw_2D_map(data);
	draw_player(data);
	raycasting(data);
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
	
	fill_canvas(data);
	game(data);
	
	mlx_loop_hook(data->window, key_is_pressed, data);
	mlx_loop(data->window);
	mlx_terminate(data->window);
}