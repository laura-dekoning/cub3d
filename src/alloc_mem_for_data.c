/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   alloc_mem_for_data.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/13 14:11:04 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/03/20 18:40:24 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*alloc_mem_for_data(void)
{
	t_data		*data;

	data = (t_data *)safe_calloc(NULL, 1, sizeof(t_data));
	data->map = (t_map *)safe_calloc(data, 1, sizeof(t_map));
	data->player = (t_player *)safe_calloc(data, 1, sizeof(t_player));
	data->check = (t_check *)safe_calloc(data, 1, sizeof(t_check));
	return (data);
}
