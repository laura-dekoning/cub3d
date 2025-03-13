/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_validate_init_textures.c                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/28 15:27:18 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/03/13 13:38:39 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_texture_data(t_data *data, char *line, int i, int flag)
{
	while (line[i] == ' ')
		i++;
	if (flag == NORTH)
		data->north_texture = ft_substr(line, i, ft_strlen(line) - i);
	if (flag == SOUTH)
		data->south_texture = ft_substr(line, i, ft_strlen(line) - i);
	if (flag == EAST)
		data->east_texture = ft_substr(line, i, ft_strlen(line) - i);
	if (flag == WEST)
		data->west_texture = ft_substr(line, i, ft_strlen(line) - i);

}

int	parse_and_validate_textures(t_data *data, char *line)
{
	int flag;

	flag = 0;
	if (ft_strncmp(line, "NO ", 3) == 0)
		flag = NORTH;
	else if (ft_strncmp(line, "SO ", 3) == 0)
		flag = SOUTH;
	else if (ft_strncmp(line, "EA ", 3) == 0)
		flag = EAST;
	else if (ft_strncmp(line, "WE ", 3) == 0)
		flag = WEST;
	else
		error_message(data, "Invalid texture\n");
	return (flag);
}

void	parse_validate_init_textures(t_data *data, char *line)
{
	int	flag;

	flag = parse_and_validate_textures(data, line);
	init_texture_data(data, line, 1, flag);
}

bool	is_texture(char *line)
{
	if (ft_strncmp(line, "NO", 2) == 0)
		return (true);
	else if (ft_strncmp(line, "SO", 2) == 0)
		return (true);
	else if (ft_strncmp(line, "EA", 2) == 0)
		return (true);
	else if (ft_strncmp(line, "WE", 2) == 0)
		return (true);
	else
		return (false);
}
