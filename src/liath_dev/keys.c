/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keys.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/07 14:41:47 by livliege      #+#    #+#                 */
/*   Updated: 2025/04/04 12:30:51 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	normalize_diagonal_movement(float *step_x, float *step_y)
{
	// stelling van onze grote vriend pytagoras

    // c² = a² + b²
    // c² = 1² + 1²
    // c = sqrt (2)
    // c = 1.41

	float moving_speed;

	moving_speed = sqrt(((*step_x) * (*step_x)) + ((*step_y) * (*step_y)));
	if (moving_speed > 1)
	{
		*step_x /= moving_speed;
		*step_y /= moving_speed;
	}
}

void	movement_keys(t_game *data)
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
	normalize_diagonal_movement(&step.x, &step.y);
	check_collision(data, step);
}

void	rotation_keys(t_game *data)
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

void	exit_key(t_game *data)
{
	if (mlx_is_key_down(data->window, MLX_KEY_ESCAPE))
	{
		mlx_close_window(data->window);
	}
}

void	is_key_pressed(void *game_data)
{
	t_game		*data;
	t_vector_f	old_pos;
	t_vector_f	old_dir;
	int			moved;
	int			rotated;

	data = (t_game *)game_data;
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
