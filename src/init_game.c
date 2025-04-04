/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_game.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/04 14:34:34 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/04/04 14:53:23 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_game(t_game *game, t_data * data)
{

	game->floor_colour = rgb_to_hex(data->floor);
	game->ceiling_colour = rgb_to_hex(data->ceiling);


	//1.) init game->player with data from data->player
	//2.) init game->map->map_width and height
	init_window(game);
	init_minimap_image(game);
	init_wall_textures(data, &game->textures);


	free_data(data);
}
