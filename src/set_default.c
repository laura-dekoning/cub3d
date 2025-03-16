/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_default.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/11 19:32:37 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/03/16 09:36:42 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_default(t_data *data)
{
	if (data->check->setting[NORTH] == false)
		data->north_texture = ft_strdup(DEFAULT_NORTH);
	if (data->check->setting[SOUTH] == false)
		data->south_texture = ft_strdup(DEFAULT_SOUTH);
	if (data->check->setting[EAST] == false)
		data->east_texture = ft_strdup(DEFAULT_EAST);
	if (data->check->setting[WEST] == false)
		data->west_texture = ft_strdup(DEFAULT_WEST);
	if (data->check->setting[FLOOR] == false)
		data->floor = string_to_rgb(data, DEFAULT_FLOOR, 0);
	if (data->check->setting[CEILING] == false)
		data->ceiling = string_to_rgb(data, DEFAULT_CEILING, 0);
	if (data->check->setting[MAP] == false)
	{
		data->map->map = ft_split(DEFAULT_MAP, '\n');
		data->player->x = 5;
		data->player->y = 2;
		data->player->dir = SOUTH;
	}
}
