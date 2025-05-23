/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_collision.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: livliege <livliege@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/07 14:41:47 by livliege      #+#    #+#                 */
/*   Updated: 2025/03/17 14:02:32 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	hit_wall(t_game *game, float player_x, float player_y)
{
	t_vector_s	top_left;
	t_vector_s	top_right;
	t_vector_s	bottom_left;
	t_vector_s	bottom_right;
	uint16_t	size;

	size = game->player->size;
	top_left.x = ((int)player_x - size) / GRIDSIZE;
	top_left.y = ((int)player_y - size) / GRIDSIZE;
	top_right.x = ((int)player_x + size) / GRIDSIZE;
	top_right.y = ((int)player_y - size) / GRIDSIZE;
	bottom_left.x = ((int)player_x - size) / GRIDSIZE;
	bottom_left.y = ((int)player_y + size) / GRIDSIZE;
	bottom_right.x = ((int)player_x + size) / GRIDSIZE;
	bottom_right.y = ((int)player_y + size) / GRIDSIZE;
	if (game->map->map[top_left.y][top_left.x] == '1' || \
		game->map->map[top_right.y][top_right.x] == '1' || \
		game->map->map[bottom_left.y][bottom_left.x] == '1' || \
		game->map->map[bottom_right.y][bottom_right.x] == '1')
	{
		return (true);
	}
	return (false);
}

void	normalize_diagonal_movement(float *step_x, float *step_y)
{
	float	moving_speed;

	moving_speed = sqrt(((*step_x) * (*step_x)) + ((*step_y) * (*step_y)));
	if (moving_speed > 1)
	{
		*step_x /= moving_speed;
		*step_y /= moving_speed;
	}
}

void	check_collision(t_game *game, t_vector_f step)
{
	t_vector_f	next_pos;

	normalize_diagonal_movement(&step.x, &step.y);
	next_pos.x = game->player->pos.x + step.x * MOVING_SPEED;
	next_pos.y = game->player->pos.y + step.y * MOVING_SPEED;
	if (!hit_wall(game, next_pos.x, game->player->pos.y))
	{
		game->player->pos.x = next_pos.x;
	}
	if (!hit_wall(game, game->player->pos.x, next_pos.y))
	{
		game->player->pos.y = next_pos.y;
	}
}
