/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_map.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/06 19:41:18 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/03/16 16:49:53 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	surrounded_by_walls(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map->map[x] != NULL)
	{
		y = 0;
		while (data->map->map[x][y] != '\0')
		{
			if (data->map->map[0][y] != '1' || )
			y++;
		}
		x++;
	}
}



void	validate_map(t_data *data)
{
	fill_and_replace(data);
	surrounded_by_walls(data);
	make_square(data);
}


