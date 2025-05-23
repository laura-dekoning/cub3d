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

void	dda_aggorithm(t_game *game, t_ray *ray, t_vector_f map_pos)
{
	while (ray->wall_hit == false)
	{
		if (ray->collision_point.x < ray->collision_point.y)
		{
			map_pos.x += ray->step_dir.x;
			ray->distance = ray->collision_point.x;
			ray->collision_point.x += ray->step_size.x;
			ray->wall_3d.n_s_wall = false;
		}
		else
		{
			map_pos.y += ray->step_dir.y;
			ray->distance = ray->collision_point.y;
			ray->collision_point.y += ray->step_size.y;
			ray->wall_3d.n_s_wall = true;
		}
		if (map_pos.x >= 0 && map_pos.y >= 0 && map_pos.x < \
			game->map->map_width_px && map_pos.y < game->map->map_height_px)
		{
			if (game->map->map[(int)(map_pos.y / GRIDSIZE)] \
			[(int)(map_pos.x / GRIDSIZE)] == '1')
				ray->wall_hit = true;
		}
	}
}

void	cast_ray(t_game *game, t_ray *ray, t_vector_f map_pos)
{
	dda_aggorithm(game, ray, map_pos);
	ray->end_pos.x = ray->start_pos.x + ray->direction.x * ray->distance;
	ray->end_pos.y = ray->start_pos.y + ray->direction.y * ray->distance;
}

void	get_ray_direction(t_game *game, t_ray *ray, t_vector_f *map_pos)
{
	if (map_pos->x < 0 || map_pos->x >= game->map->map_width_px || \
		map_pos->y < 0 || map_pos->y >= game->map->map_height_px)
		return ;
	if (ray->direction.x < 0)
	{
		get_collision_point_negative_x(ray, map_pos->x);
	}
	else
	{
		get_collision_point_positive_x(ray, map_pos->x);
	}
	if (ray->direction.y < 0)
	{
		get_collision_point_negative_y(ray, map_pos->y);
	}
	else
	{
		get_collision_point_positive_y(ray, map_pos->y);
	}
}

void	init_ray(t_game *game, t_ray *ray, float ang, t_vector_f *map_pos)
{
	ray->start_pos = game->player->pos;
	map_pos->x = (int)(ray->start_pos.x);
	map_pos->y = (int)(ray->start_pos.y);
	ray->angle = ang;
	ray->direction.x = cos(ray->angle);
	ray->direction.y = sin(ray->angle);
	if (ray->direction.x == 0)
		ray->step_size.x = 1.0e30;
	else
		ray->step_size.x = sqrt(1 + (ray->direction.y / ray->direction.x) * \
		(ray->direction.y / ray->direction.x));
	if (ray->direction.y == 0)
		ray->step_size.y = 1.0e30;
	else
		ray->step_size.y = sqrt(1 + (ray->direction.x / ray->direction.y) * \
		(ray->direction.x / ray->direction.y));
	ray->wall_hit = false;
	ray->distance = 0.0;
	get_ray_direction(game, ray, map_pos);
}

void	raycasting(t_game *game)
{
	t_vector_f	map_pos;
	float		angle;
	float		angle_step;
	int			i;

	angle = game->player->angle - ((FOV / 2) * ONE_D_RADIAN);
	angle_step = (FOV * ONE_D_RADIAN) / NUMB_RAYS;
	i = 0;
	while (i < NUMB_RAYS)
	{
		game->ray[i].index = i;
		init_ray(game, &game->ray[i], angle, &map_pos);
		cast_ray(game, &game->ray[i], map_pos);
		init_wall_segment(game, &game->ray[i]);
		render_3d_wall_segment(game, &game->ray[i]);
		angle += angle_step;
		check_angle(&angle);
		i++;
	}
}
