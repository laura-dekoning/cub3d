/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_ceiling_and_floor.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: livliege <livliege@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/10 18:45:20 by livliege      #+#    #+#                 */
/*   Updated: 2025/04/23 14:24:14 by livliege      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_ceiling(t_game *game)
{
	t_vector_s	ceiling_start;
	t_vector_s	ceiling_end;
	uint32_t	colour;

	colour = game->ceiling_colour;
	ceiling_start.x = 0;
	ceiling_start.y = 0;
	ceiling_end.x = game->window_image->width;
	ceiling_end.y = game->window_image->height / 2;
	draw_filled_rectangle(game->window_image, ceiling_start, ceiling_end, \
		colour);
}

void	draw_floor(t_game *game)
{
	t_vector_s	floor_start;
	t_vector_s	floor_end;
	uint32_t	colour;

	colour = game->floor_colour;
	floor_start.x = 0;
	floor_start.y = game->window_image->height / 2;
	floor_end.x = game->window_image->width;
	floor_end.y = game->window_image->height;
	draw_filled_rectangle(game->window_image, floor_start, floor_end, colour);
}

void	draw_ceiling_and_floor(t_game *game)
{
	draw_ceiling(game);
	draw_floor(game);
}
