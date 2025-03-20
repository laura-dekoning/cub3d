/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keys.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: livliege <livliege@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/07 14:41:47 by livliege      #+#    #+#                 */
/*   Updated: 2025/03/20 17:29:57 by livliege      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/liath.h"

void	movement_keys(t_data *data)
{
	t_vector_f	step;

	step.x = 0.0;
	step.y = 0.0;
	if (mlx_is_key_down(data->window, MLX_KEY_W))
	{
		step.x += data->player.dir.x;
		step.y += data->player.dir.y;
	}
	if (mlx_is_key_down(data->window, MLX_KEY_S))
	{
		step.x -= data->player.dir.x;
		step.y -= data->player.dir.y;
	}
	if (mlx_is_key_down(data->window, MLX_KEY_A))
	{
		step.x += data->player.dir.y;
		step.y -= data->player.dir.x;
	}
	if (mlx_is_key_down(data->window, MLX_KEY_D))
	{
		step.x -= data->player.dir.y;
		step.y += data->player.dir.x;
	}
	check_collision(data, step);
}

void	rotation_keys(t_data *data)
{
	if (mlx_is_key_down(data->window, MLX_KEY_LEFT))
	{
		data->player.angle -= ROTATING_SPEED;
		if (data->player.angle < 0)
		{
			data->player.angle += (2 * PI);
		}
		data->player.dir.x = cos(data->player.angle); //* ROTATING_SPEED;
		data->player.dir.y = sin(data->player.angle); //* ROTATING_SPEED;
	}
	if (mlx_is_key_down(data->window, MLX_KEY_RIGHT))
	{
		data->player.angle += ROTATING_SPEED;
		if (data->player.angle > (2 * PI))
		{
			data->player.angle -= (2 * PI);
		}
		data->player.dir.x = cos(data->player.angle); // * ROTATING_SPEED;
		data->player.dir.y = sin(data->player.angle); // * ROTATING_SPEED;
	}
}

void	exit_key(t_data *data)
{
	if (mlx_is_key_down(data->window, MLX_KEY_ESCAPE))
	{
		mlx_close_window(data->window);
	}
}

void	is_key_pressed(void *game_data)
{
	t_data		*data;
	t_vector_f	old_pos;
	t_vector_f	old_dir;
	int			moved;
	int			rotated;

	data = (t_data *)game_data;
	old_pos.x = data->player.pos.x;
	old_pos.y = data->player.pos.y;
	old_dir.x = data->player.dir.x;
	old_dir.y = data->player.dir.y;
	exit_key(data);
	rotation_keys(data);
	movement_keys(data);
	moved = ft_memcmp(&old_pos, &data->player.pos, sizeof(t_vector_f));
	rotated = ft_memcmp(&old_dir, &data->player.dir, sizeof(t_vector_f));
	if (moved != 0 || rotated != 0)
	{
		game(data);
	}
}
