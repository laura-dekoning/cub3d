/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_validate_init_textures.c                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/28 15:27:18 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/04/10 13:43:48 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//Maybe change variables. Maybe pass whole data struct to EVERY function for clean exit everywhere
//Also no hassle with pointers and stuff. 
void	set_texture(char **target, char *line)
{
	size_t	len;

	len = 3;
	while (ft_issymbol(line[len]))
		len++;
	if (*target)
		free(*target);
	*target = ft_substr(line, 3, len - 3);
	while (line[len] == ' ')
		len++;
}

//Maybe make the textures in a char ** so it can align with the enums 
void	init_texture_data(t_data *data, char *line, int flag)
{
	if (data->check->setting[flag] == true)
		error_free_data(data, DUP_TEXTURE);		
	if (flag == NORTH)
		set_texture(&data->north_texture, line);
	else if (flag == EAST)
		set_texture(&data->east_texture, line);
	else if (flag == SOUTH)
		set_texture(&data->south_texture, line);
	else if (flag == WEST)
		set_texture(&data->west_texture, line);
	data->check->setting[flag] = true;
}

int	validate_texture_id(t_data *data, char *line)
{
	int	flag;

	flag = 0;
	if (ft_strncmp(line, "NO ", 3) == 0)
		flag = NORTH;
	else if (ft_strncmp(line, "EA ", 3) == 0)
		flag = EAST;
	else if (ft_strncmp(line, "SO ", 3) == 0)
		flag = SOUTH;
	else if (ft_strncmp(line, "WE ", 3) == 0)
		flag = WEST;
	else
		error_free_data(data, "Invalid texture ID\n");
	return (flag);
}

void	parse_validate_init_textures(t_data *data, char *line)
{
	int		flag;

	if (data->check->setting[MAP] == true)
		error_free_data(data, "File should end with map content!");
	flag = validate_texture_id(data, line);
	init_texture_data(data, line, flag);
}
