/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_data.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/06 18:23:48 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/03/11 20:02:23 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_data(t_data *data, const char *file)
{
	char	*file_as_str;

	file_as_str = read_file(file);
	validate_file_and_init_data(data, file_as_str);
	// parse_data(data, file_as_str);
	// init_data(data, file_as_str);
}
