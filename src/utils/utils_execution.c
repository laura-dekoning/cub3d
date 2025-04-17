/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_execution.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/26 12:55:32 by livliege      #+#    #+#                 */
/*   Updated: 2025/04/17 13:46:59 by livliege      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_angle(float *angle)
{
	if (*angle > (2 * PI))
		*angle -= (2 * PI);
	if (*angle < 0)
		*angle += (2 * PI);
}
