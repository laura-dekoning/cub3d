/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_validate_init_map.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/13 19:46:51 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/03/20 17:54:33 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
					error_message(data, DUP_P);
				data->player->x = row;
				data->player->y = col;
				player = true;
			}
			col++;
		}
		row++;
	}
}

void	set_rows_and_cols(t_data *data, char **map)
{
	size_t	rows;
	size_t	cols;
	size_t	count;

	rows = 0;
	while (map[rows])
	{
		count = 0;
		cols = 0;
		while (map[rows][cols])
		{
			if (map[rows][cols] == '\t')
				count += 4;
			else
				count++;
			if (data->map->cols < count)
				data->map->cols = count;
			cols++;
		}
		rows++;
	}
	data->map->rows = rows;
}

bool	map_content_valid(t_data *data, char *line, size_t start)
{
	while (line[start] != '\0')
	{
		if (line[start] == '0' || line[start] == '1')
			start++;
		else if (line[start] == ' ' || line[start] == '\n' || line[start] == '\t')
			start++;
		else if (line[start] == 'N' || line[start] == 'S'
				|| line[start] == 'E' || line[start] == 'W')
			start++;
		else
			error_message(data, MAP_CONTENT);
	}
	return (true);
}

size_t	parse_validate_init_map(t_data *data, char *line, size_t start)
{
	size_t	new_start;
	char	*map_as_str;

	map_as_str = ft_substr(line, start, (ft_strlen(line) - start));
	new_start = start;
	if (map_content_valid(data, map_as_str, 0) == true)
	{
		data->map->map = ft_split(map_as_str, '\n');
		data->check->setting[MAP] = true;
	}
	set_rows_and_cols(data, data->map->map);
	set_player(data, data->map->map);
	validate_map(data);
	free (map_as_str);
	while (line[new_start] != '\0')
		new_start++;
	return (new_start);
}
