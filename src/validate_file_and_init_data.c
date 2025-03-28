/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_file_and_init_data.c                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/11 18:22:48 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/03/28 12:23:48 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	validate_file_and_init_data(t_data *data, char *file_as_str)
{
	int		start;

	start = 0;
	while (file_as_str[start] != '\0')
	{
		while (file_as_str[start] == '\n' || file_as_str[start] == ' ')
			start++;
		if (is_setting(file_as_str, start) == PATH)
			start = parse_validate_init_textures(data, file_as_str, start);
		else if (is_setting(file_as_str, start) == RGB)
			start = parse_validate_init_rgb(data, file_as_str, start);
		else if (is_setting(file_as_str, start) == MAP)
		{
			if (is_map_last(data) == false)
				error_message(data, MAP_LAST);
			start = parse_validate_init_map(data, file_as_str, start);
		}
		else
			error_message(data, FILE_CONTENT);
	}
}
