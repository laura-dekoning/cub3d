/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_file_and_init_data.c                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/11 18:22:48 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/03/28 16:52:51 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	validate_file_and_init_data(t_data *data, char **file)
{
	int		y;

	y = 0;
	while (file[y] != NULL)
	{
		// print_data(data);
		printf(Y"file[%i] = [%s]\n"DEF, y, file[y]);
		if (is_setting(file[y]) == PATH)
			parse_validate_init_textures(data, file[y]);
		else if (is_setting(file[y]) == RGB)
			parse_validate_init_rgb(data, file[y]);
		else if (is_setting(file[y]) == MAP)
		{
			if (is_map_last(data) == false)
				error_message(data, MAP_LAST);
			parse_validate_init_map(data, file, y);
			break;
		}
		else
			error_message(data, FILE_CONTENT);
		printf("I DO GET HERE %i YES!!!\n", y);
		y++;
	}
}