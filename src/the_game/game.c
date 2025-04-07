/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/27 14:05:12 by livliege      #+#    #+#                 */
/*   Updated: 2025/04/07 16:16:59 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

void	game(t_game *game)
{
	draw_ceiling_and_floor(game);
	raycasting(game);
	minimap(game);
}

void cub3d(t_game *game)
{
	game(game);
	
	mlx_loop_hook(game->window, is_key_pressed, game);
	mlx_loop(game->window);

	mlx_delete_texture(game->textures.north_texture);
	mlx_delete_texture(game->textures.east_texture);
	mlx_delete_texture(game->textures.south_texture);
	mlx_delete_texture(game->textures.west_texture);

	mlx_delete_image(game->window, game->window_image);
	mlx_delete_image(game->window, game->minimap_image);
	
	mlx_terminate(game->window);
}
