/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_player.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/19 16:57:43 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/03/19 16:57:49 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_player(t_player *player)
{
	printf(B_P"Player:\n"DEF);
	printf("x = %i\ty = %i\n", player->x, player->y);
	if (player->dir == NORTH)
		printf("dir = north\n");
	else if (player->dir == EAST)
		printf("dir = east\n");
	else if (player->dir == SOUTH)
		printf("dir = south\n");
	else if (player->dir == WEST)
		printf("dir = west\n");
}
