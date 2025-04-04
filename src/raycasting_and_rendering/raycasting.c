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

#include "cub3d.h"

void DDA_aggorithm(t_game *data, t_ray *ray, t_vector_f *map_pos)
{
	while (ray->wall_hit == false)
	{
		if (ray->collision_point.x < ray->collision_point.y)
		{
			map_pos->x += ray->step_dir.x;
			ray->distance = ray->collision_point.x;
			ray->collision_point.x += ray->step_size.x;
			ray->wall_3d.n_s_wall = false;		
		}
		else
		{
			map_pos->y += ray->step_dir.y;
			ray->distance = ray->collision_point.y;
			ray->collision_point.y += ray->step_size.y;
			ray->wall_3d.n_s_wall = true;
		}
		if (map_pos->x >= 0 && map_pos->y >= 0 && map_pos->x < data->map->map_width_px && map_pos->y < data->map->map_height_px)
		{
			if (data->map->map[(int)(map_pos->y / GRIDSIZE)][(int)(map_pos->x / GRIDSIZE)] == '1')
			ray->wall_hit = true;
		}
	}
}

void cast_ray(t_game *data, t_ray *ray, t_vector_f *map_pos)
{
	DDA_aggorithm(data, ray, map_pos);
	ray->end_pos.x = ray->start_pos.x + ray->direction.x * ray->distance;
	ray->end_pos.y = ray->start_pos.y + ray->direction.y * ray->distance;		
}

// get ray step direction and collision point with the next horixontal or vertical line
void get_ray_direction(t_game *data, t_ray *ray, t_vector_f *map_pos)
{
	if (map_pos->x < 0 || map_pos->x >= data->map->map_width_px || map_pos->y < 0 || map_pos->y >= data->map->map_height_px)
    	return;
	if (ray->direction.x < 0)
	{
		ray->step_dir.x = -1;
		ray->collision_point.x = (ray->start_pos.x - (float)map_pos->x) * ray->step_size.x;
	}
	else 
	{
		ray->step_dir.x = 1;
		ray->collision_point.x = (((float)map_pos->x + 1.0) - ray->start_pos.x) * ray->step_size.x;
	}
	if (ray->direction.y < 0)
	{
		ray->step_dir.y = -1;
		ray->collision_point.y = (ray->start_pos.y - (float)map_pos->y) * ray->step_size.y;
	}
	else 
	{
		ray->step_dir.y = 1;
		ray->collision_point.y = (((float)map_pos->y + 1.0) - ray->start_pos.y) * ray->step_size.y;
	}
}

void init_ray(t_game *data, t_ray *ray, t_vector_f dir, float ang, t_vector_f *map_pos)
{
	map_pos->x = (int)(data->player.pos.x);
	map_pos->y = (int)(data->player.pos.y);
	ray->start_pos = data->player.pos;
	ray->direction = dir;
	ray->angle = ang;
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
	get_ray_direction(data, ray, map_pos);
}

void raycasting(t_game *data)
{
	t_vector_f map_pos;
	t_vector_f dir;
	float angle;
	float angle_step;
	int i;

	angle = data->player.angle - ((FOV / 2) * ONE_D_RADIAN);
	angle_step = (FOV * ONE_D_RADIAN) / NUMB_RAYS;
	i = 0;
	while (i < NUMB_RAYS)
	{
		dir.x = cos(angle);
		dir.y = sin(angle);
		init_ray(data, &data->ray[i], dir, angle, &map_pos);
		cast_ray(data, &data->ray[i], &map_pos);
		init_wall_segment(data, &data->ray[i]);
		render_3d_wall_segment(data, &data->ray[i], i);
		angle += angle_step;
		check_angle(&angle);
		i++;
	}
}
