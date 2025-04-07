/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   alloc_mem_for_data.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/13 14:11:04 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/04/07 17:43:54 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*alloc_mem_for_data(void)
{
	t_data	*data;

	data = (t_data *)safe_calloc(NULL, NULL, 1, sizeof(t_data));
	if (!data)
		error_free_data(data, MALLOC);
	data->floor = (int *)safe_calloc(NULL, data, 3, sizeof(int));
	if (!data->floor)
		error_free_data(data, MALLOC);
	data->ceiling = (int *)safe_calloc(NULL, data, 3, sizeof(int));
	if (!data->ceiling)
		error_free_data(data, MALLOC);
	data->map = (t_map *)safe_calloc(NULL, data, 1, sizeof(t_map));
	if (!data->map)
		error_free_data(data, MALLOC);
	data->player = (t_player *)safe_calloc(NULL, data, 1, sizeof(t_player));
	if (!data->player)
		error_free_data(data, MALLOC);
	data->check = (t_check *)safe_calloc(NULL, data, 1, sizeof(t_check));
	if (!data->check)
		error_free_data(data, MALLOC);
	return (data);
}
