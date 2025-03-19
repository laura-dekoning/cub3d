/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minimap.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: livliege <livliege@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/15 20:25:33 by livliege      #+#    #+#                 */
/*   Updated: 2025/03/20 00:09:12 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "../../incl/liath.h"

void	set_minimap_colours(t_data *data)
{
	data->minimap.wall_colour = COLOUR_BLUE;
	data->minimap.floor_colour = COLOUR_YELLOW;
	data->minimap.player_colour = COLOUR_PINK;
	data->minimap.border_colour = COLOUR_GREEN;
}

void	draw_border(t_data *data)
{
	uint64_t colour;
	int size;
	
	size = 5;
	colour = data->minimap.border_colour;
	draw_filled_square(data->minimap_image, (t_vector_i){0, 0}, MINIMAP_WIDTH, size, colour);
	draw_filled_square(data->minimap_image, (t_vector_i){0, MINIMAP_HEIGHT - size}, MINIMAP_WIDTH, size, colour);
	draw_filled_square(data->minimap_image, (t_vector_i){0, 0}, size, MINIMAP_HEIGHT, colour);
	draw_filled_square(data->minimap_image, (t_vector_i){MINIMAP_WIDTH - size, 0}, size, MINIMAP_HEIGHT, colour);
}
	
void	draw_eye(t_data *data, t_vector_f player_centre, int colour)
{
	t_vector_f	eye_centre;
	t_vector_f	dir;
	float		angle;

	angle = data->player.angle - (80.0 * ONE_D_RADIAN);
	dir.x = cos(angle);
	dir.y = sin(angle);
	eye_centre.x = player_centre.x + dir.x * (PLAYER_SIZE / 1.8);
	eye_centre.y = player_centre.y + dir.y * (PLAYER_SIZE / 1.8);
	draw_filled_circle(data->minimap_image, eye_centre, (PLAYER_SIZE / 5), colour);
}

void	draw_rays(t_data *data, int colour)
{
	t_vector_f start_pos;
	t_vector_f end_pos;
	t_vector_f dir;
	float angle;
	float angle_step;
	int i;

	start_pos = data->player.pos;
	angle = data->player.angle - ((FOV / 2) * ONE_D_RADIAN);
	angle_step = (FOV * ONE_D_RADIAN) / NUMB_RAYS;
	i = 0;
	while (i < NUMB_RAYS)
	{
		dir.x = cos(angle);
		dir.y = sin(angle);
		end_pos.x = start_pos.x + dir.x * data->ray[i].distance;
		end_pos.y = start_pos.y + dir.y * data->ray[i].distance;
		draw_line(data->minimap_image, start_pos, end_pos, colour);
		angle += angle_step;
		if (angle > (2 * PI))
			angle -= (2 * PI);
		if (angle < 0)		
			angle += (2 * PI);
		i++;
	}
}

// void	draw_mouth(t_data *data, t_vector_f start_pos, int colour)
// {
// 	t_vector_f end_pos;
// 	t_vector_f dir;
// 	float angle;
// 	float angle_step;
// 	float fov;
// 	int i;

// 	fov = 60.0;
// 	angle = data->player.angle - ((fov / 2) * ONE_D_RADIAN);
// 	angle_step = (fov * ONE_D_RADIAN) / NUMB_RAYS;
// 	i = 0;
// 	while (i < NUMB_RAYS)
// 	{
// 		dir.x = cos(angle);
// 		dir.y = sin(angle);
// 		end_pos.x = start_pos.x + dir.x * (PLAYER_SIZE + 1);
// 		end_pos.y = start_pos.y + dir.y * (PLAYER_SIZE + 1);
// 		draw_line(data->minimap_image, start_pos, end_pos, colour);
// 		angle += angle_step;
// 		if (angle > (2 * PI))
// 			angle -= (2 * PI);
// 		if (angle < 0)		
// 			angle += (2 * PI);
// 		i++;
// 	}


// // i need to figure out how to open and close the mouth hihi
// 	// draw_filled_circle(data->minimap_image, data->player.pos, PLAYER_SIZE, COLOUR_YELLOW);

// 	// end_pos.x = start_pos.x + data->player->dir.x * ((PLAYER_SIZE / 2) + 1);
// 	// end_pos.y = start_pos.y + data->player->dir.y * ((PLAYER_SIZE / 2) + 1);
// 	// draw_line(data->minimap_image, start_pos, end_pos, COLOUR_AQUA);
// }

void	draw_player(t_data *data)
{	
	draw_filled_circle(data->minimap_image, data->player.pos, PLAYER_SIZE, data->minimap.player_colour);
	// draw_mouth(data, data->player.pos, COLOUR_BLACK);
	draw_eye(data, data->player.pos, COLOUR_BLACK);
	draw_circle(data->minimap_image, data->player.pos, PLAYER_SIZE, COLOUR_BLACK);
	
	draw_rays(data, data->minimap.ray_colour);
	
}



void	draw_2D_map(t_data *data)
{
	int x;
	int y;
	t_vector_i offset;
	// t_vector_i minimap_offset;
	uint64_t colour;
	
	// minimap_offset.x = data->player.pos.x - MINIMAP_WIDTH / 2;
	// minimap_offset.y = data->player.pos.y - MINIMAP_HEIGHT / 2;
	
	y = 0;
	while (y < data->map->rows)
	{
		x = 0;
		while (x < data->map->cols)
		{
		// to draw minimap with gridlines (but this causes problems with the rays):
			// offset.x = (x * GRIDSIZE_MM) + x;
			// offset.y = (y * GRIDSIZE_MM) + y;
			offset.x = (x * GRIDSIZE_MM); // - minimap_offset.x;
			offset.y = (y * GRIDSIZE_MM); // - minimap_offset.y;

			// if (offset.x + GRIDSIZE_MM > -GRIDSIZE_MM && offset.y + GRIDSIZE_MM > -GRIDSIZE_MM && offset.x < MINIMAP_WIDTH + GRIDSIZE_MM && offset.y < MINIMAP_HEIGHT + GRIDSIZE_MM)
			if (offset.x + GRIDSIZE_MM > 0 && offset.y + GRIDSIZE_MM > 0 && offset.x < MINIMAP_WIDTH && offset.y < MINIMAP_HEIGHT)
			{
				if (data->map->map[y][x] == '1')
				{	
					colour = data->minimap.wall_colour;
				}
				else
				{	
					colour = data->minimap.floor_colour;
				}
				draw_filled_square(data->minimap_image, offset, GRIDSIZE_MM, GRIDSIZE_MM, colour);
			}
			x++;
		}
		y++;
	}
}


void	minimap(t_data *data)
{

	
	set_minimap_colours(data);
	
	draw_filled_square(data->minimap_image, (t_vector_i){0, 0}, MINIMAP_WIDTH, MINIMAP_HEIGHT, COLOUR_DARK_GRAY);
	
	draw_2D_map(data);
	draw_player(data);
	draw_border(data);

}