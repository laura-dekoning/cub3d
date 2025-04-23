/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_player.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: livliege <livliege@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/24 16:06:00 by livliege      #+#    #+#                 */
/*   Updated: 2025/03/24 16:06:00 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_eye(t_game *game, t_vector_f player_centre, int colour)
{
	t_vector_f	eye_centre;
	t_vector_f	dir;
	float		angle;

	angle = game->player->angle - (80.0 * ONE_D_RADIAN);
	dir.x = cos(angle);
	dir.y = sin(angle);
	eye_centre.x = player_centre.x + dir.x * (game->minimap.player_size / 1.8);
	eye_centre.y = player_centre.y + dir.y * (game->minimap.player_size / 1.8);
	draw_filled_circle(game->minimap_image, eye_centre, \
		(game->minimap.player_size / 5), colour);
}

void	draw_mouth(t_game *game, t_vector_f start_pos, int colour)
{
	t_vector_f	end_pos;
	t_vector_f	dir;
	float		angle;
	float		angle_step;
	int			i;

	angle = game->player->angle - ((60.0 / 2) * ONE_D_RADIAN);
	angle_step = (60.0 * ONE_D_RADIAN) / NUMB_RAYS;
	i = 0;
	while (i < NUMB_RAYS)
	{
		dir.x = cos(angle);
		dir.y = sin(angle);
		end_pos.x = start_pos.x + dir.x * (game->minimap.player_size + 1);
		end_pos.y = start_pos.y + dir.y * (game->minimap.player_size + 1);
		draw_line(game->minimap_image, start_pos, end_pos, colour);
		angle += angle_step;
		check_angle(&angle);
		i++;
	}
}

void	draw_player(t_game *game)
{
	draw_rays(game);
	draw_arrow(game);
	draw_filled_circle(game->minimap_image, game->minimap.player_pos, \
		game->minimap.player_size, game->minimap.player_colour);
	draw_mouth(game, game->minimap.player_pos, COLOUR_BLACK);
	draw_eye(game, game->minimap.player_pos, COLOUR_BLACK);
	draw_circle(game->minimap_image, game->minimap.player_pos, \
		game->minimap.player_size, COLOUR_BLACK);
}
