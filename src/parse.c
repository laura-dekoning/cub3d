/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/28 15:27:18 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/02/28 15:45:32 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_textures(t_data *data, char line)
{
	int i;
	int flag;

	flag = 0;
	i = 0;
	if (ft_strncmp(line, "NO", 2) == 0)
		flag == NORTH;
	else if (ft_strncmp(line, "SO", 2) == 0)
		flag == SOUTH;
	else if (ft_strncmp(line, "WE", 2) == 0)
		flag == WEST;
	else if (ft_strncmp(line, "EA", 2) == 0)
		flag == EAST;
	{
		while (line[i + 2] == ' ')
			i++;
		data->north_texture = ft_substr(line, i, ft_strlen(line) - i);
		
	}
}