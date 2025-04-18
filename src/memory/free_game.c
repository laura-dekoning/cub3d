/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_game.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/07 16:07:31 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/04/18 17:01:04 by livliege      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	terminate_game(t_game *game)
{
	if (game->textures.north_texture)
		mlx_delete_texture(game->textures.north_texture);
	if (game->textures.east_texture)
		mlx_delete_texture(game->textures.east_texture);
	if (game->textures.south_texture)
		mlx_delete_texture(game->textures.south_texture);
	if (game->textures.west_texture)
		mlx_delete_texture(game->textures.west_texture);
	if (game->window_image)
		mlx_delete_image(game->window, game->window_image);
	if (game->minimap_image)
		mlx_delete_image(game->window, game->minimap_image);
	if (game->window)
		mlx_terminate(game->window);
}

void	free_game(t_game *game)
{
	if (game)
	{
		terminate_game(game);
		if (game->map)
		{
			if (game->map->map)
				ft_free_arr(game->map->map);
			free(game->map);
		}
		if (game->player)
			free(game->player);
	}
	free(game);
}
