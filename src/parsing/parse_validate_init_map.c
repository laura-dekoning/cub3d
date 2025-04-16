/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_validate_init_map.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/13 19:46:51 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/04/16 14:21:17 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_player_dir(t_data *data, char p)
{
	if (p == 'N')
		data->player->dir = NORTH;
	else if (p == 'E')
		data->player->dir = EAST;
	else if (p == 'S')
		data->player->dir = SOUTH;
	else if (p == 'W')
		data->player->dir = WEST;
}

void	set_player(t_data *data, char **map)
{
	int		row;
	int		col;
	bool	player;

	player = false;
	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (map[row][col] == 'N' || map[row][col] == 'S'
				|| map[row][col] == 'E' || map[row][col] == 'W')
			{
				if (player == true)
					error_free_data(data, DUP_P);
				data->player->x = col;
				data->player->y = row;
				set_player_dir(data, map[row][col]);
				player = true;
			}
			col++;
		}
		row++;
	}
}

void	set_rows_and_cols(t_data *data, char **map, int y)
{
	size_t	rows;
	size_t	cols;
	size_t	count;

	rows = y;
	while (map[rows])
	{
		count = 0;
		cols = 0;
		while (map[rows][cols])
		{
			count++;
			if (data->map->cols < count)
				data->map->cols = count;
			cols++;
		}
		rows++;
	}
	data->map->rows = rows - y;
}

void	map_content_valid(t_data *data)
{
	char	**map;
	int		x;
	int		y;

	map = data->map->map;
	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == '0' || map[y][x] == '1')
				x++;
			else if (map[y][x] == ' ' || map[y][x] == '\n')
				x++;
			else if (map[y][x] == 'N' || map[y][x] == 'S'
					|| map[y][x] == 'E' || map[y][x] == 'W')
				x++;
			else
				error_free_data(data, MAP_CONTENT);
		}
		y++;
	}
}

void	parse_validate_init_map(t_data *data, char **file_as_arr, int y)
{
	int	x;

	x = 0;
	set_rows_and_cols(data, file_as_arr, y);
	data->map->map = (char **)safe_calloc(NULL, data, data->map->rows + 1, sizeof(char *));
	while (file_as_arr[y] != NULL)
	{
		data->map->map[x] = ft_substr(file_as_arr[y], 0, ft_strlen(file_as_arr[y]));
		if (data->map->map[x] == NULL)
			error_free_data(data, MALLOC);
		x++;
		y++;
	}
	map_content_valid(data);
	data->check->setting[MAP] = true;
	set_player(data, data->map->map);
	validate_map(data);
}
