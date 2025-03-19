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
