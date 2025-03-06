/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_data.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/06 18:23:48 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/03/06 18:27:37 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_data(t_data *data, const char *file)
{
	char		*file_str;

	file_str = read_file(file);
	validate_file(file_str);
	parse_data(data, file_str);
	init_data(data, file_str);
}
