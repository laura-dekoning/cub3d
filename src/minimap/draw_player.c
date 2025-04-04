/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_minimap_player.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: livliege <livliege@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/24 16:06:00 by livliege      #+#    #+#                 */
/*   Updated: 2025/03/24 16:06:00 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void	draw_eye(t_game *data, t_vector_f player_centre, int colour)
{
	t_vector_f	eye_centre;
	t_vector_f	dir;
	float		angle;

	angle = data->player.angle - (80.0 * ONE_D_RADIAN);
	dir.x = cos(angle);
	dir.y = sin(angle);
	eye_centre.x = player_centre.x + dir.x * (data->minimap.player_size / 1.8);
	eye_centre.y = player_centre.y + dir.y * (data->minimap.player_size / 1.8);
	draw_filled_circle(data->minimap_image, eye_centre, (data->minimap.player_size / 5), colour);
}

void	draw_rays(t_game *data, int colour)
{
	t_vector_f	start_pos;
	t_vector_f	end_pos;
	t_vector_f	dir;
	float		angle;
	float		angle_step;
	int			i;

	start_pos = data->minimap.player_pos;
	angle = data->player.angle - ((FOV / 2) * ONE_D_RADIAN);
	angle_step = (FOV * ONE_D_RADIAN) / NUMB_RAYS;
	i = 0;
	while (i < NUMB_RAYS)
	{
		dir.x = cos(angle);
		dir.y = sin(angle);
		end_pos.x = (start_pos.x + dir.x * (data->ray[i].distance / GRIDSIZE) * data->minimap.grid_size);
		end_pos.y = (start_pos.y + dir.y * (data->ray[i].distance / GRIDSIZE) * data->minimap.grid_size);
		draw_line(data->minimap_image, start_pos, end_pos, colour);
		angle += angle_step;
		check_angle(&angle);
		i++;
	}
}

void	draw_arrow_head(t_game *data,  t_vector_f start_pos, t_vector_f end_pos, t_vector_f dir, int colour)
{
	float	arrow_length;
	float	arrow_angle;
	float	arrow_head_size;
	uint8_t	arrow_head_pointyness;

	arrow_head_size = 0.7;
	arrow_head_pointyness = 40;	// the arrow will look like 2 * arrow_head_pointyness degrees. for example arrow_head_pointyness = 45 will make an arrowhead of 90 degrees (quarter circle). for more pointy you have to go lower.
	arrow_length = data->minimap.grid_size * arrow_head_size;
	arrow_angle = arrow_head_pointyness * ONE_D_RADIAN;
	
	dir.x = cos(data->player.angle + PI + arrow_angle);
	dir.y = sin(data->player.angle + PI + arrow_angle);
	start_pos.x = end_pos.x + dir.x * arrow_length;
	start_pos.y = end_pos.y + dir.y * arrow_length;
	draw_line(data->minimap_image, end_pos, start_pos, colour);
	
	dir.x = cos(data->player.angle + PI - arrow_angle);
	dir.y = sin(data->player.angle + PI - arrow_angle);
	start_pos.x = end_pos.x + dir.x * arrow_length;
	start_pos.y = end_pos.y + dir.y * arrow_length;
	draw_line(data->minimap_image, end_pos, start_pos, colour);
}
	
void	draw_arrow(t_game *data, int colour)
{
	t_vector_f 	start_pos;
	t_vector_f 	end_pos;
	t_vector_f 	dir;
	float 		angle;
	float 		angle_step;
	int 		i;

	start_pos = data->minimap.player_pos;
	angle = data->player.angle;
	angle_step = (FOV * ONE_D_RADIAN) / NUMB_RAYS;
	i = (NUMB_RAYS / 2); 
	dir.x = cos(angle);
	dir.y = sin(angle);
	end_pos.x = start_pos.x + dir.x * (data->ray[i].distance / GRIDSIZE) * data->minimap.grid_size;
	end_pos.y = start_pos.y + dir.y * (data->ray[i].distance / GRIDSIZE) * data->minimap.grid_size;
	draw_line(data->minimap_image, start_pos, end_pos, colour);
	angle += angle_step;
	check_angle(&angle);
	draw_arrow_head(data, start_pos, end_pos, dir, colour);
}


void	draw_mouth(t_game *data, t_vector_f start_pos, int colour)
{
	t_vector_f	end_pos;
	t_vector_f	dir;
	float		angle;
	float		angle_step;
	float		fov;
	int			i;

	fov = 60.0;
	angle = data->player.angle - ((fov / 2) * ONE_D_RADIAN);
	angle_step = (fov * ONE_D_RADIAN) / NUMB_RAYS;
	i = 0;
	while (i < NUMB_RAYS)
	{
		dir.x = cos(angle);
		dir.y = sin(angle);
		end_pos.x = start_pos.x + dir.x * (data->minimap.player_size + 1);
		end_pos.y = start_pos.y + dir.y * (data->minimap.player_size + 1);
		draw_line(data->minimap_image, start_pos, end_pos, colour);
		angle += angle_step;
		check_angle(&angle);
		i++;
	}
}

void	draw_player(t_game *data)
{
	draw_rays(data, data->minimap.ray_colour);
	draw_arrow(data, data->minimap.arrow_colour);
	draw_filled_circle(data->minimap_image, data->minimap.player_pos, data->minimap.player_size, data->minimap.player_colour);
	draw_mouth(data, data->minimap.player_pos, COLOUR_BLACK);
	draw_eye(data, data->minimap.player_pos, COLOUR_BLACK);
	draw_circle(data->minimap_image, data->minimap.player_pos, data->minimap.player_size, COLOUR_BLACK);
}
