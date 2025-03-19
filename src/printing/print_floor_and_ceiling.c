/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_floor_and_ceiling.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/19 16:55:50 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/03/19 16:56:04 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_floor_and_ceiling(int *floor, int *ceiling)
{
	printf(B_W"Floor: "R"%i, "G"%i, "B"%i \n"DEF, floor[0], floor[1], floor[2]);
	printf(B_W"Ceiling: "R"%i, "G"%i, "B"%i \n"DEF, ceiling[0], ceiling[1], ceiling[2]);
}
