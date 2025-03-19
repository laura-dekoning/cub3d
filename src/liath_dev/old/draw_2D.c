/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_2D.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: livliege <livliege@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/17 14:15:33 by livliege      #+#    #+#                 */
/*   Updated: 2025/03/17 14:15:33 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include "../../incl/liath.h"


// void	draw_eye(t_data *data, mlx_image_t *image, t_vector_f player_centre, int colour)
// {
// 	t_vector_f	eye_centre;
// 	t_vector_f	dir;
// 	float		angle;

// 	angle = data->player->angle - (80.0 * ONE_D_RADIAN);
// 	dir.x = cos(angle);
// 	dir.y = sin(angle);
// 	eye_centre.x = player_centre.x + dir.x * (PLAYER_SIZE / 1.8);
// 	eye_centre.y = player_centre.y + dir.y * (PLAYER_SIZE / 1.8);
// 	draw_filled_circle(image, eye_centre, (PLAYER_SIZE / 5), colour);
// }


// void	draw_mouth(t_data *data, mlx_image_t *image, t_vector_f start_pos, int colour)
// {
// 	t_vector_f end_pos;
// 	t_vector_f dir;
// 	float angle;
// 	float angle_step;
// 	float fov;
// 	int i;

// 	fov = 60.0;
// 	angle = data->player->angle - ((fov / 2) * ONE_D_RADIAN);
// 	angle_step = (fov * ONE_D_RADIAN) / NUMB_RAYS;
// 	i = 0;
// 	while (i < NUMB_RAYS)
// 	{
// 		dir.x = cos(angle);
// 		dir.y = sin(angle);
// 		end_pos.x = start_pos.x + dir.x * (PLAYER_SIZE + 1);
// 		end_pos.y = start_pos.y + dir.y * (PLAYER_SIZE + 1);
// 		draw_line(image, start_pos, end_pos, colour);
// 		angle += angle_step;
// 		if (angle > (2 * PI))
// 			angle -= (2 * PI);
// 		if (angle < 0)		
// 			angle += (2 * PI);
// 		i++;
// 	}


// // i need to figure out how to open and close the mouth hihi
// 	// draw_filled_circle(image, data->player->pos, PLAYER_SIZE, COLOUR_YELLOW);

// 	// end_pos.x = start_pos.x + data->player->dir.x * ((PLAYER_SIZE / 2) + 1);
// 	// end_pos.y = start_pos.y + data->player->dir.y * ((PLAYER_SIZE / 2) + 1);
// 	// draw_line(image, start_pos, end_pos, COLOUR_AQUA);
// }

// void	draw_player(t_data *data, mlx_image_t *image)
// {	
// 	draw_filled_circle(image, data->player->pos, PLAYER_SIZE, COLOUR_YELLOW);
// 	draw_circle(image, data->player->pos, PLAYER_SIZE, COLOUR_BLACK);
// 	// draw_circle(image, data->player->pos, PLAYER_SIZE + 1, COLOUR_BLACK);
// 	draw_mouth(data, image, data->player->pos, COLOUR_BLACK);
// 	draw_eye(data, image, data->player->pos, COLOUR_BLACK);
// }

// void	draw_2D_map(t_data *data, mlx_image_t *image)
// {
// 	int x;
// 	int y;
// 	t_vector_f offset;
// 	uint64_t colour;
	
// 	y = 0;
// 	while (y < data->map->rows)
// 	{
// 		x = 0;
// 		while (x < data->map->cols)
// 		{
// 			// offset.x = (x * GRIDSIZE) + x;
// 			// offset.y = (y * GRIDSIZE) + y;
// 			offset.x = x * GRIDSIZE;
// 			offset.y = y * GRIDSIZE;
// 			if (data->map->map[y][x] == '1')
// 			{	
// 				colour = COLOUR_BLACK;
// 			}
// 			else 
// 			{	
// 				colour = COLOUR_LIGHT_GRAY;
// 			}
// 			draw_filled_square(image, offset, GRIDSIZE, GRIDSIZE, colour);
// 			x++;
// 		}
// 		y++;
// 	}
// }


//=========================================================================



// void	fill_canvas(t_data *data)
// {
// 	uint32_t	x;
// 	uint32_t	y;

// 	y = 0;
// 	while (y < data->window_image->height)
// 	{
// 		x = 0;
// 		while (x < data->window_image->width)
// 		{
// 			mlx_put_pixel(data->window_image, x, y, COLOUR_GRAY);
// 			x++;
// 		}
// 		y++;
// 	}
// }

// void	draw_filled_square(mlx_image_t *image, t_vector_f start_pos, uint32_t width, uint32_t height, uint64_t colour)
// {
// 	uint32_t	x;
// 	uint32_t	y;

// 	y = start_pos.y;
// 	while (y < start_pos.y + height)
// 	{
// 		x = start_pos.x;
// 		while (x < start_pos.x + width)
// 		{
// 			if (x < image->width && y < image->height)
// 				mlx_put_pixel(image, x, y, colour);
// 			x++;
// 		}
// 		y++;
// 	}
// }

// void draw_filled_circle(mlx_image_t	*image, t_vector_f centre, int radius, int colour) 
// {
// 	int x;
// 	int y;
	
// 	y = -radius;
// 	while (y <= radius) 
// 	{
// 		x = -radius;
// 		while (x <= radius) 
// 		{
// 			if ((centre.x + x >= 0 && centre.y + y >= 0 && centre.x + x < (int)image->width && centre.y + y < (int)image->height) && (x * x + y * y <= radius * radius)) // Check if the point is inside the circle
// 			{
// 				mlx_put_pixel(image, centre.x + x, centre.y + y, colour);
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// }

// void	draw_line(mlx_image_t *image, t_vector_f start, t_vector_f end, uint64_t colour)
// {
// 	float	step_x;
// 	float	step_y;
// 	float	max;

// 	//get total length
// 	step_x = end.x - start.x;
// 	step_y = end.y - start.y;
// 	//get amount of steps
// 	max = get_max(fabsf(step_x), fabsf(step_y));	// fabsf() returns the absolute value of a float
// 	// get step length for x and y
// 	step_x /= max;
// 	step_y /= max;
// 	// compare ints because floats are unreliable
// 	while ((int)(start.x - end.x) || (int)(start.y - end.y))
// 	{
// 		if (start.x >= 0 && start.y >= 0 && start.x < (int)image->width && start.y < (int)image->height)
// 			mlx_put_pixel(image, start.x, start.y, colour);
// 		start.x += step_x;
// 		start.y += step_y;
// 	}
// }
// int message_i = 0;		// TAKE OUT

// void	draw_player(t_data *data)
// {
// 	// t_vector_f start_pos;
// 	// t_vector_f end_pos;

// 	// start_pos.x = data->player->pos.x;
// 	// start_pos.y = data->player->pos.y;
// 	// end_pos.x = data->player->pos.x + data->player->dir.x * (PLAYER_SIZE * 3);
// 	// end_pos.y = data->player->pos.y + data->player->dir.y * (PLAYER_SIZE * 3);
// 	// draw_filled_circle(data->minimap_image, start_pos, PLAYER_SIZE, COLOUR_YELLOW);
// 	// draw_line(data->minimap_image, start_pos, end_pos, COLOUR_GREEN);
	
// 	t_vector_f player_centre;
// 	t_vector_f nose_end_pos;

// 	// Center player in minimap
// 	player_centre.x = MINIMAP_WIDTH / 2;
// 	player_centre.y = MINIMAP_HEIGHT / 2;
// 	nose_end_pos.x = player_centre.x + data->player->dir.x * (PLAYER_SIZE * 3);
// 	nose_end_pos.y = player_centre.y + data->player->dir.y * (PLAYER_SIZE * 3);

// 	draw_filled_circle(data->minimap_image, player_centre, PLAYER_SIZE, COLOUR_YELLOW);
// 	draw_line(data->minimap_image, player_centre, nose_end_pos, COLOUR_GREEN);
// }

// void	draw_2D_map(t_data *data)
// {
// 	int x;
// 	int y;
// 	t_vector_f offset;
// 	t_vector_f minimap_offset;
// 	uint64_t colour;
	
// 	minimap_offset.x = data->player->pos.x - MINIMAP_WIDTH / 2;
// 	minimap_offset.y = data->player->pos.y - MINIMAP_HEIGHT / 2;
	
// 	draw_filled_square(data->minimap_image, (t_vector_f){0, 0}, MINIMAP_WIDTH, MINIMAP_HEIGHT, COLOUR_DARK_GRAY);

// 	y = 0;
// 	while (y < data->map->rows)
// 	{
// 		x = 0;
// 		while (x < data->map->cols)
// 		{
// 		// to draw minimap with gridlines (but this causes problems with the rays):
// 			// offset.x = (x * GRIDSIZE) + x;
// 			// offset.y = (y * GRIDSIZE) + y;
// 			offset.x = (x * GRIDSIZE) - minimap_offset.x;
// 			offset.y = (y * GRIDSIZE) - minimap_offset.y;

// 			// if (offset.x + GRIDSIZE > 0 && offset.y + GRIDSIZE > 0 && offset.x < MINIMAP_WIDTH && offset.y < MINIMAP_HEIGHT)
// 			if (offset.x + GRIDSIZE > -GRIDSIZE && offset.y + GRIDSIZE > -GRIDSIZE && offset.x < MINIMAP_WIDTH + GRIDSIZE && offset.y < MINIMAP_HEIGHT + GRIDSIZE)
// 			{
// 				if (data->map->map[y][x] == '1')
// 				{	
// 					colour = COLOUR_BLACK;
// 				}
// 				else
// 				{	
// 					colour = COLOUR_LIGHT_GRAY;
// 				}
// 				draw_filled_square(data->minimap_image, offset, GRIDSIZE, GRIDSIZE, colour);
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// 	// Draw border
// 	colour = COLOUR_WHITE;
// 	draw_filled_square(data->minimap_image, (t_vector_f){0, 0}, MINIMAP_WIDTH, 2, colour);
// 	draw_filled_square(data->minimap_image, (t_vector_f){0, MINIMAP_HEIGHT - 2}, MINIMAP_WIDTH, 2, colour);
// 	draw_filled_square(data->minimap_image, (t_vector_f){0, 0}, 2, MINIMAP_HEIGHT, colour);
// 	draw_filled_square(data->minimap_image, (t_vector_f){MINIMAP_WIDTH - 2, 0}, 2, MINIMAP_HEIGHT, colour);
// }

// void	game(t_data *data)
// {
// 	draw_2D_map(data);
// 	raycasting(data);
// 	draw_player(data);
// }

// void	init_window(t_data *data)
// {
// 	data->window = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, false);
// 	if (data->window == NULL)
// 	{
// 		error_and_exit("Window could not be created\n");
// 	}
// 	data->window_image = mlx_new_image(data->window, WINDOW_WIDTH, WINDOW_HEIGHT);
// 	if (data->window_image == NULL)
// 	{
// 		mlx_terminate(data->window);
// 		error_and_exit("Image could not be created\n");
// 	}
// 	data->minimap_image = mlx_new_image(data->window, MINIMAP_WIDTH, MINIMAP_HEIGHT);
// 	if (data->minimap_image == NULL)
// 	{
// 		mlx_terminate(data->window);
// 		error_and_exit("Image could not be created\n");
// 	}
	
// 	if (mlx_image_to_window(data->window, data->window_image, 0, 0) < 0)
// 	{
// 		mlx_terminate(data->window);
// 		error_and_exit("Image could not be displayed on the window\n");
// 	}
// 	if (mlx_image_to_window(data->window, data->minimap_image, 0, 0) < 0)
// 	{
// 		mlx_terminate(data->window);
// 		error_and_exit("Image could not be displayed on the window\n");
// 	}

// 	fill_canvas(data);
// 	game(data);
	
// 	mlx_loop_hook(data->window, key_is_pressed, data);
// 	mlx_loop(data->window);
// 	mlx_terminate(data->window);
// }





