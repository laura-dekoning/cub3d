/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_validate_init_rgb.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/13 17:56:57 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/03/13 19:46:00 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	set_rgb(t_data *data, int *target, char *line, size_t start)
{
	int	len;

	len = start;
	while(line[len] != '\n' || line[len] != '\0')
		len++;
	if (target)
		free(target);
	target = string_to_rgb(data, line, start);
	return (len + 1);
}

int	init_rgb_data(t_data *data, char *line, size_t start, int flag)
{
	int	new_start;

	new_start = 0;
	if (flag == FLOOR)
		new_start = set_rgb(data, data->floor, line, start);
	else if (flag == CEILING)
		new_start = set_rgb(data, data->ceiling, line, start);
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

int	parse_validate_init_rgb(t_data *data, char *line, size_t start)
{
	int	flag;
	int	new_start;

	new_start = 0;
	flag = validate_rgb_id(data, line, start);
	new_start = init_rgb_data(data, line, start, flag);
	return (new_start);
}
