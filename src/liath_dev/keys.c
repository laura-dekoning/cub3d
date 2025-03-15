/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keys.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: livliege <livliege@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/07 14:41:47 by livliege      #+#    #+#                 */
/*   Updated: 2025/03/15 16:07:11 by livliege      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "../../incl/liath.h"


// 	// close window 									-> escape
// 	// look left and right in the maze					-> left and right key
// 	// move the point of view through the maze (walk)	-> w, s, d, a

bool check_collision(t_data *data, float next_x, float next_y)
{
	t_vector_f corners[4];
	int i;
	int map_pos_x;
	int map_pos_y;
	
	// Top-left
	corners[0].x = next_x - PLAYER_SIZE;
	corners[0].y = next_y - PLAYER_SIZE;
	// Top-right
	corners[1].x = next_x + PLAYER_SIZE;
	corners[1].y = next_y - PLAYER_SIZE;
	// Bottom-left
	corners[2].x = next_x - PLAYER_SIZE;
	corners[2].y = next_y + PLAYER_SIZE;
	// Bottom-right
	corners[3].x = next_x + PLAYER_SIZE;
	corners[3].y = next_y + PLAYER_SIZE;
	i = 0; 
	while (i < 4)
	{
		map_pos_x = (int)(corners[i].x / GRIDSIZE);
		map_pos_y = (int)(corners[i].y / GRIDSIZE);

		if (data->map->map[map_pos_y][map_pos_x] == '1')
		{
			return true;
		}
		i++;
	}
	return false;
}

void rotation_keys(t_data *data)
{
	if (mlx_is_key_down(data->window, MLX_KEY_LEFT))
	{
		data->player->angle -= 0.1;
		if (data->player->angle < 0)
		{
			data->player->angle += (2 * PI);
		}
		data->player->dir.x = cos(data->player->angle) * ROTATE_SPEED;
		data->player->dir.y = sin(data->player->angle) * ROTATE_SPEED;
	}
	if (mlx_is_key_down(data->window, MLX_KEY_RIGHT))
	{
		data->player->angle += 0.1;
		if (data->player->angle > (2 * PI))
		{
			data->player->angle -= (2 * PI);
		}
		data->player->dir.x = cos(data->player->angle) * ROTATE_SPEED;
		data->player->dir.y = sin(data->player->angle) * ROTATE_SPEED;
	}
}

void movement_keys(t_data *data, float *next_x, float *next_y)
{
	float step_x;
	float step_y;
	
	// Calculate Movement
	step_x = 0.0;
	step_y = 0.0;
	if (mlx_is_key_down(data->window, MLX_KEY_W))
	{
		step_x += data->player->dir.x;
		step_y += data->player->dir.y;
	}
	if (mlx_is_key_down(data->window, MLX_KEY_S))
	{
		step_x -= data->player->dir.x;
		step_y -= data->player->dir.y;
	}
	if (mlx_is_key_down(data->window, MLX_KEY_A))
	{
		step_x += data->player->dir.y;
		step_y -= data->player->dir.x;
	}
	if (mlx_is_key_down(data->window, MLX_KEY_D))
	{
		step_x -= data->player->dir.y;
		step_y += data->player->dir.x;
	}
	
	// Calculate New Position
	*next_x = data->player->pos.x + step_x * MOVING_SPEED;
	*next_y = data->player->pos.y + step_y * MOVING_SPEED;
}

void key_action(t_data *data)
{
	float next_x;
	float next_y;

	// Exit Program
	if (mlx_is_key_down(data->window, MLX_KEY_ESCAPE))
		mlx_close_window(data->window);

	rotation_keys(data);
	movement_keys(data, &next_x, &next_y);

	if (!check_collision(data, next_x, data->player->pos.y))
		data->player->pos.x = next_x;
	if (!check_collision(data, data->player->pos.x, next_y))
		data->player->pos.y = next_y;
}


void	key_is_pressed(void *game_data)
{
	t_data		*data;
	t_vector_f	player_pos;
	t_vector_f	player_dir;
	int			player_moved;
	int			player_rotated;

	data = (t_data *)game_data;
	player_pos.x = data->player->pos.x;
	player_pos.y = data->player->pos.y;
	player_dir.x = data->player->dir.x;
	player_dir.y = data->player->dir.y;
	
	key_action(data);
	
	player_moved = ft_memcmp(&player_pos, &data->player->pos, sizeof(t_vector_f));
	player_rotated = ft_memcmp(&player_dir, &data->player->dir, sizeof(t_vector_f));
	if (player_moved != 0 || player_rotated != 0)
	{
		fill_canvas(data);
		game(data);
	}
}
