
# include "../../incl/liath.h"


void draw_rays2D(t_data *data)
{
	int 		rays;
	t_vector 	m;
	int 		mp;
	int 		dof;
	t_vector 	radius;
	float		radius_angle;
	float		x_offset;
	float		y_offset;
	float 		a_tan;

	radius_angle = data->player->angle;

	rays = 0;
	while(rays < 1)
	{
		// check horezontal lines
		dof = 0;
		a_tan = -1 / tan(radius_angle);

		// looking up
		if (radius_angle > PI)
		{
			radius.y = (((int)data->player->pos.y >> 6) << 6) - 0.0001; // >>6 <<6 only works on GRIDSIZE 64
			radius.x = data->player->pos.y - radius.y * a_tan + data->player->pos.x;
			y_offset = -GRIDSIZE;
			x_offset = -y_offset * a_tan;
		}
		// looking down
		if (radius_angle < PI)
		{
			radius.y = (((int)data->player->pos.y >> 6) << 6) + GRIDSIZE;  // >>6 <<6 only works on GRIDSIZE 64
			radius.x = data->player->pos.y - radius.y * a_tan + data->player->pos.x;
			y_offset = GRIDSIZE;
			x_offset = -y_offset * a_tan;
		}
		// looking straight left and right
		if (radius_angle == 0 || radius_angle == PI)
		{
			radius.x = data->player->pos.x;
			radius.y = data->player->pos.y;
			dof = 8;	// probably only works with gridsize 64
		}
		while (dof < 8) // probably only works with gridsize 64
		{
			m.x = (int)radius.x >> 6; // probably only works with gridsize 64
			m.y = (int)radius.y >> 6; // probably only works with gridsize 64
			mp = m.y * data->map->cols + m.x;
			if (mp < data->map->cols * data->map->rows && data->map->map[mp][mp] == '1') // hit wall
			{
				dof = 8;	// probably only works with gridsize 64
			}
			else // next line
			{
				radius.x += x_offset;
				radius.x += x_offset;
				dof += 1;
			}
		} 

		rays++;
	}

}
