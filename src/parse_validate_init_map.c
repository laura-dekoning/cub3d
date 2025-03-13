/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_validate_init_map.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/13 19:46:51 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/03/13 20:12:15 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	map_content_valid(t_data *data, char *line, size_t start)
{
	while (line[start] != '\0')
	{
		if (line[start] == '0' || line[start] == '1')
			start++;
		else if (line[start] == ' ' || line[start] == '\n')
			start++;
		else if (line[start] == 'N' || line[start] == 'S'
				|| line[start] == 'E' || line[start] == 'W')
			start++;
		else
			error_message(data, MAP_CONTENT);
	}
	return (true);
}

void	parse_validate_init_map(t_data *data, char *line, size_t start)
{
	if (data->map->map)
		ft_free_arr(data->map->map);
	if (map_content_valid(data, line, start) == true)
		data->map->map = ft_split(line, '\n');
}
