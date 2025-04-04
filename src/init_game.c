/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_game.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/04 14:34:34 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/04/04 14:43:13 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_game(t_game *game, t_data * data)
{

	game->floor_colour = rgb_to_hex(data->floor);
	game->ceiling_colour = rgb_to_hex(data->ceiling);

	init_window(game);
	init_minimap_image(game);
	init_wall_textures(&game->textures);


	free_data(data);
}
