/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_map_last.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/28 12:18:57 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/04/16 16:57:04 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_missing_settings(t_data *data)
{
	if (data->check->setting[NORTH] == false)
		ft_putstr_fd("North texture path is missing!\n", 2);
	if (data->check->setting[EAST] == false)
		ft_putstr_fd("East texture path is missing!\n", 2);
	if (data->check->setting[SOUTH] == false)
		ft_putstr_fd("South texture path is missing!\n", 2);
	if (data->check->setting[WEST] == false)
		ft_putstr_fd("West texture path is missing!\n", 2);
	if (data->check->setting[FLOOR] == false)
		ft_putstr_fd("Floor rgb is missing!\n", 2);
	if (data->check->setting[CEILING] == false)
		ft_putstr_fd("Ceiling rgb is missing!\n", 2);
}

bool	is_map_last(t_data *data)
{
	int	x;

	x = 0;
	while (x < 6)
	{
		if (data->check->setting[x] == false)
		{
			print_missing_settings(data);
			return (false);
		}
		x++;
	}
	return (true);
}
