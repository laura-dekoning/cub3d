/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/27 14:05:12 by livliege      #+#    #+#                 */
/*   Updated: 2025/04/04 14:43:52 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	game(t_game *data)
{
	draw_ceiling_and_floor(data);
	raycasting(data);

	minimap(data);
}

void cub3d(t_game *data)
{
	game(data);
	
	mlx_loop_hook(data->window, is_key_pressed, data);
	mlx_loop(data->window);

	mlx_delete_texture(data->textures.north_texture);
	mlx_delete_texture(data->textures.east_texture);
	mlx_delete_texture(data->textures.south_texture);
	mlx_delete_texture(data->textures.west_texture);

	mlx_delete_image(data->window, data->window_image);
	mlx_delete_image(data->window, data->minimap_image);
	
	mlx_terminate(data->window);
}
