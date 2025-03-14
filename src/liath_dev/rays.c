# include "../../incl/liath.h"


void draw_3d_wall(t_data *data, t_ray *ray, int ray_i, float angle)
{
	// float		line_hight;
    float		proj_plane_dist;
	float		corrected_distance;
    float		wall_height;
    int			wall_top;
    int			wall_bottom;
	t_vector_f 	start;
	t_vector_f 	end;
	int slice_width;
	int screen_x;
	int	i;

	proj_plane_dist = (data->window->width / 2) / tan((90.0 * ONE_DEGREE) / 2);

	corrected_distance = ray[ray_i].distance * cos(angle - data->player->angle);
	wall_height = (GRIDSIZE * proj_plane_dist) / corrected_distance;
	// wall_top = (data->window->height / 2) - (wall_height / 2);
	// wall_bottom = (data->window->height / 2) + (wall_height / 2);

	wall_top = max(0, (data->window->height / 2) - (wall_height / 2));
	wall_bottom = min(data->window->height, (data->window->height / 2) + (wall_height / 2));
	
	slice_width = data->window->width / NUMB_RAYS;
	i = 0;
	while (i < slice_width)
	{
		screen_x = ray_i * slice_width + i;
		if (screen_x >= data->window->width)
			break;
		start.x = ray_i * slice_width + i;
		start.y = wall_top;
		end.x = ray_i * slice_width + i;
		end.y = wall_bottom;
		draw_line(data, start, end, COLOUR_BLUE);
		i++;
	}
}


void draw_ray(t_data *data, t_ray *ray)
{
	while (!ray->wall_hit) // && ray->distance < ray->max_distance)
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
		draw_line(data, ray->ray_start, ray->ray_end, COLOUR_RED);
	}
}

void get_ray_collision(t_data *data, t_ray *ray)
{
	if (ray->map_pos.x < 0 || ray->map_pos.x >= data->map->cols * GRIDSIZE || ray->map_pos.y < 0 || ray->map_pos.y >= data->map->rows * GRIDSIZE)
    	return;
	if (ray->ray_dir.x < 0)
	{
		ray->step.x = -1;
		ray->collision_point.x = (ray->ray_start.x - (float)ray->map_pos.x) * ray->ray_unit_step_size.x;
	}
	else 
	{
		ray->step.x = 1;
		ray->collision_point.x = (((float)ray->map_pos.x + 1.0) - ray->ray_start.x) * ray->ray_unit_step_size.x;
	}
	if (ray->ray_dir.y < 0)
	{
		ray->step.y = -1;
		ray->collision_point.y = (ray->ray_start.y - (float)ray->map_pos.y) * ray->ray_unit_step_size.y;
	}
	else 
	{
		ray->step.y = 1;
		ray->collision_point.y = (((float)ray->map_pos.y + 1.0) - ray->ray_start.y) * ray->ray_unit_step_size.y;
	}
}

// void init_ray(t_data *data, t_ray *ray)
// {
// 	ray->ray_start = data->player->pos;
// 	ray->ray_dir = data->player->dir;
// 	ray->ray_unit_step_size.x = sqrt(1 + (ray->ray_dir.y / ray->ray_dir.x) * (ray->ray_dir.y / ray->ray_dir.x));
// 	ray->ray_unit_step_size.y = sqrt(1 + (ray->ray_dir.x / ray->ray_dir.y) * (ray->ray_dir.x / ray->ray_dir.y));
// 	ray->map_pos.x = (int)(data->player->pos.x);
// 	ray->map_pos.y = (int)(data->player->pos.y);
// 	ray->wall_hit = false;
// 	ray->distance = 0.0;
// }

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

	// t_ray ray;

	// init_ray(data, &ray);	
	// get_ray_collision(&ray);
	// draw_ray(data, &ray);

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





// void raycasting(t_data *data)
// {
// 	float 		camera_X;
// 	t_vector_f	ray_dir;
// 	t_vector_f	map_pos;
// 	t_vector_f	side_dist;
// 	t_vector_f	delta_dist;
// 	bool		hit;
// 	int			side;
// 	double		perpWallDist;	// change name
// 	int			step_x;
// 	int			step_y;

// 	int x;

// 	x = 0;
// 	while (x < data->map->cols * GRIDSIZE)
// 	{
// 		camera_X = 2 * x / (data->map->cols * GRIDSIZE) - 1.0;
// 		ray_dir.x = data->player->dir.x + data->player->plane.x * camera_X;
// 		ray_dir.y = data->player->dir.y + data->player->plane.y * camera_X;
	    
// 		//which box of the map we're in
// 		map_pos.x = (int)(data->player->pos.x / GRIDSIZE);
// 		map_pos.y = (int)(data->player->pos.y / GRIDSIZE);
    	

// 		//length of ray from one x or y-side to next x or y-side
// 		if (ray_dir.x == 0)	// looking straight left/right
// 		{
// 			delta_dist.x = data->map->cols * GRIDSIZE;
// 		}
// 		else
// 		{
// 			delta_dist.x = fabsf(1 / ray_dir.x);
// 		}
// 		if (ray_dir.y == 0)	// looking straight up/down
// 		{
// 			delta_dist.y = data->map->rows * GRIDSIZE;
// 		}
// 		else
// 		{
// 			delta_dist.y = fabsf(1 / ray_dir.y);
// 		}


