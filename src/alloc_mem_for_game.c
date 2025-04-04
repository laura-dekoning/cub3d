/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   alloc_mem_for_game.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/04 12:43:37 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/04/04 13:22:00 by livliege      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*alloc_mem_for_game(void)
{
	t_game		*game;

	game = (t_game *)safe_calloc(NULL, 1, sizeof(t_game));
	if (!game)
		error_message(game, MALLOC);
	game->map = (t_map_ex *)safe_calloc(game, 1, sizeof(t_map_ex));
	if (!game->map)
		error_message(game, MALLOC);
	game->player = (t_player_ex *)safe_calloc(game, 1, sizeof(t_player_ex));
	if (!game->player)
		error_message(game, MALLOC);

	return (game);
}
