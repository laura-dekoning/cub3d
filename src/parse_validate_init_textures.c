/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_validate_init_textures.c                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/28 15:27:18 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/03/14 16:30:18 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	set_texture(char **target, char *line, size_t start)
{
	size_t	len;

	len = start;
	while(line[len] != '\n' && line[len] != '\0')
		len++;
	if (*target)
		free(*target);
	*target = ft_substr(line, start + 3, (len - start - 3));
	if (line[len] != '\0')
		return (len + 1);
	return (len);
}

size_t	init_texture_data(t_data *data, char *line, size_t start, int flag)
{
	size_t	new_start;

	new_start = 0;
	print_check(data->check);
	if (data->check->setting[flag] == true)
		error_message(data, DUP_TEXTURE);		
	if (flag == NORTH)
		new_start = set_texture(&data->north_texture, line, start);
	else if (flag == SOUTH)
		new_start = set_texture(&data->south_texture, line, start);
	else if (flag == EAST)
		new_start = set_texture(&data->east_texture, line, start);
	else if (flag == WEST)
		new_start = set_texture(&data->west_texture, line, start);
	data->check->setting[flag] = true;
	return (new_start);
}

int	validate_texture_id(t_data *data, char *line, size_t start)
{
	int	flag;

	flag = 0;
	if (ft_strncmp(&line[start], "NO ", 3) == 0)
		flag = NORTH;
	else if (ft_strncmp(&line[start], "SO ", 3) == 0)
		flag = SOUTH;
	else if (ft_strncmp(&line[start], "EA ", 3) == 0)
		flag = EAST;
	else if (ft_strncmp(&line[start], "WE ", 3) == 0)
		flag = WEST;
	else
		error_message(data, "Invalid texture ID\n");
	return (flag);
}

size_t	parse_validate_init_textures(t_data *data, char *line, size_t start)
{
	int		flag;
	size_t	new_start;

	new_start = 0;
	flag = validate_texture_id(data, line, start);
	new_start = init_texture_data(data, line, start, flag);
	return (new_start);
}

int	is_setting(char *line, size_t start)
{
	if (ft_strncmp(&line[start], "NO", 2) == 0)
		return (PATH);
	else if (ft_strncmp(&line[start], "SO", 2) == 0)
		return (PATH);
	else if (ft_strncmp(&line[start], "EA", 2) == 0)
		return (PATH);
	else if (ft_strncmp(&line[start], "WE", 2) == 0)
		return (PATH);
	else if (ft_strncmp(&line[start], "F", 1) == 0)
		return (RGB);
	else if (ft_strncmp(&line[start], "C", 1) == 0)
		return (RGB);
	else
		return (NONE);
}
