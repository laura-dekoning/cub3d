/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_floor_and_ceiling.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/19 16:55:50 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/04/07 17:52:28 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_floor_and_ceiling(int *floor, int *ceiling)
{
	int	*f;
	int	*c;

	f = floor;
	c = ceiling;
	if (floor)
		printf(B_W"Floor: "R"%i, "G"%i, "B"%i \n"DEF, f[0], f[1], f[2]);
	if (ceiling)
		printf(B_W"Ceiling: "R"%i, "G"%i, "B"%i \n"DEF, c[0], c[1], c[2]);
}
