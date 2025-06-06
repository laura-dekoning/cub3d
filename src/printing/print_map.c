/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/19 16:56:41 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/03/28 16:16:32 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_map(t_map *map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	printf(B_G"Map:\n"DEF);
	printf("rows\t: %zu\tcols\t: %zu\n", map->rows, map->cols);
	if (map->map)
	{
		while (map->map[i] != NULL)
		{
			printf(B_W"%s\n"DEF, map->map[i]);
			i++;
		}
		print_array_with_values(map->map);
	}
}
