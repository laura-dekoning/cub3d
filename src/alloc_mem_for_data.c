/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   alloc_mem_for_data.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/13 14:11:04 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/03/28 13:20:17 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*alloc_mem_for_data(void)
{
	t_data		*data;

	data = (t_data *)safe_calloc(NULL, 1, sizeof(t_data));
	if (!data)
		error_message(data, MALLOC);
	data->map = (t_map *)safe_calloc(data, 1, sizeof(t_map));
	if (!data->map)
		error_message(data, MALLOC);
	data->player = (t_player *)safe_calloc(data, 1, sizeof(t_player));
	if (!data->player)
		error_message(data, MALLOC);
	data->check = (t_check *)safe_calloc(data, 1, sizeof(t_check));
	if (!data->check)
		error_message(data, MALLOC);
	return (data);
}
