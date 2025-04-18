/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keys.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/07 14:41:47 by livliege      #+#    #+#                 */
/*   Updated: 2025/04/18 19:11:36 by livliege      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	movement_keys(t_game *game)
{
	t_vector_f	step;

	step.x = 0.0;
	step.y = 0.0;
	if (mlx_is_key_down(game->window, MLX_KEY_W))
	{
		step.x += game->player->dir.x;
		step.y += game->player->dir.y;
	}
	if (mlx_is_key_down(game->window, MLX_KEY_S))
	{
		step.x -= game->player->dir.x;
		step.y -= game->player->dir.y;
	}
	if (mlx_is_key_down(game->window, MLX_KEY_A))
	{
		step.x += game->player->dir.y;
		step.y -= game->player->dir.x;
	}
	if (mlx_is_key_down(game->window, MLX_KEY_D))
	{
		step.x -= game->player->dir.y;
		step.y += game->player->dir.x;
	}
	check_collision(game, step);
}

void	rotation_keys(t_game *game)
{
	if (mlx_is_key_down(game->window, MLX_KEY_LEFT))
	{
		game->player->angle -= ROTATING_SPEED;
		if (game->player->angle < 0)
		{
			game->player->angle += (2 * PI);
		}
		game->player->dir.x = cos(game->player->angle);
		game->player->dir.y = sin(game->player->angle);
	}
	if (mlx_is_key_down(game->window, MLX_KEY_RIGHT))
	{
		game->player->angle += ROTATING_SPEED;
		if (game->player->angle > (2 * PI))
		{
			game->player->angle -= (2 * PI);
		}
		game->player->dir.x = cos(game->player->angle);
		game->player->dir.y = sin(game->player->angle);
	}
}

void	exit_key(t_game *game)
{
	if (mlx_is_key_down(game->window, MLX_KEY_ESCAPE))
	{
		mlx_close_window(game->window);
	}
}

void	is_key_pressed(void *game_game)
{
	t_game		*game;
	t_vector_f	old_pos;
	t_vector_f	old_dir;
	int			moved;
	int			rotated;

	game = (t_game *)game_game;
	old_pos.x = game->player->pos.x;
	old_pos.y = game->player->pos.y;
	old_dir.x = game->player->dir.x;
	old_dir.y = game->player->dir.y;
	exit_key(game);
	rotation_keys(game);
	movement_keys(game);
	moved = ft_memcmp(&old_pos, &game->player->pos, sizeof(t_vector_f));
	rotated = ft_memcmp(&old_dir, &game->player->dir, sizeof(t_vector_f));
	if (moved != 0 || rotated != 0)
	{
		start_game(game);
	}
}
