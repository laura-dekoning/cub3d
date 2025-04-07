/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   alloc_mem_for_game.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/04 12:43:37 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/04/07 17:46:24 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*alloc_mem_for_game(t_data *data)
{
	t_game		*game;

	game = (t_game *)safe_calloc(NULL, data, 1, sizeof(t_game));
	if (!game)
		error_free_game_and_data(NULL, data, MALLOC);
	game->map = (t_game_m *)safe_calloc(game, data, 1, sizeof(t_game_m));
	if (!game->map)
		error_free_game_and_data(game, data, MALLOC);
	game->player = (t_game_p *)safe_calloc(game, data, 1, sizeof(t_game_p));
	if (!game->player)
		error_free_game_and_data(game, data, MALLOC);
	return (game);
}
