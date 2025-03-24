/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minimap.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: livliege <livliege@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/15 20:25:33 by livliege      #+#    #+#                 */
/*   Updated: 2025/03/24 13:21:27 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "../../incl/liath.h"

// void init_border_vectors(t_data *data)
// {
	
// }

void	draw_border(t_data *data)
{
	t_vector_i	top_line_start;
	t_vector_i	top_line_end;
	t_vector_i	bottom_line_start;
	t_vector_i	bottom_line_end;
	t_vector_i	left_line_start;
	t_vector_i	left_line_end;
	t_vector_i	right_line_start;
	t_vector_i	right_line_end;
	uint64_t	colour;

	top_line_start.x = 0;
	top_line_start.y = 0;
	top_line_end.x = data->minimap_image->width;
	top_line_end.y = data->minimap.border_size;
	bottom_line_start.x = 0;
	bottom_line_start.y = data->minimap_image->height - data->minimap.border_size;
	bottom_line_end.x = data->minimap_image->width;
	bottom_line_end.y = data->minimap_image->height;
	left_line_start.x = 0;
	left_line_start.y = 0;
	left_line_end.x = data->minimap.border_size;
	left_line_end.y = data->minimap_image->height;
	right_line_start.x = data->minimap_image->width - data->minimap.border_size;
	right_line_start.y = 0;
	right_line_end.x = data->minimap_image->width;
	right_line_end.y = data->minimap_image->height;

	colour = data->minimap.border_colour;

	draw_filled_rectangle(data->minimap_image, top_line_start, top_line_end, colour);
	draw_filled_rectangle(data->minimap_image, bottom_line_start, bottom_line_end, colour);
	draw_filled_rectangle(data->minimap_image, left_line_start, left_line_end, colour);
	draw_filled_rectangle(data->minimap_image, right_line_start, right_line_end, colour);
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

void	draw_mouth(t_data *data, t_vector_f start_pos, int colour)
{
	t_vector_f end_pos;
	t_vector_f dir;
	float angle;
	float angle_step;
	float fov;
	int i;

	fov = 60.0;
	angle = data->player.angle - ((fov / 2) * ONE_D_RADIAN);
	angle_step = (fov * ONE_D_RADIAN) / NUMB_RAYS;
	i = 0;
	while (i < NUMB_RAYS)
	{
		dir.x = cos(angle);
		dir.y = sin(angle);
		end_pos.x = start_pos.x + dir.x * (PLAYER_SIZE + 1);
		end_pos.y = start_pos.y + dir.y * (PLAYER_SIZE + 1);
		draw_line(data->minimap_image, start_pos, end_pos, colour);
		angle += angle_step;
		if (angle > (2 * PI))
			angle -= (2 * PI);
		if (angle < 0)		
			angle += (2 * PI);
		i++;
	}


// i need to figure out how to open and close the mouth hihi
	// draw_filled_circle(data->minimap_image, data->player.pos, PLAYER_SIZE, COLOUR_YELLOW);

	// end_pos.x = start_pos.x + data->player->dir.x * ((PLAYER_SIZE / 2) + 1);
	// end_pos.y = start_pos.y + data->player->dir.y * ((PLAYER_SIZE / 2) + 1);
	// draw_line(data->minimap_image, start_pos, end_pos, COLOUR_AQUA);
}

void	draw_player(t_data *data)
{	
	draw_rays(data, data->minimap.ray_colour);
	draw_filled_circle(data->minimap_image, data->player.pos, PLAYER_SIZE, data->minimap.player_colour);
	draw_mouth(data, data->player.pos, COLOUR_BLACK);
	draw_eye(data, data->player.pos, COLOUR_BLACK);
	draw_circle(data->minimap_image, data->player.pos, PLAYER_SIZE, COLOUR_BLACK);
}

// this version the map gets drawn sort of how i want it, but the player collision is very off (player runs into a wall while on the minimap it looks like we still have space.)
// also the map blocks only get drawn nce the whole block will fit in the screen, i want half of te block drawn as well.
// void	draw_2D_map(t_data *data)
// {
// 	int x;
// 	int y;
// 	t_vector_i offset;
// 	t_vector_i minimap_offset;
// 	uint64_t colour;
	
// 	// Center the minimap around the player
// 	minimap_offset.x = (int)(data->player.pos.x * GRIDSIZE_MM / GRIDSIZE_3D) - (data->minimap.minimap_size / 2);
// 	minimap_offset.y = (int)(data->player.pos.y * GRIDSIZE_MM / GRIDSIZE_3D) - (data->minimap.minimap_size / 2);
	
// 	// Adjust for small maps so they’re centered
// 	if (data->map->cols * GRIDSIZE_MM < data->minimap.minimap_size)
// 		minimap_offset.x = -(data->minimap.minimap_size - (data->map->cols * GRIDSIZE_MM)) / 2;
// 	if (data->map->rows * GRIDSIZE_MM < data->minimap.minimap_size)
// 		minimap_offset.y = -(data->minimap.minimap_size - (data->map->rows * GRIDSIZE_MM)) / 2;
	

// 	float scale = 1.0;
// 	if (data->map->cols > 8 || data->map->rows > 8)
// 		scale = (float)data->minimap.minimap_size / (data->map->cols * GRIDSIZE_MM);
	
// 	// Adjust GRIDSIZE_MM with the scaling factor
// 	int scaled_size = (int)(GRIDSIZE_MM * scale);

// 	y = 0;
// 	while (y < data->map->rows)
// 	{
// 		x = 0;
// 		while (x < data->map->cols)
// 		{
// 			offset.x = (x * scaled_size) - minimap_offset.x;
// 			offset.y = (y * scaled_size) - minimap_offset.y;
	
// 			if (offset.x + scaled_size > 0 && offset.y + scaled_size > 0 &&
// 				offset.x < data->minimap.minimap_size && offset.y < data->minimap.minimap_size)
// 			{
// 				if (data->map->map[y][x] == '1')
// 					colour = data->minimap.wall_colour;
// 				else
// 					colour = data->minimap.floor_colour;
	
// 				draw_filled_rectangle(data->minimap_image, offset, scaled_size, scaled_size, colour);
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// }

// // this version the walls and floor are the same colour, but the walls (player collision) is on the right track.
// void draw_2D_map(t_data *data)
// {
//	int x;
//	int y;
//	t_vector_i offset;
//	uint64_t colour;

//	// Calculate dynamic tile size to fit 8x8 grid or smaller
//	int max_tiles = 8;
//	int grid_size = GRIDSIZE_MM;
//	if (data->map->cols > max_tiles || data->map->rows > max_tiles)
//		grid_size = data->minimap.minimap_size / max_tiles;
//	else
//		grid_size = data->minimap.minimap_size / data->map->cols;

//	// Center the map around the player
//	int map_width_px = data->map->cols * grid_size;
//	int map_height_px = data->map->rows * grid_size;
//	int offset_x = (data->minimap.minimap_size - map_width_px) / 2 - (data->player.pos.x * grid_size - data->minimap.minimap_size / 2);
//	int offset_y = (data->minimap.minimap_size - map_height_px) / 2 - (data->player.pos.y * grid_size - data->minimap.minimap_size / 2);

//	y = 0;
//	while (y < data->map->rows)
//	{
//		x = 0;
//		while (x < data->map->cols)
//		{
//			offset.x = x * grid_size + offset_x;
//			offset.y = y * grid_size + offset_y;

//			if (offset.x + grid_size > 0 && offset.y + grid_size > 0 && offset.x < data->minimap.minimap_size && offset.y < data->minimap.minimap_size)
//			{
//				if (data->map->map[y][x] == '1')
//				{
//					colour = data->minimap.wall_colour;
//				}
//				else
//				{
//					colour = data->minimap.floor_colour;
//				}
//				draw_filled_rectangle(data->minimap_image, offset, grid_size, grid_size, colour);
//			}
//			x++;
//		}
//		y++;
//	}
// }

// this version works but only draws the top right part of the map and the player moves "out of the map"

/*
plan:
- get location on the map of the player.
- draw x amount of wall or floor blocks around the player
- easy peasy 

- also GRIDSIZE_MM moet waarschijnlijk afhangen van de size of the minimap en dat kan geen define zijn.
*/
void	draw_2D_map(t_data *data)
{
	int x;
	int y;
	t_vector_i start_pos;
	t_vector_i end_pos;
	uint64_t colour;

	y = 0;
	while (y < data->map->rows)
	{
		x = 0;
		while (x < data->map->cols)
		{
			start_pos.x = (x * GRIDSIZE_MM); // + x; 	(to draw minimap with gridlines (skips a pixel every row and col))
			start_pos.y = (y * GRIDSIZE_MM); // + y; 	(but this causes problems with the rays) (i can do it later on top of the map if i want to)
			if (start_pos.x + GRIDSIZE_MM > 0 && start_pos.y + GRIDSIZE_MM > 0 && start_pos.x < data->minimap.minimap_size && start_pos.y < data->minimap.minimap_size)
			{
				if (data->map->map[y][x] == '1')
				{	
					colour = data->minimap.wall_colour;
				}
				else
				{	
					colour = data->minimap.floor_colour;
				}
				end_pos.x = start_pos.x + GRIDSIZE_MM;
				end_pos.y = start_pos.y + GRIDSIZE_MM;
				draw_filled_rectangle(data->minimap_image, start_pos, end_pos, colour);
			}
			x++;
		}
		y++;
	}
}

void	draw_minimap_background(t_data *data)
{
	t_vector_i start_pos;
	t_vector_i end_pos;
	
	start_pos.x = 0;
	start_pos.y = 0;
	end_pos.x = start_pos.x + data->minimap.minimap_size;
	end_pos.y = start_pos.y + data->minimap.minimap_size;
	
	draw_filled_rectangle(data->minimap_image, start_pos, end_pos, data->minimap.back_ground_colour);
}

void	minimap(t_data *data)
{
	draw_minimap_background(data);
	
	draw_2D_map(data);
	draw_player(data);
	draw_border(data);
}
