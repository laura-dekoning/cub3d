/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_file_and_init_data.c                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/11 18:22:48 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/04/07 17:16:10 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	validate_file_and_init_data(t_data *data, char **file)
{
	int		y;

	y = 0;
	while (file[y] != NULL)
	{
		if (is_setting(file[y]) == PATH)
			parse_validate_init_textures(data, file[y]);
		else if (is_setting(file[y]) == RGB)
			parse_validate_init_rgb(data, file[y]);
		else if (is_setting(file[y]) == MAP)
		{
			if (is_map_last(data) == false)
				error_free_data(data, MAP_LAST);
			parse_validate_init_map(data, file, y);
			break;
		}
		else
			error_free_data(data, FILE_CONTENT);
		y++;
	}
}