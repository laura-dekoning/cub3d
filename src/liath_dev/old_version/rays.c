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

void get_ray_distance(t_data *data, t_ray *ray)
{
	while (!ray->wall_hit)
	{
		if (ray->collision_point.x < ray->collision_point.y)
		{
			ray->map_pos.x += ray->step.x;
			ray->distance = ray->collision_point.x;
			ray->collision_point.x += ray->step_size.x;
		}
		else
		{
			ray->map_pos.y += ray->step.y;
			ray->distance = ray->collision_point.y;
			ray->collision_point.y += ray->step_size.y;
		}
		if (ray->map_pos.x >= 0 && ray->map_pos.y >= 0 && ray->map_pos.x < data->minimap_size.x && ray->map_pos.y < data->minimap_size.y)
		{
			if (data->map->map[(int)(ray->map_pos.y / GRIDSIZE)][(int)(ray->map_pos.x / GRIDSIZE)] == '1')
				ray->wall_hit = true;
		}
	}
	if (ray->wall_hit)
	{
		ray->end_pos.x = ray->start_pos.x + ray->direction.x * ray->distance;
		ray->end_pos.y = ray->start_pos.y + ray->direction.y * ray->distance;
		draw_line(data->minimap_image, ray->start_pos, ray->end_pos, COLOUR_RED);
	}
}

void get_ray_collision(t_data *data, t_ray *ray)
{
	if (ray->map_pos.x < 0 || ray->map_pos.x >= data->map->cols * GRIDSIZE || ray->map_pos.y < 0 || ray->map_pos.y >= data->map->rows * GRIDSIZE)
    	return;
	if (ray->direction.x < 0)
	{
		ray->step.x = -1;
		ray->collision_point.x = (ray->start_pos.x - (float)(ray->map_pos.x)) * ray->step_size.x;
	}
	else 
	{
		ray->step.x = 1;
		ray->collision_point.x = (float)((ray->map_pos.x + 1.0) - ray->start_pos.x) * ray->step_size.x;
	}
	if (ray->direction.y < 0)
	{
		ray->step.y = -1;
		ray->collision_point.y = (ray->start_pos.y - (float)(ray->map_pos.y)) * ray->step_size.y;
	}
	else 
	{
		ray->step.y = 1;
		ray->collision_point.y = (float)((ray->map_pos.y + 1.0) - ray->start_pos.y) * ray->step_size.y;
	}
}

void init_ray(t_data *data, t_ray *ray, t_vector_f dir)
{
	ray->start_pos = data->player->pos;
	ray->map_pos.x = (int)(data->player->pos.x);
	ray->map_pos.y = (int)(data->player->pos.y);
	ray->direction = dir;
	if (ray->direction.x == 0)
		ray->step_size.x = 1.0e30;
	else
		ray->step_size.x = sqrt(1 + (ray->direction.y / ray->direction.x) * (ray->direction.y / ray->direction.x));
	if (ray->direction.y == 0)
		ray->step_size.y = 1.0e30;
	else
		ray->step_size.y = sqrt(1 + (ray->direction.x / ray->direction.y) * (ray->direction.x / ray->direction.y));
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
		init_ray(data, &data->ray[i], dir);	
		get_ray_collision(data, &data->ray[i]);
		get_ray_distance(data, &data->ray[i]);
		draw_3d_wall(data, &data->ray[i], i, angle);
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


