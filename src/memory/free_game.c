/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_game.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/07 16:07:31 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/04/07 16:09:55 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_game(t_game *game)
{
	if (game)
	{
		if (game->map)
		{
			ft_free_arr(game->map->map);
			free(game->map);
		}
	}
	free(game);
}
