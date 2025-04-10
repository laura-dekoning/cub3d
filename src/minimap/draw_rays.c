/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_rays.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: livliege <livliege@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/10 18:20:37 by livliege      #+#    #+#                 */
/*   Updated: 2025/04/10 18:30:09 by livliege      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_rays(t_game *game)
{
	t_vector_f	end_pos;
	t_vector_f	dir;
	float		angle;
	float		angle_step;
	int			i;

	angle = game->player->angle - ((FOV / 2) * ONE_D_RADIAN);
	angle_step = (FOV * ONE_D_RADIAN) / NUMB_RAYS;
	i = 0;
	while (i < NUMB_RAYS)
	{
		dir.x = cos(angle);
		dir.y = sin(angle);
		end_pos.x = (game->minimap.player_pos.x + dir.x * (game->ray[i].distance / GRIDSIZE) * game->minimap.grid_size);
		end_pos.y = (game->minimap.player_pos.y + dir.y * (game->ray[i].distance / GRIDSIZE) * game->minimap.grid_size);
		draw_line(game->minimap_image, game->minimap.player_pos, end_pos, game->minimap.ray_colour);
		angle += angle_step;
		check_angle(&angle);
		i++;
	}
}

void	draw_arrow_head(t_game *game, t_vector_f start_pos, t_vector_f end_pos, t_vector_f dir)
{
	float	arrow_length;
	float	arrow_angle;
	float	arrow_head_size;
	uint8_t	arrow_head_pointyness;

	arrow_head_size = 0.7;
	arrow_head_pointyness = 40;
	arrow_length = game->minimap.grid_size * arrow_head_size;
	arrow_angle = arrow_head_pointyness * ONE_D_RADIAN;
	dir.x = cos(game->player->angle + PI + arrow_angle);
	dir.y = sin(game->player->angle + PI + arrow_angle);
	start_pos.x = end_pos.x + dir.x * arrow_length;
	start_pos.y = end_pos.y + dir.y * arrow_length;
	draw_line(game->minimap_image, end_pos, start_pos, game->minimap.arrow_colour);
	dir.x = cos(game->player->angle + PI - arrow_angle);
	dir.y = sin(game->player->angle + PI - arrow_angle);
	start_pos.x = end_pos.x + dir.x * arrow_length;
	start_pos.y = end_pos.y + dir.y * arrow_length;
	draw_line(game->minimap_image, end_pos, start_pos, game->minimap.arrow_colour);
}

void	draw_arrow(t_game *game)
{
	t_vector_f	start_pos;
	t_vector_f	end_pos;
	t_vector_f	dir;
	float		angle;
	float		angle_step;

	start_pos = game->minimap.player_pos;
	angle = game->player->angle;
	angle_step = (FOV * ONE_D_RADIAN) / NUMB_RAYS;
	dir.x = cos(angle);
	dir.y = sin(angle);
	end_pos.x = start_pos.x + dir.x * (game->ray[NUMB_RAYS / 2].distance / GRIDSIZE) * game->minimap.grid_size;
	end_pos.y = start_pos.y + dir.y * (game->ray[NUMB_RAYS / 2].distance / GRIDSIZE) * game->minimap.grid_size;
	draw_line(game->minimap_image, start_pos, end_pos, game->minimap.arrow_colour);
	angle += angle_step;
	check_angle(&angle);
	draw_arrow_head(game, start_pos, end_pos, dir);
}
