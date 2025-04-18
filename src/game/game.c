/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/27 14:05:12 by livliege      #+#    #+#                 */
/*   Updated: 2025/04/18 16:04:08 by livliege      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	start_game(t_game *game)
{
	draw_ceiling_and_floor(game);
	raycasting(game);
	minimap(game);
}

void	cub3d(t_game *game)
{
	start_game(game);
	mlx_loop_hook(game->window, is_key_pressed, game);
	mlx_loop(game->window);
}
