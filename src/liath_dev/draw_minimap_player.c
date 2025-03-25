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

# include "../../incl/liath.h"

void	draw_eye(t_data *data, t_vector_f player_centre, int colour)
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

void	draw_rays(t_data *data, int colour)
{
	t_vector_f start_pos;
	t_vector_f end_pos;
	t_vector_f dir;
	float angle;
	float angle_step;
	int i;

	start_pos = data->minimap.player_pos;
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
		end_pos.x = start_pos.x + dir.x * (data->minimap.player_size + 1);
		end_pos.y = start_pos.y + dir.y * (data->minimap.player_size + 1);
		draw_line(data->minimap_image, start_pos, end_pos, colour);
		angle += angle_step;
		if (angle > (2 * PI))
			angle -= (2 * PI);
		if (angle < 0)		
			angle += (2 * PI);
		i++;
	}

// i need to figure out how to open and close the mouth hihi
	// draw_filled_circle(data->minimap_image, data->minimap.player_pos, data->minimap.player_size, COLOUR_YELLOW);

	// end_pos.x = start_pos.x + data->player->dir.x * ((data->minimap.player_size / 2) + 1);
	// end_pos.y = start_pos.y + data->player->dir.y * ((data->minimap.player_size / 2) + 1);
	// draw_line(data->minimap_image, start_pos, end_pos, COLOUR_AQUA);
}

void	draw_player(t_data *data)
{
	draw_rays(data, data->minimap.ray_colour);
	draw_filled_circle(data->minimap_image, data->minimap.player_pos, data->minimap.player_size, data->minimap.player_colour);
	draw_mouth(data, data->minimap.player_pos, COLOUR_BLACK);
	draw_eye(data, data->minimap.player_pos, COLOUR_BLACK);
	draw_circle(data->minimap_image, data->minimap.player_pos, data->minimap.player_size, COLOUR_BLACK);
}
