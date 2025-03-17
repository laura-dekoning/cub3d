/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rays.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: livliege <livliege@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/17 14:15:11 by livliege      #+#    #+#                 */
/*   Updated: 2025/03/17 14:15:11 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */



#include "../../incl/liath.h"

void draw_ray(t_data *data, t_ray *ray)
{
	while (!ray->wall_hit)
	{
		if (ray->collision_point.x < ray->collision_point.y)
		{
			ray->map_pos.x += ray->step.x;
			ray->distance = ray->collision_point.x;
			ray->collision_point.x += ray->ray_unit_step_size.x;
		}
		else
		{
			ray->map_pos.y += ray->step.y;
			ray->distance = ray->collision_point.y;
			ray->collision_point.y += ray->ray_unit_step_size.y;
		}
		if (ray->map_pos.x >= 0 && ray->map_pos.y >= 0 && ray->map_pos.x < data->minimap_size.x && ray->map_pos.y < data->minimap_size.y)
		{
			if (data->map->map[(int)(ray->map_pos.y / GRIDSIZE)][(int)(ray->map_pos.x / GRIDSIZE)] == '1')
				ray->wall_hit = true;
		}
	}
	if (ray->wall_hit)
	{
		ray->ray_end.x = ray->ray_start.x + ray->ray_dir.x * ray->distance;
		ray->ray_end.y = ray->ray_start.y + ray->ray_dir.y * ray->distance;
		draw_line(data->minimap_image, ray->ray_start, ray->ray_end, COLOUR_RED);
	}
}

void get_ray_collision(t_data *data, t_ray *ray)
{
	float x_offset;
	float y_offset;


// minimap rays are off by a few pixels.. playing with the offset seems to help but i cant figure it out..
	// x_offset = (data->map->rows - 1);
	// y_offset = (data->map->cols - 1);
	x_offset = 0.0;
	y_offset = 0.0;
	// x_offset = floor((ray->map_pos.x / GRIDSIZE) + 1.0);
	// y_offset = floor((ray->map_pos.y / GRIDSIZE) + 1.0);
	
	if (ray->map_pos.x < 0 || ray->map_pos.x >= data->map->cols * GRIDSIZE || ray->map_pos.y < 0 || ray->map_pos.y >= data->map->rows * GRIDSIZE)
    	return;
	if (ray->ray_dir.x < 0)
	{
		ray->step.x = -1;
		ray->collision_point.x = (ray->ray_start.x - (float)(ray->map_pos.x)) * ray->ray_unit_step_size.x;
	}
	else 
	{
		ray->step.x = 1;
		ray->collision_point.x = ((float)((ray->map_pos.x + 1.0) + x_offset) - ray->ray_start.x) * ray->ray_unit_step_size.x;
	}
	if (ray->ray_dir.y < 0)
	{
		ray->step.y = -1;
		ray->collision_point.y = (ray->ray_start.y - (float)(ray->map_pos.y)) * ray->ray_unit_step_size.y;
	}
	else 
	{
		ray->step.y = 1;
		ray->collision_point.y = ((float)((ray->map_pos.y + 1.0) + y_offset) - ray->ray_start.y) * ray->ray_unit_step_size.y;
	}
}

void init_ray(t_data *data, t_ray *ray, t_vector_f dir)
{
	ray->ray_start = data->player->pos;
	ray->map_pos.x = (int)(data->player->pos.x);
	ray->map_pos.y = (int)(data->player->pos.y);
	ray->ray_dir = dir;
	ray->ray_unit_step_size.x = sqrt(1 + (ray->ray_dir.y / ray->ray_dir.x) * (ray->ray_dir.y / ray->ray_dir.x));
	ray->ray_unit_step_size.y = sqrt(1 + (ray->ray_dir.x / ray->ray_dir.y) * (ray->ray_dir.x / ray->ray_dir.y));
	ray->wall_hit = false;
	ray->distance = 0.0;
}

void raycasting(t_data *data)
{
	t_ray ray[NUMB_RAYS];
	t_vector_f dir;
	float angle;
	float angle_step;
	float fov;
	int i;

	fov = 60.0;
	angle = data->player->angle - ((fov / 2) * ONE_DEGREE);
	angle_step = (fov * ONE_DEGREE) / NUMB_RAYS;
	i = 0;
	while (i < NUMB_RAYS)
	{
		dir.x = cos(angle);
		dir.y = sin(angle);

		init_ray(data, &ray[i], dir);	
		get_ray_collision(data, &ray[i]);
		draw_ray(data, &ray[i]);

		draw_3d_wall(data, &ray[i], i, angle);

		angle += angle_step;
		if (angle > (2 * PI))
		{
			angle -= (2 * PI);
		}
		if (angle < 0)
		{			
			angle += (2 * PI);
		}
		i++;
	}
}

