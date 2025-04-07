/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_map_last.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/28 12:18:57 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/03/28 12:24:03 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_map_last(t_data *data)
{
	int	x;

	x = 0;
	while (x < 6)
	{
		if (data->check->setting[x] == false)
			return (false);
		x++;
	}
	return (true);
}
