/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_validate_init_rgb.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/13 17:56:57 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/03/28 15:51:19 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_rgb(t_data *data, int **target, char *line)
{
	int	i;
	int	komma;

	komma = 0;
	i = 2;
	while(line[i] != '\0')
	{
		if (line[i] == ',')
			komma++;
		i++;
	}
	if (komma > 2)
		error_message(data, "More then 3 colors in floor or ceiling");
	*target = string_to_rgb(data, line, 2);
}

void	init_rgb_data(t_data *data, char *line, int flag)
{
	if (flag == FLOOR)
		set_rgb(data, &data->floor, line);
	else if (flag == CEILING)
		set_rgb(data, &data->ceiling, line);
	data->check->setting[flag] = true;
}

int	validate_rgb_id(t_data *data, char *line)
{
	int	flag;

	flag = 0;
	if (ft_strncmp(line, "F ", 2) == 0)
		flag = FLOOR;
	else if (ft_strncmp(line, "C ", 2) == 0)
		flag = CEILING;
	else
		error_message(data, "Invalid RGB ID\n");
	return (flag);
}

void	parse_validate_init_rgb(t_data *data, char *line)
{
	int		flag;

	if (data->check->setting[MAP] == true)
		error_message(data, "File should end with map content!");
	flag = validate_rgb_id(data, line);
	init_rgb_data(data, line, flag);
}
