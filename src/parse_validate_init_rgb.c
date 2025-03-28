/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_validate_init_rgb.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/13 17:56:57 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/03/28 12:41:06 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	set_rgb(t_data *data, int **target, char *line, size_t start)
{
	size_t	len;
	int		komma;

	komma = 0;
	len = start;
	while(line[len] != '\n' && line[len] != '\0')
	{
		if (line[len] == ',')
			komma++;
		len++;
	}
	if (komma > 2)
		error_message(data, "More then 3 colors in floor or ceiling");
	*target = string_to_rgb(data, line, start);
	//build in error check if something goes wrong. maybe do the same as textures (pass whole data struct through function)
	while (line[len] == '\n' || line[len] == ' ')
		len++;
	return (len);
}

size_t	init_rgb_data(t_data *data, char *line, size_t start, int flag)
{
	size_t	new_start;

	new_start = 0;
	if (flag == FLOOR)
		new_start = set_rgb(data, &data->floor, line, start + 2);
	else if (flag == CEILING)
		new_start = set_rgb(data, &data->ceiling, line, start + 2);
	data->check->setting[flag] = true;
	return (new_start);
}

int	validate_rgb_id(t_data *data, char *line, size_t start)
{
	int	flag;

	flag = 0;
	if (ft_strncmp(&line[start], "F ", 2) == 0)
		flag = FLOOR;
	else if (ft_strncmp(&line[start], "C ", 2) == 0)
		flag = CEILING;
	else
		error_message(data, "Invalid RGB ID\n");
	return (flag);
}

size_t	parse_validate_init_rgb(t_data *data, char *line, size_t start)
{
	int		flag;
	size_t	new_start;

	if (data->check->setting[MAP] == true)
		error_message(data, "File should end with map content!");
	new_start = 0;
	flag = validate_rgb_id(data, line, start);
	new_start = init_rgb_data(data, line, start, flag);
	return (new_start);
}
