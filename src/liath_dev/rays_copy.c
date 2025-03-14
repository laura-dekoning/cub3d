
# include "../../incl/liath.h"

void draw_ray(t_data *data, t_ray ray)
{
	while (!ray.wall_hit) // && ray.distance < ray.max_distance)
	{
		if (ray.collision_point.x < ray.collision_point.y)
		{
			ray.map_pos.x += ray.step.x;
			ray.distance = ray.collision_point.x;
			ray.collision_point.x += ray.ray_unit_step_size.x;
		}
		else
		{
			ray.map_pos.y += ray.step.y;
			ray.distance = ray.collision_point.y;
			ray.collision_point.y += ray.ray_unit_step_size.y;
		}
		if (ray.map_pos.x >= 0 && ray.map_pos.y >= 0 && ray.map_pos.x < data->minimap_size.x && ray.map_pos.y < data->minimap_size.y)
		{
			if (data->map->map[(int)(ray.map_pos.y / GRIDSIZE)][(int)(ray.map_pos.x / GRIDSIZE)] == '1')
				ray.wall_hit = true;
		}
	}
	if (ray.wall_hit)
	{
		ray.ray_end.x = ray.ray_start.x + ray.ray_dir.x * ray.distance;
		ray.ray_end.y = ray.ray_start.y + ray.ray_dir.y * ray.distance;
		draw_line(data, ray.ray_start, ray.ray_end, COLOUR_RED);
	}
}

void get_ray_collision(t_ray ray)
{
	if (ray.ray_dir.x < 0)
	{
		ray.step.x = -1;
		ray.collision_point.x = (ray.ray_start.x - (float)ray.map_pos.x) * ray.ray_unit_step_size.x;
	}
	else 
	{
		ray.step.x = 1;
		ray.collision_point.x = (((float)ray.map_pos.x + 1.0) - ray.ray_start.x) * ray.ray_unit_step_size.x;
	}
	if (ray.ray_dir.y < 0)
	{
		ray.step.y = -1;
		ray.collision_point.y = (ray.ray_start.y - (float)ray.map_pos.y) * ray.ray_unit_step_size.y;
	}
	else 
	{
		ray.step.y = 1;
		ray.collision_point.y = (((float)ray.map_pos.y + 1.0) - ray.ray_start.y) * ray.ray_unit_step_size.y;
	}
}

void init_ray(t_data *data, t_ray ray)
{
	ray.ray_start = data->player->pos;
	ray.ray_dir = data->player->dir;
	ray.ray_unit_step_size.x = sqrt(1 + (ray.ray_dir.y / ray.ray_dir.x) * (ray.ray_dir.y / ray.ray_dir.x));
	ray.ray_unit_step_size.y = sqrt(1 + (ray.ray_dir.x / ray.ray_dir.y) * (ray.ray_dir.x / ray.ray_dir.y));
	ray.map_pos.x = (int)(data->player->pos.x);
	ray.map_pos.y = (int)(data->player->pos.y);
	ray.wall_hit = false;
	ray.distance = 0.0;
}
float normalize_angle(float a)
{
	if (a > 359.0)
	{
		a -= 360.0;
	}
	if ( a < 0.0)
	{
		a += 360.0;
	}
	return (a);
}

void raycasting(t_data *data)
{

	t_ray ray;

	init_ray(data, ray);	
	get_ray_collision(ray);
	draw_ray(data, ray);

	// t_ray ray[60];
	// t_vector_f dir;
	// float angle;
	// int i;


	// angle = data->player->angle;
	// i = 0;
	// while (i < 60)
	// {
		
	// 	dir.x = normalize_angle(cos(angle - (30 * ONE_DEGREE))); // * ROTATE_SPEED;
	// 	dir.y = normalize_angle(sin(angle - (30 * ONE_DEGREE))); // * ROTATE_SPEED;

	// 	init_ray(data, ray[i], dir);	
	// 	get_ray_collision(ray[i]);
	// 	draw_ray(data, ray[i]);

	// 	angle += (30 * ONE_DEGREE);
	// 	i++;
	// }
}
