/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_file_and_init_data.c                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/11 18:22:48 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/03/11 20:07:02 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	validate_file_and_init_data(t_data *data, char *file_as_str)
{
	if (is_texture(&file_as_str))
		parse_validate_init_textures(data, &file_as_str);
	
}
