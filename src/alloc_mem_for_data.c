/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   alloc_mem_for_data.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/13 14:11:04 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/03/13 20:10:20 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*alloc_mem_for_data(void)
{
	t_data		*data;

	data = (t_data *)safe_calloc(NULL, 1, sizeof(t_data));
	data->floor = (int *)safe_calloc(data, 3, sizeof(int));
	data->ceiling = (int *)safe_calloc(data, 3, sizeof(int));
	data->map = (t_map *)safe_calloc(data, 1, sizeof(t_map));
	data->map->map = (char **)safe_calloc(data, 1, sizeof(char *));
	data->player = (t_player *)safe_calloc(data, 1, sizeof(t_player));
	data->check = (t_check *)safe_calloc(data, 1, sizeof(t_check));
	print_data(data);
	return (data);
}
