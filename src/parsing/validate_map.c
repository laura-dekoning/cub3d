/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_map.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/06 19:41:18 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/04/24 12:20:14 by lade-kon      ########   odam.nl         */
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
		if (map[row + x[i]][col + y[i]] == ' ' \
				|| map[row + x[i]][col + y[i]] == '\0')
			error_free_data(data, NO_WALL);
		i++;
	}
}

static void	check_zero(t_data *data, char **map)
{
	int	i;
	int	last_row;

	i = 0;
	last_row = data->map->rows - 1;
	while (map[0][i] != '\0')
	{
		if (map[0][i] != '1' && map[0][i] != ' ')
			error_free_data(data, NO_WALL);
		if (map[last_row][i] != '1' && map[last_row][i] != ' ')
			error_free_data(data, NO_WALL);
		i++;
	}
	i = 0;
	while (map[i] != NULL)
	{
		if (map[i][0] != '1' && map[i][0] != ' ')
			error_free_data(data, NO_WALL);
		i++;
	}
}

void	surrounded_by_walls(t_data *data)
{
	int	x;
	int	y;

	check_zero(data, data->map->map);
	x = 1;
	while (data->map->map[x] != NULL)
	{
		y = 1;
		while (data->map->map[x][y] != '\0')
		{
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
	fill_and_replace_space(data);
	surrounded_by_walls(data);
}
