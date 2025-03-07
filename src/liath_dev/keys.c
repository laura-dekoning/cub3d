/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keys.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: livliege <livliege@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/07 14:41:47 by livliege      #+#    #+#                 */
/*   Updated: 2025/03/07 17:09:34 by livliege      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "../../incl/liath.h"

void	key_action(int key, t_data *data)
{
	if (key == MLX_KEY_ESCAPE)
		mlx_close_window(data->window);
	if (key == MLX_KEY_RIGHT)
		printf("right key!\n");
	if (key == MLX_KEY_LEFT)
		printf("left key!\n");
	if (key == MLX_KEY_W)
	{
		data->player->y -= MOVING_SPEED;
		// printf("y = %d\n", data->player->y);
	}
	if (key == MLX_KEY_S)
	{
		data->player->y += MOVING_SPEED;
		// printf("y = %d\n", data->player->y);
	}
	if (key == MLX_KEY_A)
	{
		data->player->x -= MOVING_SPEED;
		// printf("y = %d\n", data->player->y);
	}
	if (key == MLX_KEY_D)
	{
		data->player->x += MOVING_SPEED;
		// printf("y = %d\n", data->player->y);
	}
}


int	what_key(t_data *data)
{
	// close window 									-> escape
	// look left and right in the maze					-> left and right key
	// move the point of view through the maze (walk)	-> w, s, d, a
	int			i;
	const int	keys[] = {MLX_KEY_ESCAPE, MLX_KEY_LEFT, MLX_KEY_RIGHT, MLX_KEY_W, MLX_KEY_D, MLX_KEY_S, MLX_KEY_A, -1};

	i = 0;
	while (keys[i] != -1)
	{
		if (mlx_is_key_down(data->window, keys[i]))
			return (keys[i]);
		i++;
	}
	return (0);
}

void	key_is_pressed(void *game_data)
{
	t_data	*data;
	int			key;

	data = (t_data *)game_data;
	key = what_key(data);
	if (key > 0)
	{
		key_action(key, data);
		fill_canvas(data);
		game(data);
	}
}