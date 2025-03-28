/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_map.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/06 19:41:18 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/03/28 14:14:36 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_player(char c)
{
	if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
		return (true);
	return (false);
}

static void	check_adjacent(t_data *data, char **map, int row, int col)
{
	const int	x[4] = {1, 0, -1, 0};
	const int	y[4] = {0, 1, 0, -1};
	int			i;

	i = 0;
	while (i < 4)
	{
		if (map[row + x[i]][col + y[i]] == ' ')
			error_message(data, NO_WALL);
		i++;
	}
}

static void	check_zero(t_data *data, char **map)
{
	int	i;

	i = 0;
	while (map[0][i] != '\0')
	{
		if (map[0][i] != '1' && map[0][i] != ' ')
			error_message(data, NO_WALL);
		i++;
	}
	i = 0;
	while (map[i] != NULL)
	{
		if (map[i][0] != '1' && map[i][0] != ' ')
			error_message(data, NO_WALL);
		i++;
	}
}

void	surrounded_by_walls(t_data *data)
{
	int	x;
	int	y;

	print_array_with_index(data->map->map);
	check_zero(data, data->map->map);
	x = 1;
	while (data->map->map[x] != NULL)
	{
		y = 1;
		while (data->map->map[x][y] != '\0')
		{
			printf("map[%i][%i]\n", x, y);
			if (data->map->map[x][y] == '0'
					|| is_player(data->map->map[x][y]) == true)
				check_adjacent(data, data->map->map, x, y);
			y++;
		}
		x++;
	}
}

void	validate_map(t_data *data)
{
	fill_map(data);
	surrounded_by_walls(data);
}
