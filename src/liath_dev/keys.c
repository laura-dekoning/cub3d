/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keys.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: livliege <livliege@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/07 14:41:47 by livliege      #+#    #+#                 */
/*   Updated: 2025/03/12 00:26:51 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "../../incl/liath.h"


// 	// close window 									-> escape
// 	// look left and right in the maze					-> left and right key
// 	// move the point of view through the maze (walk)	-> w, s, d, a


void	key_action(t_data *data)
{
	if (mlx_is_key_down(data->window, MLX_KEY_ESCAPE))
	{
		mlx_close_window(data->window);
	}
	if (mlx_is_key_down(data->window, MLX_KEY_LEFT))
	{
		data->player->angle -= 0.1;
		if (data->player->angle < 0)
		{			
			data->player->angle += (2 * PI);
		}
		data->player->dir.x = cos(data->player->angle); //  * ROTATE_SPEED;
		data->player->dir.y = sin(data->player->angle); //  * ROTATE_SPEED;
	}
	if (mlx_is_key_down(data->window,MLX_KEY_RIGHT))
	{
		
		data->player->angle += 0.1;
		if (data->player->angle > (2 * PI))
		{
			data->player->angle -= (2 * PI);
		}
		data->player->dir.x = cos(data->player->angle); //  * ROTATE_SPEED;
		data->player->dir.y = sin(data->player->angle); //  * ROTATE_SPEED;
	}
	if (mlx_is_key_down(data->window, MLX_KEY_W))
	{
		data->player->pos.x += data->player->dir.x;
		data->player->pos.y += data->player->dir.y;
	}
	if (mlx_is_key_down(data->window, MLX_KEY_S))
	{
		data->player->pos.x -= data->player->dir.x;
		data->player->pos.y -= data->player->dir.y;
	}
	if (mlx_is_key_down(data->window, MLX_KEY_A))
	{
		data->player->pos.x -= data->player->dir.y;
		data->player->pos.y += data->player->dir.x;
	}
	if (mlx_is_key_down(data->window, MLX_KEY_D))
	{
		data->player->pos.x += data->player->dir.y;
		data->player->pos.y -= data->player->dir.x;
	}
}


void	key_is_pressed(void *game_data)
{
	t_data	*data;
	t_vector player_pos;
	t_vector player_dir;
	int		player_moved;
	int		player_rotated;

	data = (t_data *)game_data;
	player_pos.x = data->player->pos.x;
	player_pos.y = data->player->pos.y;
	player_dir.x = data->player->dir.x;
	player_dir.y = data->player->dir.y;
	
	key_action(data);
	
	player_moved = ft_memcmp(&player_pos, &data->player->pos, sizeof(t_vector));
	player_rotated = ft_memcmp(&player_dir, &data->player->dir, sizeof(t_vector));
	// This will be changleed to a function that compares two structs with memcmp. 
	// if ((player_pos.x != data->player->pos.x) || (player_pos.y != data->player->pos.y))
	if (player_moved != 0 || player_rotated != 0)
	{
		fill_canvas(data);
		game(data);
	}
}
