
# include "../../incl/liath.h"

void draw_rays(t_data *data)
{

}


void raycasting(t_data *data)
{
	t_vector_f	ray_start;
	t_vector_f	ray_end;
	t_vector_f	ray_dir;
	t_vector_f	ray_unit_step_size;

	t_vector_i	map_pos;

	t_vector_f	collision_point; // x will store length to collision with vertical grid_lines, y horizontally
	t_vector_i	step;
	

	ray_start = data->player->pos;
	ray_dir = data->player->dir;
	ray_unit_step_size.x = sqrt(1 + (ray_dir.y / ray_dir.x) * (ray_dir.y / ray_dir.x));
	ray_unit_step_size.y = sqrt(1 + (ray_dir.x / ray_dir.y) * (ray_dir.x / ray_dir.y));

	map_pos.x = (int)(data->player->pos.x);
	map_pos.y = (int)(data->player->pos.y);


		//calculate step and initial sideDist
	if (ray_dir.x < 0)
	{
		step.x = -1;
		collision_point.x = (ray_start.x - (float)map_pos.x) * ray_unit_step_size.x;
	}
	else 
	{
		step.x = 1;
		collision_point.x = (((float)map_pos.x + 1.0) - ray_start.x) * ray_unit_step_size.x;
	}
	if (ray_dir.y < 0)
	{
		step.y = -1;
		collision_point.y = (ray_start.y - (float)map_pos.y) * ray_unit_step_size.y;
	}
	else 
	{
		step.y = 1;
		collision_point.y = (((float)map_pos.y + 1.0) - ray_start.y) * ray_unit_step_size.y;
	}



	bool	wall_hit;
	float 	distance;
	float 	max_distance;	

	wall_hit = false;
	distance = 0.0;
	max_distance = 1000.0;	
	while (!wall_hit && distance < max_distance)
	{
		// walk
		if (collision_point.x < collision_point.y)
		{
			map_pos.x += step.x;
			distance = collision_point.x;
			collision_point.x += ray_unit_step_size.x;
		}
		else
		{
			map_pos.y += step.y;
			distance = collision_point.y;
			collision_point.y += ray_unit_step_size.y;
		}

		if (map_pos.x >= 0 && map_pos.y >= 0 && map_pos.x < data->minimap_size.x && map_pos.y < data->minimap_size.y)
		{
			if (data->map->map[(int)(map_pos.y / GRIDSIZE)][(int)(map_pos.x / GRIDSIZE)] == '1')
			{
				wall_hit = true;
			}
		}
	}

	if (wall_hit)
	{
		ray_end.x = ray_start.x + ray_dir.x * distance;
		ray_end.y = ray_start.y + ray_dir.y * distance;
		draw_line(data, ray_start, ray_end, COLOUR_RED);
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
