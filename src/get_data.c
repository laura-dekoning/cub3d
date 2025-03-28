/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_data.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/06 18:23:48 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/03/28 17:52:46 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_data(t_data *data, const char *file)
{
	char	*file_as_str;
	char	**file_as_arr;

	file_as_str = read_file(data, file);
	file_as_arr = ft_split(file_as_str, '\n');
	validate_file_and_init_data(data, file_as_arr);
	free(file_as_str);
	ft_free_arr(file_as_arr);
}