// 		//calculate step and initial sideDist
// 		if (ray_dir.x < 0)
// 		{
// 			step_x = -1;
// 			side_dist.x = (data->player->pos.x - map_pos.x) * delta_dist.x;
// 		}
// 		else 
// 		{
// 			step_x = 1;
// 			side_dist.x = (map_pos.x + 1.0 - data->player->pos.x) * delta_dist.x;
// 		}
// 		if (ray_dir.y < 0)
// 		{
// 			step_y = -1;
// 			side_dist.y = (data->player->pos.y - map_pos.y) * delta_dist.y;
// 		}
// 		else 
// 		{
// 			step_y = 1;
// 			side_dist.y = (map_pos.y + 1.0 - data->player->pos.y) * delta_dist.y;
// 		}

// 		hit = false;

// 		while(hit == false)
// 		{
// 			//jump to next map square, either in x-direction, or in y-direction
// 			if(side_dist.x < side_dist.y)
// 			{
// 				side_dist.x += delta_dist.x;
// 				map_pos.x += step_x;
// 				side = 0;
// 			}
// 			else
// 			{
// 				side_dist.y += delta_dist.y;
// 				map_pos.y += step_y;
// 				side = 1;
// 			}
// 			//Check if ray has hit a wall
// 			// if (data->map->map[(int)map_pos.y][(int)map_pos.x] == '1')
// 			if (data->map->map[(int)map_pos.y][(int)map_pos.x] == '1')
// 			{
// 				hit = true;
// 				t_vector_f end_pos;
// 				end_pos.x = map_pos.x * GRIDSIZE;
// 				end_pos.y = map_pos.y * GRIDSIZE;
// 				draw_line(data, data->player->pos, end_pos, COLOUR_RED);
// 			}
// 		}
// 		x++;

// 	}
// }
// 	t_vector_f	start_pos;
// 	t_vector_f	end_pos;
// 	t_vector_f	ray_dir;
// 	float		angle;
// 	float		field_of_view;
// 	int			rays;
// 	int 		i;
	
// 	start_pos.x = data->player->pos.x;
// 	start_pos.y = data->player->pos.y;
// 	ray_dir.x = data->player->dir.x;
// 	ray_dir.y = data->player->dir.y;
// 	field_of_view = 90.0;
// 	rays = 30;
// 	i = 0;
// 	while (i < rays)
// 	{
// 		angle = data->player->angle + (i - (rays / 2)) * (field_of_view / (field_of_view / 3));
// 		if (angle > (2 * PI))
// 			angle -= (2 * PI);
// 		if (angle < 0)
// 			angle += (2 * PI);
// 		ray_dir.x = cos(angle); //  * ROTATE_SPEED;
// 		ray_dir.y = sin(angle); //  * ROTATE_SPEED;
// 		end_pos.x = start_pos.x + ray_dir.x * 50;
// 		end_pos.y = start_pos.y + ray_dir.y * 50;
// 		draw_line(data, start_pos, end_pos, COLOUR_RED);
// 		i++;
// 	}
// }


// void draw_rays2D(t_data *data)
// {
// 	int 		rays;
// 	t_vector_f 	m;
// 	int 		mp;
// 	int 		dof;
// 	t_vector_f 	radius;
// 	float		radius_angle;
// 	float		x_offset;
// 	float		y_offset;
// 	float 		a_tan;

// 	radius_angle = data->player->angle;

// 	rays = 0;
// 	while(rays < 1)
// 	{
// 		// check horezontal lines
// 		dof = 0;
// 		a_tan = -1 / tan(radius_angle);

// 		// looking up
// 		if (radius_angle > PI)
// 		{
// 			radius.y = (((int)data->player->pos.y >> 6) << 6) - 0.0001; // >>6 <<6 only works on GRIDSIZE 64
// 			radius.x = data->player->pos.y - radius.y * a_tan + data->player->pos.x;
// 			y_offset = -GRIDSIZE;
// 			x_offset = -y_offset * a_tan;
// 		}
// 		// looking down
// 		if (radius_angle < PI)
// 		{
// 			radius.y = (((int)data->player->pos.y >> 6) << 6) + GRIDSIZE;  // >>6 <<6 only works on GRIDSIZE 64
// 			radius.x = data->player->pos.y - radius.y * a_tan + data->player->pos.x;
// 			y_offset = GRIDSIZE;
// 			x_offset = -y_offset * a_tan;
// 		}
// 		// looking straight left and right
// 		if (radius_angle == 0 || radius_angle == PI)
// 		{
// 			radius.x = data->player->pos.x;
// 			radius.y = data->player->pos.y;
// 			dof = 8;	// probably only works with gridsize 64
// 		}
// 		while (dof < 8) // probably only works with gridsize 64
// 		{
// 			m.x = (int)radius.x >> 6; // probably only works with gridsize 64
// 			m.y = (int)radius.y >> 6; // probably only works with gridsize 64
// 			mp = m.y * data->map->cols + m.x;
// 			if (mp < data->map->cols * data->map->rows && data->map->map[mp][mp] == '1') // hit wall
// 			{
// 				dof = 8;	// probably only works with gridsize 64
// 			}
// 			else // next line
// 			{
// 				radius.x += x_offset;
// 				radius.x += x_offset;
// 				dof += 1;
// 			}
// 		} 

// 		rays++;
// 	}

// }
