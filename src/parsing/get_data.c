/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_data.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/06 18:23:48 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/04/23 14:54:21 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_map(int c)
{
	if (c == '0' || c == '1')
		return (true);
	else if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
		return (true);
	else
		return (false);
}

static void	check_empty_lines_in_map(t_data *data, char *str)
{
	int		i;
	bool	map;
	bool	new_lines;

	map = false;
	new_lines = false;
	i = 0;
	while (str[i] != '\0')
	{
		if (is_map(str[i]) && map == false)
			map = true;
		else if (str[i] == '\n' && map)
			new_lines = true;
		else if (str[i] != '\0' && is_map(str[i]) && map && new_lines)
			error_free_data(data, "There are empty lines in map");
		i++;
	}
}

void	get_data(t_data *data, const char *file)
{
	char	*file_as_str;
	char	**file_as_arr;

	file_as_str = read_file(data, file);
	check_empty_lines_in_map(data, file_as_str);
	file_as_arr = ft_split(file_as_str, '\n');
	validate_file_and_init_data(data, file_as_arr);
	free(file_as_str);
	ft_free_arr(file_as_arr);
	validate_data(data);
}
