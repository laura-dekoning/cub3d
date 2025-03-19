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

#include "../../incl/liath.h"

bool	hit_wall(t_data *data, float player_x, float player_y)
{
	t_vector_i	top_left;
	t_vector_i	top_right;
	t_vector_i	bottom_left;
	t_vector_i	bottom_right;

	top_left.x = ((int)player_x - PLAYER_SIZE) / GRIDSIZE;
	top_left.y = ((int)player_y - PLAYER_SIZE) / GRIDSIZE;
	top_right.x = ((int)player_x + PLAYER_SIZE) / GRIDSIZE;
	top_right.y = ((int)player_y - PLAYER_SIZE) / GRIDSIZE;
	bottom_left.x = ((int)player_x - PLAYER_SIZE) / GRIDSIZE;
	bottom_left.y = ((int)player_y + PLAYER_SIZE) / GRIDSIZE;
	bottom_right.x = ((int)player_x + PLAYER_SIZE) / GRIDSIZE;
	bottom_right.y = ((int)player_y + PLAYER_SIZE) / GRIDSIZE;
	if (data->map->map[top_left.y][top_left.x] == '1' || data->map->map[top_right.y][top_right.x] == '1' || data->map->map[bottom_left.y][bottom_left.x] == '1' || data->map->map[bottom_right.y][bottom_right.x] == '1')
	{
		return (true);
	}
	else
	{
		return (false);
	}
}

void	check_collision(t_data *data, t_vector_f step)
{
	t_vector_f	next_pos;

	next_pos.x = data->player.pos.x + step.x * MOVING_SPEED;
	next_pos.y = data->player.pos.y + step.y * MOVING_SPEED;
	if (!hit_wall(data, next_pos.x, data->player.pos.y))
	{
		data->player.pos.x = next_pos.x;
	}
	if (!hit_wall(data, data->player.pos.x, next_pos.y))
	{
		data->player.pos.y = next_pos.y;
	}
}
