/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   collision_points.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/04 17:09:44 by livliege      #+#    #+#                 */
/*   Updated: 2025/04/23 14:23:39 by livliege      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_collision_point_negative_x(t_ray *ray, float map_pos_x)
{
	ray->step_dir.x = -1;
	ray->collision_point.x = (ray->start_pos.x - (float)map_pos_x) * \
	ray->step_size.x;
}

void	get_collision_point_positive_x(t_ray *ray, float map_pos_x)
{
	ray->step_dir.x = 1;
	ray->collision_point.x = (((float)map_pos_x + 1.0) - ray->start_pos.x) * \
	ray->step_size.x;
}

void	get_collision_point_negative_y(t_ray *ray, float map_pos_y)
{
	ray->step_dir.y = -1;
	ray->collision_point.y = (ray->start_pos.y - (float)map_pos_y) * \
	ray->step_size.y;
}

void	get_collision_point_positive_y(t_ray *ray, float map_pos_y)
{
	ray->step_dir.y = 1;
	ray->collision_point.y = (((float)map_pos_y + 1.0) - ray->start_pos.y) * \
	ray->step_size.y;
}
