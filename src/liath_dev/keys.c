/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keys.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: livliege <livliege@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/07 14:41:47 by livliege      #+#    #+#                 */
/*   Updated: 2025/03/08 14:07:22 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "../../incl/liath.h"


// 	// close window 									-> escape
// 	// look left and right in the maze					-> left and right key
// 	// move the point of view through the maze (walk)	-> w, s, d, a


void	key_action(t_data *data)
{
	if (mlx_is_key_down(data->window, MLX_KEY_ESCAPE))
		mlx_close_window(data->window);
	if (mlx_is_key_down(data->window,MLX_KEY_RIGHT))
		printf("right key!\n");
	if (mlx_is_key_down(data->window, MLX_KEY_LEFT))
		printf("left key!\n");
	if (mlx_is_key_down(data->window, MLX_KEY_W))
	{
		data->player->pos.y -= MOVING_SPEED;
		// printf("y = %d\n", data->player->y);
	}
	if (mlx_is_key_down(data->window, MLX_KEY_S))
	{
		data->player->pos.y += MOVING_SPEED;
		// printf("y = %d\n", data->player->y);
	}
	if (mlx_is_key_down(data->window, MLX_KEY_A))
	{
		data->player->pos.x -= MOVING_SPEED;
		// printf("y = %d\n", data->player->y);
	}
	if (mlx_is_key_down(data->window, MLX_KEY_D))
	{
		data->player->pos.x += MOVING_SPEED;
		// printf("y = %d\n", data->player->y);
	}
}


void	key_is_pressed(void *game_data)
{
	t_data	*data;
	t_vector player_pos;

	data = (t_data *)game_data;
	player_pos.x = data->player->pos.x;
	player_pos.y = data->player->pos.y;
	
	key_action(data);
	
	// This will be changed to a function that compares two structs with memcmp. 
	if ((player_pos.x != data->player->pos.x) || (player_pos.y != data->player->pos.y))
	{
		fill_canvas(data);
		game(data);
	}
}
