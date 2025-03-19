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

// DDA algorithm
void get_ray_distance(t_data *data, t_ray *ray, t_vector_f *current_map_pos)
{
	while (!ray->wall_hit)
	{
		if (ray->collision_point.x < ray->collision_point.y)
		{
			current_map_pos->x += ray->step_dir.x;
			ray->distance = ray->collision_point.x;
			ray->collision_point.x += ray->step_size.x;
			ray->N_S_wall = false;		
		}
		else
		{
			current_map_pos->y += ray->step_dir.y;
			ray->distance = ray->collision_point.y;
			ray->collision_point.y += ray->step_size.y;
			ray->N_S_wall = true;
		}
		if (current_map_pos->x >= 0 && current_map_pos->y >= 0 && current_map_pos->x < data->map->map_width_px && current_map_pos->y < data->map->map_height_px)
		{
			if (data->map->map[(int)(current_map_pos->y / GRIDSIZE)][(int)(current_map_pos->x / GRIDSIZE)] == '1')
				ray->wall_hit = true;
		}
	}
	if (ray->wall_hit)
	{
		// for the minimap:
		ray->end_pos.x = ray->start_pos.x + ray->direction.x * ray->distance;
		ray->end_pos.y = ray->start_pos.y + ray->direction.y * ray->distance;
		


		// if (ray->horiztonal_wall == true)
		// {
		// 	if (ray->step_dir.y < 0)
		// 	{
		// 		ray->wall_side = NORTH;
		// 	}
		// 	else
		// 	{
		// 		ray->wall_side = SOUTH;
		// 	}
		// }
		// else
		// {
		// 	if (ray->step_dir.x < 0)
		// 	{
		// 		ray->wall_side = WEST;
		// 	}
		// 	else
		// 	{
		// 		ray->wall_side = EAST;
		// 	}
		// }
	
	}
}

void get_ray_collision(t_data *data, t_ray *ray, t_vector_f *current_map_pos)
{
	if (current_map_pos->x < 0 || current_map_pos->x >= data->map->map_width_px || current_map_pos->y < 0 || current_map_pos->y >= data->map->map_height_px)
    	return;
	if (ray->direction.x < 0)
	{
		ray->step_dir.x = -1;
		ray->collision_point.x = (ray->start_pos.x - (float)current_map_pos->x) * ray->step_size.x;
	}
	else 
	{
		ray->step_dir.x = 1;
		ray->collision_point.x = (((float)current_map_pos->x + 1.0) - ray->start_pos.x) * ray->step_size.x;
	}
	if (ray->direction.y < 0)
	{
		ray->step_dir.y = -1;
		ray->collision_point.y = (ray->start_pos.y - (float)current_map_pos->y) * ray->step_size.y;
	}
	else 
	{
		ray->step_dir.y = 1;
		ray->collision_point.y = (((float)current_map_pos->y + 1.0) - ray->start_pos.y) * ray->step_size.y;
	}
}

void init_ray(t_data *data, t_ray *ray, t_vector_f dir, float ang, t_vector_f *current_map_pos)
{
	current_map_pos->x = (int)(data->player.pos.x);
	current_map_pos->y = (int)(data->player.pos.y);
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
}

void raycasting(t_data *data)
{
	t_vector_f current_map_pos;
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
		init_ray(data, &data->ray[i], dir, angle, &current_map_pos);
		get_ray_collision(data, &data->ray[i], &current_map_pos);
		get_ray_distance(data, &data->ray[i], &current_map_pos);
		cast_ray(data, &data->ray[i], i, angle);
		angle += angle_step;
		if (angle > (2 * PI))
			angle -= (2 * PI);
		if (angle < 0)
			angle += (2 * PI);
		i++;
	}
}
